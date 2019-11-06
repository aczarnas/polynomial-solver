#include "ListTest.h"
#include "PolynomialTest.h"

int main(int argc, char *argv[]){
    ListTest listTest;
    PolynomialTest polyTest;

    bool listTestResult = QTest::qExec(&listTest);
    bool polyTestResult = QTest::qExec(&polyTest);

    return listTestResult && polyTestResult;
}
