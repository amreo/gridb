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

		void opposite_data() {
			common_data();
		}
		void opposite() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			dir = dir.getDirectionOpposite();
			QVERIFY(dir.getCoefficientX() == -fixedCoeX);
			QVERIFY(dir.getCoefficientY() == -fixedCoeY);
		}

		void setDirection_data() {
			common_data();
		}
		void setDirection() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			Direction dir2;
			dir2.setDirection(dir);
			QVERIFY(dir2.getCoefficientX() == fixedCoeX);
			QVERIFY(dir2.getCoefficientY() == fixedCoeY);
		}

		void setDirection2_data() {
			common_data();
		}
		void setDirection2() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (-100, -100);
			dir.setDirection(coeX, coeY);

			QVERIFY(dir.getCoefficientX() == fixedCoeX);
			QVERIFY(dir.getCoefficientY() == fixedCoeY);
		}


		void setCoefficient_data() {
			common_data();
		}
		void setCoefficient() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (-100, -100);
			dir.setCoefficientX(coeX);
			dir.setCoefficientY(coeY);

			QVERIFY(dir.getCoefficientX() == fixedCoeX);
			QVERIFY(dir.getCoefficientY() == fixedCoeY);
		}

		void sum_data() {
			QTest::addColumn <int> ("dir1_x");
			QTest::addColumn <int> ("dir1_y");
			QTest::addColumn <int> ("dir2_x");
			QTest::addColumn <int> ("dir2_y");
			QTest::addColumn <int> ("dir3_x");
			QTest::addColumn <int> ("dir3_y");

			QTest::newRow("none+none") << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY()
									   << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY()
									   << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY();
			QTest::newRow("none+right up") << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY()
									   << Direction::UP_RIGHT.getCoefficientX() << Direction::UP_RIGHT.getCoefficientY()
									   << Direction::UP_RIGHT.getCoefficientX() << Direction::UP_RIGHT.getCoefficientY();
			QTest::newRow("none+left down") << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY()
									   << Direction::DOWN_LEFT.getCoefficientX() << Direction::DOWN_LEFT.getCoefficientY()
									   << Direction::DOWN_LEFT.getCoefficientX() << Direction::DOWN_LEFT.getCoefficientY();
			QTest::newRow("right up+left down") << Direction::UP_RIGHT.getCoefficientX() << Direction::UP_RIGHT.getCoefficientY()
									   << Direction::DOWN_LEFT.getCoefficientX() << Direction::DOWN_LEFT.getCoefficientY()
									   << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY();
			QTest::newRow("left up+right down") << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY()
									   << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY()
									   << Direction::NONE.getCoefficientX() << Direction::NONE.getCoefficientY();
			QTest::newRow("right up+right down") << Direction::UP_RIGHT.getCoefficientX() << Direction::UP_RIGHT.getCoefficientY()
									   << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY()
									   << Direction::RIGHT.getCoefficientX() << Direction::RIGHT.getCoefficientY();
			QTest::newRow("left up+left down") << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY()
									   << Direction::DOWN_LEFT.getCoefficientX() << Direction::DOWN_LEFT.getCoefficientY()
									   << Direction::LEFT.getCoefficientX() << Direction::LEFT.getCoefficientY();
			QTest::newRow("left up+right up") << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY()
									   << Direction::UP_RIGHT.getCoefficientX() << Direction::UP_RIGHT.getCoefficientY()
									   << Direction::UP.getCoefficientX() << Direction::UP.getCoefficientY();
			QTest::newRow("left down+right down") << Direction::DOWN_LEFT.getCoefficientX() << Direction::DOWN_LEFT.getCoefficientY()
									   << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY()
									   << Direction::DOWN.getCoefficientX() << Direction::DOWN.getCoefficientY();

			QTest::newRow("left up+left up") << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY()
									   << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY()
									   << Direction::UP_LEFT.getCoefficientX() << Direction::UP_LEFT.getCoefficientY();
			QTest::newRow("right down+right down") << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY()
									   << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY()
									   << Direction::DOWN_RIGHT.getCoefficientX() << Direction::DOWN_RIGHT.getCoefficientY();
		}
		void sum() {
			QFETCH(int, dir1_x);
			QFETCH(int, dir1_y);
			QFETCH(int, dir2_x);
			QFETCH(int, dir2_y);
			QFETCH(int, dir3_x);
			QFETCH(int, dir3_y);

			Direction dir1(dir1_x, dir1_y);
			Direction dir2(dir2_x, dir2_y);
			Direction dir3 = Direction::sum(dir1,dir2);

			QVERIFY(dir3.getCoefficientX() == dir3_x);
			QVERIFY(dir3.getCoefficientY() == dir3_y);
		}

};


#endif // TESTDIRECTION_H
