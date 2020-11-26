#include <QtTest>
// add necessary includes here
#include "../Game/core/statistics.h"

class TestCase1 : public QObject
{
    Q_OBJECT

public:
    TestCase1();
    ~TestCase1();

private slots:
    void test_case1();
    void test_case2();
    void test_case3();

};

TestCase1::TestCase1()
{


}

TestCase1::~TestCase1()
{

}

void TestCase1::test_case1()
{
    QString str = "Hella";
    QCOMPARE(str.toUpper(), QString("HELLO"));

}

void TestCase1::test_case2()
{
    QString str = "Hella";
    QCOMPARE(str.toUpper(), QString("HELLO"));

}

void TestCase1::test_case3()
{
    QString str = "Hella";
    QCOMPARE(str.toUpper(), QString("HELLO"));

}

QTEST_APPLESS_MAIN(TestCase1)

#include "tst_testcase1.moc"
