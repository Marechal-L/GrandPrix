#include "car.h"

Car::Car() :
    positionsX(),
    positionsY(),
    boostUsage(),
    velX(0),
    velY(0),
    nbMoves(0),
    nbFailures(0),
    boosts(0),
    position(0),
    debug(false)
{
    driver = new QProcess;
}

Car::~Car()
{
    driver->disconnect(SIGNAL(readyReadStandardOutput()));
    driver->disconnect(SIGNAL(readyReadStandardError()));
    driver->close();
    driver->deleteLater();
}

void Car::reset(int x, int y, int boosts, int position, QColor color)
{
    this->positionsX.clear();
    this->positionsY.clear();
    this->boostUsage.clear();
    this->positionsX.append(x);
    this->positionsY.append(y);
    this->velX = 0;
    this->velY = 0;
    this->boosts = boosts;
    this->nbMoves = 0;
    this->nbFailures = 0;
    this->position = position;
    this->color = color;
    this->carburant = 0;
}

void Car::remplirReservoir(int valeur)
{
	this->carburant = valeur;	
}

