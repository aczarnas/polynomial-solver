#ifndef LISTTEST_H
#define LISTTEST_H

#include <QObject>
#include <QTest>

class ListTest : public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = nullptr);

signals:

private slots:
    void cleanup();
    void IntList_CreateEmptyList_HeadNullptrSizeZero();
    void IntList_CreateListWithHead_HeadNotNullptrSizeOneNextNullptr();

public slots:
};

#endif // LISTTEST_H
