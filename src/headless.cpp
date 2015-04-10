#include <iostream>

#include "headless.h"

Headless::Headless(int& argc, char** argv, bool* loaded) :
    QCoreApplication(argc, argv)
{
    *loaded = false;
    control.setDelay(0);

    if (!control.setMap(argv[1])) {
        qCritical("Map failed to load.");
        return;
    }
    control.setDriverPath(0, argv[2]);
    control.setDriverPath(1, argv[3]);
    control.setDriverPath(2, argv[4]);

    QObject::connect(&control, SIGNAL(end(QString)), this, SLOT(on_end(QString)));

    control.nextMove();
    *loaded = true;
}

void Headless::on_end(QString)
{
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (control.getPosDepart(j) == i) {
                std::cout << control.getDriverName(j).toStdString() << ' ' << control.getNbMoves(j) << std::endl;
            }
        }
    }
    ::exit(0);
}

