#include "ListTest.h"
#include "List.h"

ListTest::ListTest(QObject *parent) : QObject(parent)
{

}

void ListTest::cleanup()
{

}



void ListTest::IntList_CreateEmptyList_HeadNullptrSizeZero()
{
    List<int>* testedList = new List<int>();
    QVERIFY(testedList->getHead() == nullptr);
    QVERIFY(testedList->getSize() == 0);
}

void ListTest::IntList_CreateListWithHead_HeadNotNullptrSizeOneNextNullptr()
{
    Node<int>* node = new Node<int>(5, nullptr);
    List<int>* testedList = new List<int>(node);
    QVERIFY(testedList->getHead() == node);
    QVERIFY(testedList->getSize() == 1);
    QVERIFY(testedList->getHead()->getNext() == nullptr);
}

