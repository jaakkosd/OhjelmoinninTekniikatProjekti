#include <QtTest/QtTest>
#include "Game/core/statistics.h"
class TestCase1 : public QObject
{
    Q_OBJECT

public:
    TestCase1();
    ~TestCase1();

private slots:
    void test_points();
    void test_nysses();
    void test_passangers();

};

TestCase1::TestCase1()
{


}

TestCase1::~TestCase1()
{

}

void TestCase1::test_points()
{
    Game::Statistics stats;
    stats.addPoints(100);
    stats.addPoints(100);
    QCOMPARE(stats.Points(), 200);
    QVERIFY(stats.hiScore()>=0);
}

void TestCase1::test_nysses()
{
    Game::Statistics stats;
    for(int i = 0 ; i<100;i++){
        stats.newNysse();
    }
    stats.nysseRemoved();
    stats.nysseLeft();
    QCOMPARE(stats.nysses(),98);

}

void TestCase1::test_passangers()
{
    Game::Statistics stats;
    for(int i = 0 ; i<100;i++){
        stats.morePassengers(10);
    }

    QCOMPARE(stats.passangers(),1000);

}

QTEST_APPLESS_MAIN(TestCase1)

#include "tst_testcase1.moc"
