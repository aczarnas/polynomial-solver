#ifndef POLYNOMIALTEST_H
#define POLYNOMIALTEST_H

#include <QObject>

class PolynomialTest : public QObject
{
    Q_OBJECT
public:
    explicit PolynomialTest(QObject *parent = nullptr);

signals:

public slots:
    void cleanup();
};

#endif // POLYNOMIALTEST_H
