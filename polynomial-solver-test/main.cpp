#include "listtest.h"

int main(int argc, char *argv[]){
    ListTest listTest;
    return QTest::qExec(&listTest);
}
