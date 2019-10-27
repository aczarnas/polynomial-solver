#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <QObject>

class Polynomial : public QObject
{
    Q_OBJECT
public:
    explicit Polynomial(QObject *parent = nullptr);

signals:

public slots:
};

#endif // POLYNOMIAL_H
