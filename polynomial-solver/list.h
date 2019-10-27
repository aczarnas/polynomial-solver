#ifndef LIST_H
#define LIST_H

#include <QObject>

class List : public QObject
{
    Q_OBJECT
public:
    explicit List(QObject *parent = nullptr);

signals:

public slots:
};

#endif // LIST_H
