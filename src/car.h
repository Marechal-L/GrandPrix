#ifndef VOITURE_H
#define VOITURE_H

#include <QProcess>
#include <QColor>

class Car
{
public:
    QString name;
    QList<int> positionsX;
    QList<int> positionsY;
    QList<int> boostUsage;
    int velX;
    int velY;
    int nbMoves;
    int nbFailures;
    int boosts;
    int position;
    QColor color;
    // Pour la gestion du carburant
    int carburant;
    bool debug;
    // pointeur à cause de QtVector
    QProcess* driver;


    Car();
    ~Car();

    void reset(int x, int y, int boosts, int position, QColor color);
    void remplirReservoir(int valeur);
};


#endif
