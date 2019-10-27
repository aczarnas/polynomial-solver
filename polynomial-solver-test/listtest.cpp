#include "listtest.h"
#include <list.h>

ListTest::ListTest(QObject *parent) : QObject(parent)
{

}

void ListTest::cleanup()
{

}



void ListTest::IntList_CreateEmptyList_HeadNullptrSizeZero()
{
    List<int>* testedList = new List<int>();
    QVERIFY(testedList->head() == nullptr);
    QVERIFY(testedList->size() == 0);
}

