#ifndef TESTDIRECTION_H
#define TESTDIRECTION_H

#include "autotest.h"
#include <QTest>
#include "direction.h"
#include <QDebug>

Q_DECLARE_METATYPE(Direction)

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
			QCOMPARE(dir.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir.getCoefficientY(), fixedCoeY);
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
			QCOMPARE(dir2.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir2.getCoefficientY(), fixedCoeY);
			QCOMPARE(dir3.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir3.getCoefficientY(), fixedCoeY);
		}

		void staticDirection() {
			QCOMPARE(Direction::UP.getCoefficientX(), 0);
			QCOMPARE(Direction::UP.getCoefficientY(), -1);
			QCOMPARE(Direction::UP_RIGHT.getCoefficientX(), 1);
			QCOMPARE(Direction::UP_RIGHT.getCoefficientY(), -1);
			QCOMPARE(Direction::RIGHT.getCoefficientX(), 1);
			QCOMPARE(Direction::RIGHT.getCoefficientY(), 0);
			QCOMPARE(Direction::DOWN_RIGHT.getCoefficientX(), 1);
			QCOMPARE(Direction::DOWN_RIGHT.getCoefficientY(), 1);
			QCOMPARE(Direction::DOWN.getCoefficientX(), 0);
			QCOMPARE(Direction::DOWN.getCoefficientY(), 1);
			QCOMPARE(Direction::DOWN_LEFT.getCoefficientX(), -1);
			QCOMPARE(Direction::DOWN_LEFT.getCoefficientY(), 1);
			QCOMPARE(Direction::LEFT.getCoefficientX(), -1);
			QCOMPARE(Direction::LEFT.getCoefficientY(), 0);
			QCOMPARE(Direction::UP_LEFT.getCoefficientX(), -1);
			QCOMPARE(Direction::UP_LEFT.getCoefficientY(), -1);
			QCOMPARE(Direction::NONE.getCoefficientX(), 0);
			QCOMPARE(Direction::NONE.getCoefficientY(), 0);
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
			QCOMPARE(dir.getCoefficientX(), -fixedCoeX);
			QCOMPARE(dir.getCoefficientY(), -fixedCoeY);
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
			Direction dir3;
			dir2.setDirection(dir);
			dir3.setDirection(coeX, coeY);
			QCOMPARE(dir2.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir2.getCoefficientY(), fixedCoeY);
			QCOMPARE(dir3.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir3.getCoefficientY(), fixedCoeY);
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

			QCOMPARE(dir.getCoefficientX(), fixedCoeX);
			QCOMPARE(dir.getCoefficientY(), fixedCoeY);
		}

		void sum_data() {
			QTest::addColumn <Direction> ("dir1");
			QTest::addColumn <Direction> ("dir2");
			QTest::addColumn <Direction> ("dir3");

			QTest::newRow("none+none") << Direction::NONE << Direction::NONE << Direction::NONE;
			QTest::newRow("none+right up") << Direction::NONE << Direction::UP_RIGHT << Direction::UP_RIGHT;
			QTest::newRow("none+left down") << Direction::NONE<< Direction::DOWN_LEFT << Direction::DOWN_LEFT;
			QTest::newRow("right up+left down") << Direction::UP_RIGHT << Direction::DOWN_LEFT << Direction::NONE;
			QTest::newRow("left up+right down") << Direction::UP_LEFT << Direction::DOWN_RIGHT << Direction::NONE;
			QTest::newRow("right up+right down") << Direction::UP_RIGHT << Direction::DOWN_RIGHT << Direction::RIGHT;
			QTest::newRow("left up+left down") << Direction::UP_LEFT << Direction::DOWN_LEFT << Direction::LEFT;
			QTest::newRow("left up+right up") << Direction::UP_LEFT << Direction::UP_RIGHT << Direction::UP;
			QTest::newRow("left down+right down") << Direction::DOWN_LEFT << Direction::DOWN_RIGHT << Direction::DOWN;
			QTest::newRow("left up+left up") << Direction::UP_LEFT << Direction::UP_LEFT << Direction::UP_LEFT;
			QTest::newRow("right down+right down") << Direction::DOWN_RIGHT << Direction::DOWN_RIGHT << Direction::DOWN_RIGHT;
		}
		void sum() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(Direction, dir3);

			Direction dir6 = Direction::sum(dir1,dir2);
			Direction dir4 = Direction::sum(dir1.getCoefficientX(),dir1.getCoefficientY(), dir2.getCoefficientX(), dir2.getCoefficientY());
			Direction dir5 = dir1 + dir2;

			QCOMPARE(dir4.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir4.getCoefficientY(), dir3.getCoefficientY());
			QCOMPARE(dir5.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir5.getCoefficientY(), dir3.getCoefficientY());
			QCOMPARE(dir6.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir6.getCoefficientY(), dir3.getCoefficientY());
		}

		void sub_data() {
			QTest::addColumn <Direction> ("dir1");
			QTest::addColumn <Direction> ("dir2");
			QTest::addColumn <Direction> ("dir3");

			QTest::newRow("none-none") << Direction::NONE << Direction::NONE << Direction::NONE;
			QTest::newRow("none-right up") << Direction::NONE << Direction::UP_RIGHT << Direction::DOWN_LEFT;
			QTest::newRow("none-left down") << Direction::NONE << Direction::DOWN_LEFT << Direction::UP_RIGHT;
			QTest::newRow("right up-left down") << Direction::UP_RIGHT << Direction::DOWN_LEFT << Direction::UP_RIGHT;
			QTest::newRow("left up-right down") << Direction::UP_LEFT << Direction::DOWN_RIGHT << Direction::UP_LEFT;
			QTest::newRow("right up-right down") << Direction::UP_RIGHT << Direction::DOWN_RIGHT << Direction::UP;
			QTest::newRow("left up-left down") << Direction::UP_LEFT << Direction::DOWN_LEFT << Direction::UP;
			QTest::newRow("left up-right up") << Direction::UP_LEFT << Direction::UP_RIGHT << Direction::LEFT;
			QTest::newRow("left down-right down") << Direction::DOWN_LEFT << Direction::DOWN_RIGHT << Direction::LEFT;
			QTest::newRow("left up-left up") << Direction::UP_LEFT << Direction::UP_LEFT << Direction::NONE;
			QTest::newRow("right down-right down") << Direction::DOWN_RIGHT << Direction::DOWN_RIGHT << Direction::NONE;
		}
		void sub() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(Direction, dir3);

			Direction dir6 = Direction::sub(dir1,dir2);
			Direction dir4 = Direction::sub(dir1.getCoefficientX(),dir1.getCoefficientY(), dir2.getCoefficientX(), dir2.getCoefficientY());
			Direction dir5 = dir1 - dir2;

			QCOMPARE(dir4.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir4.getCoefficientY(), dir3.getCoefficientY());
			QCOMPARE(dir5.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir5.getCoefficientY(), dir3.getCoefficientY());
			QCOMPARE(dir6.getCoefficientX(), dir3.getCoefficientX());
			QCOMPARE(dir6.getCoefficientY(), dir3.getCoefficientY());
		}

		void equal_data() {
			QTest::addColumn <Direction> ("dir1");
			QTest::addColumn <Direction> ("dir2");
			QTest::addColumn <bool> ("result");

			QTest::newRow("none == none") << Direction::NONE << Direction::NONE << true;
			QTest::newRow("left up == none") << Direction::UP_LEFT << Direction::NONE << false;
			QTest::newRow("none == left up") << Direction::NONE << Direction::UP_LEFT << false;
			QTest::newRow("left up == left up") << Direction::UP_LEFT << Direction::UP_LEFT << true;
			QTest::newRow("right down == left up") << Direction::DOWN_RIGHT << Direction::UP_LEFT << false;
		}
		void equal() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(bool, result);

			QCOMPARE(Direction::equal(dir1, dir2), result);
			QCOMPARE(dir1 == dir2, result);
			QCOMPARE(dir1 != dir2, !result);
		}

		void rotate_data() {
			QTest::addColumn <Direction> ("dir");
			QTest::addColumn <int> ("times");
			QTest::addColumn <Direction> ("result");
			QTest::newRow("none --> none") << Direction::NONE << 0 << Direction::NONE;
			QTest::newRow("none --> none") << Direction::NONE << 10 << Direction::NONE;
			QTest::newRow("up --> left") << Direction::UP << -2 << Direction::LEFT;
			QTest::newRow("up --> right") << Direction::UP << 2 << Direction::RIGHT;
			QTest::newRow("up --> down") << Direction::UP << 4 << Direction::DOWN;
			QTest::newRow("up --> down-right") << Direction::UP << 3 << Direction::DOWN_RIGHT;
			QTest::newRow("up --> down-left") << Direction::UP << 5 << Direction::DOWN_LEFT;
			QTest::newRow("up --> down-right") << Direction::UP << -5 << Direction::DOWN_RIGHT;
			QTest::newRow("up --> down-left") << Direction::UP << -3 << Direction::DOWN_LEFT;
			QTest::newRow("left --> left") << Direction::LEFT << 0 << Direction::LEFT;
			QTest::newRow("left --> right") << Direction::LEFT << 4 << Direction::RIGHT;
			QTest::newRow("left --> down") << Direction::LEFT << -2 << Direction::DOWN;
			QTest::newRow("left --> down-right") << Direction::LEFT << -3 << Direction::DOWN_RIGHT;
			QTest::newRow("left --> down-left") << Direction::LEFT << -1 << Direction::DOWN_LEFT;
			QTest::newRow("left --> down-right") << Direction::LEFT << 5 << Direction::DOWN_RIGHT;
			QTest::newRow("left --> down-left") << Direction::LEFT << 7 << Direction::DOWN_LEFT;
		}
		void rotate() {
			QFETCH(Direction, dir);
			QFETCH(int, times);
			QFETCH(Direction, result);

			Direction dir2 = dir.getDirectionRotated(times);

			QCOMPARE(dir2.getCoefficientX(), result.getCoefficientX());
			QCOMPARE(dir2.getCoefficientY(), result.getCoefficientY());
		}

		void angle_data() {
			QTest::addColumn <Direction> ("dir");
			QTest::addColumn <int> ("angle");
			QTest::addColumn <int> ("angle_inverse");

			QTest::newRow("angle-0") << Direction::UP << 0 << -8;
			QTest::newRow("angle-1") << Direction::UP_RIGHT << 1 << -7;
			QTest::newRow("angle-2") << Direction::RIGHT << 2 << -6;
			QTest::newRow("angle-3") << Direction::DOWN_RIGHT << 3 << -5;
			QTest::newRow("angle-4") << Direction::DOWN << 4 << -4;
			QTest::newRow("angle-5") << Direction::DOWN_LEFT << 5 << -3;
			QTest::newRow("angle-6") << Direction::LEFT << 6 << -2;
			QTest::newRow("angle-7") << Direction::UP_LEFT << 7 << -1;
		}
		void angle() {
			QFETCH(Direction, dir);
			QFETCH(int, angle);
			QFETCH(int, angle_inverse);
			Direction dir2;
			dir2.setDirection(angle);
			Direction dir3;
			dir3.setDirection(angle_inverse);

			QCOMPARE(dir.getDirectionAngle(), angle);
			QCOMPARE(dir2.getCoefficientX(), dir.getCoefficientX());
			QCOMPARE(dir2.getCoefficientY(), dir.getCoefficientY());
			QCOMPARE(dir3.getCoefficientX(), dir.getCoefficientX());
			QCOMPARE(dir3.getCoefficientY(), dir.getCoefficientY());
		}
};


#endif // TESTDIRECTION_H
