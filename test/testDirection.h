#ifndef TESTDIRECTION_H
#define TESTDIRECTION_H

#include "autotest.h"
#include <QTest>
#include "direction.h"
#include <QDebug>

/**
 * @author amreo
 * @brief The TestDirection class
 * @version 1.0
 * @since 1.0
 */
class TestDirection : public QObject
{
		Q_OBJECT

	private slots:

		void common_data() {
			QTest::addColumn<int>("coeX");
			QTest::addColumn<int>("coeY");
			QTest::addColumn<int>("fixedCoeX");
			QTest::addColumn<int>("fixedCoeY");

			QTest::newRow("coe -1 -1") << -1 << -1 << -1 << -1;
			QTest::newRow("coe  0 -1") <<  0 << -1 <<  0 << -1;
			QTest::newRow("coe  1 -1") <<  1 << -1 <<  1 << -1;
			QTest::newRow("coe -1  0") << -1 <<  0 << -1 <<  0;
			QTest::newRow("coe  0  0") <<  0 <<  0 <<  0 <<  0;
			QTest::newRow("coe  1  0") <<  1 <<  0 <<  1 <<  0;
			QTest::newRow("coe -1  1") << -1 <<  1 << -1 <<  1;
			QTest::newRow("coe  0  1") <<  0 <<  1 <<  0 <<  1;
			QTest::newRow("coe  1  1") <<  1 <<  1 <<  1 <<  1;

			QTest::newRow("coe -2 -2") << -2 << -2 << -1 << -1;
			QTest::newRow("coe  0 -2") <<  0 << -2 <<  0 << -1;
			QTest::newRow("coe  2 -2") <<  2 << -2 <<  1 << -1;
			QTest::newRow("coe -2  0") << -2 <<  0 << -1 <<  0;
			QTest::newRow("coe  0  0") <<  0 <<  0 <<  0 <<  0;
			QTest::newRow("coe  2  0") <<  2 <<  0 <<  1 <<  0;
			QTest::newRow("coe -2  2") << -2 <<  2 << -1 <<  1;
			QTest::newRow("coe  0  2") <<  0 <<  2 <<  0 <<  1;
			QTest::newRow("coe  2  2") <<  2 <<  2 <<  1 <<  1;
		}

		void costructor1_data() {
			common_data();
		}

		void costructor1() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			QVERIFY(dir.getCoefficientX() == fixedCoeX);
			QVERIFY(dir.getCoefficientY() == fixedCoeY);
		}

		void costructor2_data() {
			common_data();
		}
		void costructor2() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			Direction dir2 = dir;
			Direction dir3(dir);
			QVERIFY(dir2.getCoefficientX() == fixedCoeX);
			QVERIFY(dir2.getCoefficientY() == fixedCoeY);
			QVERIFY(dir3.getCoefficientX() == fixedCoeX);
			QVERIFY(dir3.getCoefficientY() == fixedCoeY);
		}

		void staticDirection() {
			QVERIFY(Direction::UP.getCoefficientX() == 0);
			QVERIFY(Direction::UP.getCoefficientY() == -1);
			QVERIFY(Direction::UP_RIGHT.getCoefficientX() == 1);
			QVERIFY(Direction::UP_RIGHT.getCoefficientY() == -1);
			QVERIFY(Direction::RIGHT.getCoefficientX() == 1);
			QVERIFY(Direction::RIGHT.getCoefficientY() == 0);
			QVERIFY(Direction::DOWN_RIGHT.getCoefficientX() == 1);
			QVERIFY(Direction::DOWN_RIGHT.getCoefficientY() == 1);
			QVERIFY(Direction::DOWN.getCoefficientX() == 0);
			QVERIFY(Direction::DOWN.getCoefficientY() == 1);
			QVERIFY(Direction::DOWN_LEFT.getCoefficientX() == -1);
			QVERIFY(Direction::DOWN_LEFT.getCoefficientY() == 1);
			QVERIFY(Direction::LEFT.getCoefficientX() == -1);
			QVERIFY(Direction::LEFT.getCoefficientY() == 0);
			QVERIFY(Direction::UP_LEFT.getCoefficientX() == -1);
			QVERIFY(Direction::UP_LEFT.getCoefficientY() == -1);
			QVERIFY(Direction::NONE.getCoefficientX() == 0);
			QVERIFY(Direction::NONE.getCoefficientY() == 0);
		}
};


#endif // TESTDIRECTION_H
