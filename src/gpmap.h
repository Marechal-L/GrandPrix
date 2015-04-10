#ifndef GPMAP_H
#define GPMAP_H

#include <QObject>
#include <QPair>

class GPMap : public QObject
{
    Q_OBJECT

public:
    explicit GPMap(QObject *parent, QString mapPath);
    ~GPMap();


signals:

public slots:

};

#endif // GPMAP_H
