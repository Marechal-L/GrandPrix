#include "gpcontrol.h"
#include <QtDebug>
#include <iostream>
#include <cmath> 

GPControl::GPControl(QObject *parent) :
    QObject(parent),
    tiles(QVector<GPControl::Tile>()),
    cars(QVector<Car>(3)),
    nextCarMode(RANDOM),
    nbCars(0),
    delay(1)
{
    timer.stop();
    QObject::connect(&timer, SIGNAL(timeout()),
                     this, SLOT(timeout()));

}

GPControl::~GPControl()
{
    timer.stop();
}


bool GPControl::setMap(const QString &mapPath)
{
    QFile file(mapPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QTextStream stream(&file);
    stream >> this->sizeX >> this->sizeY >> this->carburantAuDepart;

    tiles.clear();
    tiles.reserve(sizeX * sizeY);
    nbCars = 0;
    currentCarIndex = 0;
    /* Pour vérification de la bonne lecture du carburant de départ */
	/* std::cerr << "Carburant de départ : " << this->carburantAuDepart << std::endl; */

    int x = 0;
    int y = 0;
    while (!stream.atEnd()) {
        bool ignoreCh = false;

        char ch;
        stream >> ch;
        switch (ch) {
            case GPControl::START1_CHAR:
                cars[0].reset(x, y, nbrMaxBoost, 1, QColor(Qt::red));
                cars[0].remplirReservoir(this->carburantAuDepart);
                nbCars++;
                tiles.append(GPControl::NORMAL);
                break;
            case GPControl::START2_CHAR:
                cars[1].reset(x, y, nbrMaxBoost, 2, QColor(0, 200, 0, 255));
                cars[1].remplirReservoir(this->carburantAuDepart);
                nbCars++;
                tiles.append(GPControl::NORMAL);
                break;
            case GPControl::START3_CHAR:
                cars[2].reset(x, y, nbrMaxBoost, 3, QColor(Qt::blue));
                cars[2].remplirReservoir(this->carburantAuDepart);
                nbCars++;
                tiles.append(GPControl::NORMAL);
                break;
            case GPControl::NORMAL_CHAR:
                tiles.append(GPControl::NORMAL);
                break;
            case GPControl::OUT_CHAR:
                tiles.append(GPControl::OUT);
                break;
            case GPControl::SAND_CHAR:
                tiles.append(GPControl::SAND);
                break;
            case GPControl::GOAL_CHAR:
                tiles.append(GPControl::GOAL);
                break;
            default:
                ignoreCh = true;
        }
        //qWarning("%i", ignoreCh);
        if (!ignoreCh) {
            x++;
            if (x == this->sizeX) {
                y++;
                x = 0;
            }
        }
    }
    file.close();
    if (tiles.size() != sizeX * sizeY) {
        tiles.clear();
        return false;
    } else {
        return true;
    }
}


int GPControl::getSizeX()
{
    return sizeX;
}
int GPControl::getSizeY()
{
    return sizeY;
}

GPControl::Tile GPControl::getTile(int x, int y)
{
    if (x >= 0 && x < sizeX && y >= 0 && y < sizeY) {
        return tiles.at(x + y * sizeX);
    } else {
        return GPControl::OUT;
    }
}

char GPControl::getTileChar(int x, int y)
{
    if (x >= 0 && x < sizeX && y >= 0 && y < sizeY) {
        switch (tiles.at(x + y * sizeX)) {
            case GPControl::OUT:
                return GPControl::OUT_CHAR;
            case GPControl::NORMAL:
                return GPControl::NORMAL_CHAR;
            case GPControl::SAND:
                return GPControl::SAND_CHAR;
            case GPControl::GOAL:
                return GPControl::GOAL_CHAR;
            default:
                return GPControl::OUT_CHAR;
        }
    } else {
        return GPControl::OUT_CHAR;
    }
}

int GPControl::getNbCars()
{
    return nbCars;
}
int GPControl::getPosCarX(int noCar)
{
    return cars[noCar].positionsX.last();
}
int GPControl::getPosCarY(int noCar)
{
    return cars[noCar].positionsY.last();
}
int GPControl::getVelCarX(int noCar)
{
    return cars[noCar].velX;
}
int GPControl::getVelCarY(int noCar)
{
    return cars[noCar].velY;
}

int GPControl::getCarburant(int noCar)
{
    return cars[noCar].carburant;
}


int GPControl::getOldPosCarX(int noCar, int numPos)
{
    return cars[noCar].positionsX.at(numPos);
}
int GPControl::getOldPosCarY(int noCar, int numPos)
{
    return cars[noCar].positionsY.at(numPos);
}
int GPControl::getBoost(int noCar)
{
    return cars[noCar].boosts;
}
int GPControl::getNbBoostUsed(int noCar)
{
    return cars[noCar].boostUsage.size();
}
int GPControl::getIndexBoostUsed(int noCar, int numBoost)
{
    return cars[noCar].boostUsage.at(numBoost);
}
int GPControl::getNbMoves(int noCar)
{
    return cars[noCar].nbMoves;
}
int GPControl::getNbFailures(int noCar)
{
    return cars[noCar].nbFailures;
}
int GPControl::getNbPositions(int noCar)
{
    return cars[noCar].positionsX.size();
}
int GPControl::getPosDepart(int noCar)
{
    return cars[noCar].position;
}
QColor GPControl::getColor(int noCar)
{
    return cars[noCar].color;
}
int GPControl::getCurrentCar()
{
    return currentCarIndex;
}
void GPControl::setCarDebug(int car, bool debug)
{
    cars[car].debug = debug;
}
bool GPControl::getCarDebug(int car)
{
    return cars[car].debug;
}
QString GPControl::getDriverName(int car)
{
    return cars[car].name;
}

void GPControl::setDriverPath(int noCar, const QString &driverPath)
{
    //drivers[noCar].setReadChannel(QProcess::StandardOutput|QProcess::StandardError);
    //qWarning() << "Starting driver : " <<driverPath;
    cars[noCar].name = driverPath.split("/").last();
    QProcess* driver = cars[noCar].driver;
    driver->start(driverPath, QIODevice::Unbuffered | QIODevice::Text | QIODevice::ReadWrite);
    QObject::connect(driver, SIGNAL(readyReadStandardError()), this, SLOT(readyReadStandardError()));
    driver->waitForStarted();
    driver->write(mapData());
    //qWarning() <<mapData();
}

void GPControl::setDelay(int value)
{
    delay = value;
}


QByteArray GPControl::mapData()
{	/* indique également le carburant de départ en plus de la taille de la carte */
    QByteArray res;
    res.append(QString("%1 %2 %3\n").arg(sizeX).arg(sizeY).arg(carburantAuDepart));
    for (int y = 0; y < sizeY; y++) {
        for (int x = 0; x < sizeX; x++) {
            res.append(getTileChar(x, y));
        }
        res.append("\n");
    }

    return res;
}

QByteArray GPControl::positionsData()
{
    QByteArray res;
    for (int i = 0; i < nbCars; i++) {
        Car& car = cars[(currentCarIndex + i) % nbCars];
        res.append(QString("%1 %2").arg(car.positionsX.last()).arg(car.positionsY.last()));
        if (i != nbCars - 1) {
            res.append("\t");
        }
    }
    res.append("\n");
    return res;
}


void GPControl::nextMove()
{
    //qWarning("nextMove current=%i",currentCar);
    //qWarning() << "ignore data : " << drivers[currentCar].readAllStandardOutput();
    Car& car = cars[currentCarIndex];
    QObject::connect(car.driver, SIGNAL(readyReadStandardOutput()), this, SLOT(readyReadStandardOutput()));
    car.driver->write(positionsData());
    //qWarning() << positionsData();
    car.nbMoves++;

    timer.start(2000);
}

/* Calcul de la variation de carburant en fonction de l'accéleration et de la vitesse */
int GPControl::deltaCarburantAcceleration(int accX, int accY, int velX, int velY)
{
	int valeur = accX*accX + accY*accY;
	valeur += (int)(sqrt(velX*velX+velY*velY)*3.0/2.0);
	return -valeur;
}

void GPControl::moveCurrentCar(int accX, int accY)
{
    Car& car = cars[currentCarIndex];
    /* Attention, il y a consommation même si le mouvement n'est pas autorisé */
    int deltaCarburant = deltaCarburantAcceleration(accX, accY, car.velX, car.velY);
	/* car.carburant += deltaCarburant ; // Erreur à supprimer */
	if (getTile(car.positionsX.last(), car.positionsY.last()) == GPControl::SAND){
		deltaCarburant -= 1;
	}
	car.carburant += deltaCarburant ;
	/* Pour la vérification de la bonne consomation du carburant */
	/* std::cerr << "Voiture : " << currentCarIndex << ", carburant :  " << car.carburant << " (" << deltaCarburant << ") " << std::endl; */	

        
    if (availableMoves(currentCarIndex).contains(QPair<int, int>(accX, accY)) && (car.carburant >0)) {
    	
        car.positionsX.append(car.positionsX.last()); 
        car.positionsY.append(car.positionsY.last());
    	car.velX += accX;
        car.velY += accY;
        car.positionsX.last() += car.velX;
        car.positionsY.last() += car.velY;
        if (abs(accX) == 2 || abs(accY) == 2) {
            car.boosts--;
            car.boostUsage.append(car.positionsX.size() - 2);
            emit carMovedWithBoost();
        } else {
            emit carMoved();
        }
    } else {
        //qWarning() << "Invalid move !" << availableMoves(currentCar);
        car.velX = 0;
        car.velY = 0;
        if (car.carburant>0) car.nbFailures++;
        emit invalidMove();
    }

}

QSet< QPair<int, int> > GPControl::availableMoves(int noCar)
{
    QSet< QPair<int, int> > res = QSet< QPair<int, int> >();

    Car& car = cars[noCar];
    int posX = car.positionsX.last();
    int posY = car.positionsY.last();
    int velX = car.velX;
    int velY = car.velY;

    int maxAcc = 1;

    if (car.boosts > 0) {
        maxAcc = 2;
    }


    for (int accX = -maxAcc; accX <= maxAcc; accX++) {
        for (int accY = -maxAcc; accY <= maxAcc; accY++) {
            if (getTile(posX, posY) == GPControl::NORMAL) {
                if (this->isFree(posX + velX + accX, posY + velY + accY) && abs(velX + accX)*abs(velX + accX) + abs(velY + accY)*abs(velY + accY) <= 25) {
                    res.insert(QPair<int, int>(accX, accY));
                }
            } else if (getTile(posX, posY) == GPControl::SAND) {
                if (this->isFree(posX + velX + accX, posY + velY + accY) && abs(velX + accX)*abs(velX + accX) + abs(velY + accY)*abs(velY + accY) <= 1) {
                    res.insert(QPair<int, int>(accX, accY));
                }
            }
        }
    }
    return res;
}

bool GPControl::isFree(int x, int y)
{
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY) {
        return false;
    }

    bool caseEstVide = true;
    // vérification des 2 autres cars
    for (int i = 1; i < nbCars; i++) {
        Car& car = cars[(currentCarIndex + i) % nbCars];
        if (car.positionsX.last() == x && car.positionsY.last() == y) {
            caseEstVide = false;
        }
    }

    return caseEstVide && this->getTile(x, y) != GPControl::OUT;
}

void GPControl::timeout()
{
    timer.stop();
    //qWarning() << "Driver " << currentCar << " timeout!";
    emit driverTimeout();
    Car& car = cars[currentCarIndex];
    car.driver->disconnect(SIGNAL(readyReadStandardOutput()));
    if (!isEnd()) {
        nextCar();
        QTimer::singleShot(delay * 500, this, SLOT(nextMove()));
    } else {
        emit end(results());
    }
}

void GPControl::setNextCarMode(NextCarMode mode)
{
    this->nextCarMode = mode;
}

void GPControl::nextCar()
{
    int x;
    int y;
    if (nextCarMode == RANDOM) {
        do {
            currentCarIndex = (currentCarIndex + (int)random() % 3) % nbCars;
            x = cars[currentCarIndex].positionsX.last();
            y = cars[currentCarIndex].positionsY.last();
        } while (getTile(x, y) == GPControl::GOAL);

    } else if (nextCarMode == DETERMINIST) {
        do {
            currentCarIndex = (currentCarIndex + 1) % nbCars;
            x = cars[currentCarIndex].positionsX.last();
            y = cars[currentCarIndex].positionsY.last();
        } while (getTile(x, y) == GPControl::GOAL);

    } else if (nextCarMode == SEQUENTIAL) {
        x = cars[currentCarIndex].positionsX.last();
        y = cars[currentCarIndex].positionsY.last();
        while (getTile(x, y) == GPControl::GOAL) {
            currentCarIndex = (currentCarIndex + 1) % nbCars;
            x = cars[currentCarIndex].positionsX.last();
            y = cars[currentCarIndex].positionsY.last();
        }
    }
}

void GPControl::readyReadStandardError()
{
    //qWarning() << "readyReadStandardError";
    for (int i = 0; i < nbCars; i++) {
        QByteArray data = cars[i].driver->readAllStandardError();
        if (!data.isEmpty() && cars[i].debug) {
            std::cout << data.data();
        }
    }
}

bool GPControl::isEnd()
{
    for (int noCar = 0; noCar < nbCars; noCar++) {
        int x = cars[noCar].positionsX.last();
        int y = cars[noCar].positionsY.last();
        if ((getTile(x, y) != GPControl::GOAL) && (cars[noCar].carburant>0)) {
            return false;
        }
    }
    return true;
}

void GPControl::readyReadStandardOutput()
{
    timer.stop();
    //qWarning() << "readyReadStandardOutput";
    Car& car = cars[currentCarIndex];
    car.driver->disconnect(SIGNAL(readyReadStandardOutput()));

    QByteArray ligne = car.driver->readAllStandardOutput();

    //qWarning() << "res:" << ligne;
    QList<QByteArray> list = ligne.trimmed().split(' ');

    int accX = 0;
    int accY = 0;
    bool syntax_error = false;

    if (list.size() >= 2) {
        bool ok;
        accX = list[0].toInt(&ok);
        if (ok) {
            accY = list[1].toInt(&ok);
            if (!ok) {
                //qWarning("accY not int");
                accX = 0;
                accY = 0;
                syntax_error = true;
            }
        } else {
            //qWarning("accX not int");
            accX = 0;
            accY = 0;
            syntax_error = true;
        }

    } else {
        //qWarning("syntax error");
        accX = 0;
        accY = 0;
        syntax_error = true;
    }
    if (syntax_error) {
        emit syntaxError();
    } else {
        moveCurrentCar(accX, accY);
    }

    if (!isEnd()) {
        nextCar();
        QTimer::singleShot(delay * 100, this, SLOT(nextMove()));
    } else {
        emit end(results());
    }
}

bool carMovesComparator(const Car& c1, const Car& c2)
{
    return c1.nbMoves < c2.nbMoves;
}

QString GPControl::results()
{
    QString res;
    qSort(cars.begin(), cars.end(), carMovesComparator);

    for (int i = 0; i < nbCars; i++) {
        res.append(tr("#%1\t %2 (%3) \t %4 coups - %5 carburant (%6 boosts)\n").arg(i + 1).arg(cars[i].position).arg(cars[i].name).arg(cars[i].nbMoves).arg(cars[i].carburant).arg(cars[i].boosts));
    }
    return res;
}

