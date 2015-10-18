#ifndef TESTS_H
#define TESTS_H

#include <QTest>
#include <QDebug>
#include "located.h"
#include "direction.h"
#include "movable.h"

Q_DECLARE_METATYPE(Direction)


/**
 * @author amreo
 * @brief The test class
 * @version 0.1
 * @since 0.1
 */
class Test : public QObject
{
		Q_OBJECT

	private slots:
		void testLocated_common_data() {
			QTest::addColumn<int>("x");
			QTest::addColumn<int>("y");
			QTest::newRow("x=0 y=0") << 0 << 0;
			QTest::newRow("x=1 y=0") << 1 << 0;
			QTest::newRow("x=0 y=1") << 0 << 1;
			QTest::newRow("x=1 y=1") << 1 << 1;
			QTest::newRow("x=-1 y=0") << -1 << 0;
			QTest::newRow("x=0 y=-1") << 0 << -1;
			QTest::newRow("x=-1 y=-1") << -1 << -1;
		}
		void testLocated_costructor1() {
			Located l;
			QCOMPARE(l.x(), 0);
			QCOMPARE(l.y(), 0);
		}
		void testLocated_costructor2_data() {
			testLocated_common_data();
		}
		void testLocated_costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			QCOMPARE(l.x(), x);
			QCOMPARE(l.y(), y);
		}
		void testLocated_costructor3_data() {
			testLocated_common_data();
		}
		void testLocated_costructor3() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			Located l2 = l;
			Located l3(l);
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
			QCOMPARE(l3.x(), x);
			QCOMPARE(l3.y(), y);
		}
		void testLocated_getLocation_data() {
			testLocated_common_data();
		}
		void testLocated_getLocation() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			Located l2 = l.getLocation();
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
		}


		void testDirection_common_data() {
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
		void testDirection_costructor1_data() {
			testDirection_common_data();
		}
		void testDirection_costructor1() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			QCOMPARE(dir.coefficientX(), fixedCoeX);
			QCOMPARE(dir.coefficientY(), fixedCoeY);
		}
		void testDirection_costructor2_data() {
			testDirection_common_data();
		}
		void testDirection_costructor2() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			Direction dir2 = dir;
			Direction dir3(dir);
			QCOMPARE(dir2.coefficientX(), fixedCoeX);
			QCOMPARE(dir2.coefficientY(), fixedCoeY);
			QCOMPARE(dir3.coefficientX(), fixedCoeX);
			QCOMPARE(dir3.coefficientY(), fixedCoeY);
		}
		void testDirection_staticDirection() {
			QCOMPARE(Direction::UP.coefficientX(), 0);
			QCOMPARE(Direction::UP.coefficientY(), -1);
			QCOMPARE(Direction::UP_RIGHT.coefficientX(), 1);
			QCOMPARE(Direction::UP_RIGHT.coefficientY(), -1);
			QCOMPARE(Direction::RIGHT.coefficientX(), 1);
			QCOMPARE(Direction::RIGHT.coefficientY(), 0);
			QCOMPARE(Direction::DOWN_RIGHT.coefficientX(), 1);
			QCOMPARE(Direction::DOWN_RIGHT.coefficientY(), 1);
			QCOMPARE(Direction::DOWN.coefficientX(), 0);
			QCOMPARE(Direction::DOWN.coefficientY(), 1);
			QCOMPARE(Direction::DOWN_LEFT.coefficientX(), -1);
			QCOMPARE(Direction::DOWN_LEFT.coefficientY(), 1);
			QCOMPARE(Direction::LEFT.coefficientX(), -1);
			QCOMPARE(Direction::LEFT.coefficientY(), 0);
			QCOMPARE(Direction::UP_LEFT.coefficientX(), -1);
			QCOMPARE(Direction::UP_LEFT.coefficientY(), -1);
			QCOMPARE(Direction::NONE.coefficientX(), 0);
			QCOMPARE(Direction::NONE.coefficientY(), 0);
		}
		void testDirection_opposite_data() {
			testDirection_common_data();
		}
		void testDirection_opposite() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			dir = dir.getDirectionOpposite();
			QCOMPARE(dir.coefficientX(), -fixedCoeX);
			QCOMPARE(dir.coefficientY(), -fixedCoeY);
		}
		void testDirection_setDirection_data() {
			testDirection_common_data();
		}
		void testDirection_setDirection() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (coeX, coeY);
			Direction dir2;
			Direction dir3;
			dir2.setDirection(dir);
			dir3.setDirection(coeX, coeY);
			QCOMPARE(dir2.coefficientX(), fixedCoeX);
			QCOMPARE(dir2.coefficientY(), fixedCoeY);
			QCOMPARE(dir3.coefficientX(), fixedCoeX);
			QCOMPARE(dir3.coefficientY(), fixedCoeY);
		}
		void testDirection_setCoefficient_data() {
			testDirection_common_data();
		}
		void testDirection_setCoefficient() {
			QFETCH(int, coeX);
			QFETCH(int, coeY);
			QFETCH(int, fixedCoeX);
			QFETCH(int, fixedCoeY);
			Direction dir (-100, -100);
			dir.setCoefficientX(coeX);
			dir.setCoefficientY(coeY);

			QCOMPARE(dir.coefficientX(), fixedCoeX);
			QCOMPARE(dir.coefficientY(), fixedCoeY);
		}
		void testDirection_sum_data() {
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
		void testDirection_sum() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(Direction, dir3);

			Direction dir6 = Direction::sum(dir1,dir2);
			Direction dir4 = Direction::sum(dir1.coefficientX(),dir1.coefficientY(), dir2.coefficientX(), dir2.coefficientY());
			Direction dir5 = dir1 + dir2;

			QCOMPARE(dir4.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir4.coefficientY(), dir3.coefficientY());
			QCOMPARE(dir5.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir5.coefficientY(), dir3.coefficientY());
			QCOMPARE(dir6.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir6.coefficientY(), dir3.coefficientY());
		}
		void testDirection_sub_data() {
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
		void testDirection_sub() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(Direction, dir3);

			Direction dir6 = Direction::sub(dir1,dir2);
			Direction dir4 = Direction::sub(dir1.coefficientX(),dir1.coefficientY(), dir2.coefficientX(), dir2.coefficientY());
			Direction dir5 = dir1 - dir2;

			QCOMPARE(dir4.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir4.coefficientY(), dir3.coefficientY());
			QCOMPARE(dir5.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir5.coefficientY(), dir3.coefficientY());
			QCOMPARE(dir6.coefficientX(), dir3.coefficientX());
			QCOMPARE(dir6.coefficientY(), dir3.coefficientY());
		}
		void testDirection_equal_data() {
			QTest::addColumn <Direction> ("dir1");
			QTest::addColumn <Direction> ("dir2");
			QTest::addColumn <bool> ("result");

			QTest::newRow("none == none") << Direction::NONE << Direction::NONE << true;
			QTest::newRow("left up == none") << Direction::UP_LEFT << Direction::NONE << false;
			QTest::newRow("none == left up") << Direction::NONE << Direction::UP_LEFT << false;
			QTest::newRow("left up == left up") << Direction::UP_LEFT << Direction::UP_LEFT << true;
			QTest::newRow("right down == left up") << Direction::DOWN_RIGHT << Direction::UP_LEFT << false;
		}
		void testDirection_equal() {
			QFETCH(Direction, dir1);
			QFETCH(Direction, dir2);
			QFETCH(bool, result);

			QCOMPARE(Direction::equal(dir1, dir2), result);
			QCOMPARE(dir1 == dir2, result);
			QCOMPARE(dir1 != dir2, !result);
		}
		void testDirection_rotate_data() {
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
		void testDirection_rotate() {
			QFETCH(Direction, dir);
			QFETCH(int, times);
			QFETCH(Direction, result);

			Direction dir2 = dir.getDirectionRotated(times);

			QCOMPARE(dir2.coefficientX(), result.coefficientX());
			QCOMPARE(dir2.coefficientY(), result.coefficientY());
		}
		void testDirection_angle_data() {
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
		void testDirection_angle() {
			QFETCH(Direction, dir);
			QFETCH(int, angle);
			QFETCH(int, angle_inverse);
			Direction dir2;
			dir2.setDirection(angle);
			Direction dir3;
			dir3.setDirection(angle_inverse);

			QCOMPARE(dir.getDirectionAngle(), angle);
			QCOMPARE(dir2.coefficientX(), dir.coefficientX());
			QCOMPARE(dir2.coefficientY(), dir.coefficientY());
			QCOMPARE(dir3.coefficientX(), dir.coefficientX());
			QCOMPARE(dir3.coefficientY(), dir.coefficientY());
		}

		void testMovable_common_data() {
			QTest::addColumn<int>("x");
			QTest::addColumn<int>("y");
			QTest::newRow("x=0 y=0") << 0 << 0;
			QTest::newRow("x=1 y=0") << 1 << 0;
			QTest::newRow("x=0 y=1") << 0 << 1;
			QTest::newRow("x=1 y=1") << 1 << 1;
			QTest::newRow("x=-1 y=0") << -1 << 0;
			QTest::newRow("x=0 y=-1") << 0 << -1;
			QTest::newRow("x=-1 y=-1") << -1 << -1;
		}
		void testMovable_costructor1() {
			Movable l;
			QCOMPARE(l.x(), 0);
			QCOMPARE(l.y(), 0);
		}
		void testMovable_costructor2_data() {
			testMovable_common_data();
		}
		void testMovable_costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l(x,y);
			QCOMPARE(l.x(), x);
			QCOMPARE(l.y(), y);
		}
		void testMovable_costructor3_data() {
			testMovable_common_data();
		}
		void testMovable_costructor3() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l(x,y);
			Movable l2 = l;
			Movable l3(l);
			Located l4(x,y);
			Movable l5 = l4;
			Movable l6(l4);
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
			QCOMPARE(l3.x(), x);
			QCOMPARE(l3.y(), y);
			QCOMPARE(l5.x(), x);
			QCOMPARE(l5.y(), y);
			QCOMPARE(l6.x(), x);
			QCOMPARE(l6.y(), y);

		}
		void testMovable_set_data() {
			testMovable_common_data();
		}
		void testMovable_set() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l1;
			Movable l2;
			Movable l3;
			Movable l1_receiver;
			Movable l2_receiver;
			Movable l3_receiver;
			connect(&l1, SIGNAL(locationChanged(const Located&)),
					&l1_receiver, SLOT(setMovable(const Located&)));
			connect(&l2, SIGNAL(locationChanged(const Located&)),
					&l2_receiver, SLOT(setMovable(const Located&)));
			connect(&l3, SIGNAL(locationChanged(const Located&)),
					&l3_receiver, SLOT(setMovable(const Located&)));
			l1.setX(x);
			l1.setY(y);
			l2.setMovable(x,y);
			l3.setMovable(l1);
			QCOMPARE(l1.x(), x);
			QCOMPARE(l1.y(), y);
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
			QCOMPARE(l3.x(), x);
			QCOMPARE(l3.y(), y);

			QCOMPARE(l1_receiver.x(), x);
			QCOMPARE(l1_receiver.y(), y);
			QCOMPARE(l2_receiver.x(), x);
			QCOMPARE(l2_receiver.y(), y);
			QCOMPARE(l3_receiver.x(), x);
			QCOMPARE(l3_receiver.y(), y);
		}


};

#endif // TESTS_H
