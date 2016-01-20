#ifndef TESTS_H
#define TESTS_H

#include <QTest>
#include <QDebug>
#include <QSignalSpy>
#include <QtMath>
#include "coord.h"
#include "direction.h"
#include "coordselecter.h"
#include "listcoordselecter.h"
#include "gridcoordselecter.h"
#include "abstractdistancefunction.h"
#include "manhattandistancefunction.h"
#include "euclideandistancefunction.h"
#include "diagonaldistancefunction.h"
#include "squaredeuclideandistancefunction.h"

Q_DECLARE_METATYPE(Direction)
Q_DECLARE_METATYPE(Coord)

/**
 * @author amreo
 * @brief The test class
 * @version 0.2
 * @since 0.1
 */
class Test : public QObject
{
		Q_OBJECT
	private:


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
            Coord l;
            QCOMPARE(l.x(), 0);
            QCOMPARE(l.y(), 0);
        }
        void testLocated_costructor2_data() {
            testLocated_common_data();
        }
        void testLocated_costructor2() {
            QFETCH(int, x);
            QFETCH(int, y);
            Coord l(x,y);
            QCOMPARE(l.x(), x);
            QCOMPARE(l.y(), y);
        }
        void testLocated_costructor3_data() {
            testLocated_common_data();
        }
        void testLocated_costructor3() {
            QFETCH(int, x);
            QFETCH(int, y);
            Coord l(x,y);
            Located l2 = l;
            Located l3(l);
            QCOMPARE(l2.x(), x);
            QCOMPARE(l2.y(), y);
            QCOMPARE(l3.x(), x);
            QCOMPARE(l3.y(), y);
        }
        void testLocated_equalLocation_data() {
            QTest::addColumn<int>("x1");
            QTest::addColumn<int>("y1");
            QTest::addColumn<int>("x2");
            QTest::addColumn<int>("y2");
            QTest::addColumn<bool>("result");

            QTest::newRow("0;0 0;0") << 0 << 0 << 0 << 0 << true;
            QTest::newRow("1;0 1;0") << 1 << 0 << 1 << 0 << true;
            QTest::newRow("0;1 0;1") << 0 << 1 << 0 << 1 << true;
            QTest::newRow("1;1 1;1") << 1 << 1 << 1 << 1 << true;
            QTest::newRow("-1:0 -1;0") << -1 << 0 << -1 << 0 << true;
            QTest::newRow("0;-1 0;-1") << 0 << -1 << 0 << -1 << true;
            QTest::newRow("-1;-1 -1;-1") << -1 << -1 << -1 << -1 << true;

            QTest::newRow("0;0 2;0") << 0 << 0 << 2 << 0 << false;
            QTest::newRow("1;0 1;2") << 1 << 0 << 1 << 2 << false;
            QTest::newRow("2;1 0;1") << 2 << 1 << 0 << 1 << false;
            QTest::newRow("1;2 1;1") << 1 << 2 << 1 << 1 << false;
            QTest::newRow("-3:0 -1;0") << -3 << 0 << -1 << 0 << false;
            QTest::newRow("0;-10 0;-1") << 0 << -10 << 0 << -1 << false;
            QTest::newRow("-1;6 -1;-1") << -1 << 6 << -1 << -1 << false;
        }
        void testLocated_equalLocation() {
            QFETCH(int, x1);
            QFETCH(int, y1);
            QFETCH(int, x2);
            QFETCH(int, y2);
            QFETCH(bool, result);

            QCOMPARE(Coord::isLocationEqual(Coord(x1,y1), Coord(x2, y2)), result);
            QCOMPARE(Coord(x1,y1) == Coord(x2, y2), result);
            QCOMPARE(Coord(x1,y1) != Coord(x2, y2), !result);
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
            Direction dir3 = dir>>times;


            QCOMPARE(dir2.coefficientX(), result.coefficientX());
            QCOMPARE(dir2.coefficientY(), result.coefficientY());
            QCOMPARE(dir3.coefficientX(), result.coefficientX());
            QCOMPARE(dir3.coefficientY(), result.coefficientY());
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
        void testMovable_set_data() {
            testMovable_common_data();
        }
        void testMovable_set() {
            QFETCH(int, x);
            QFETCH(int, y);
            Coord l1;
            Coord l2;
            Coord l3;
            QSignalSpy l1_receiver(&l1, SIGNAL(locationChanged(const AbstractLocated&)));
            QSignalSpy l2_receiver(&l2, SIGNAL(locationChanged(const AbstractLocated&)));
            QSignalSpy l3_receiver(&l3, SIGNAL(locationChanged(const AbstractLocated&)));

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

            QCOMPARE(l1_receiver.count(), 2);
            QCOMPARE(l2_receiver.count(), 1);
            QCOMPARE(l3_receiver.count(), 1);
        }
        void testMovable_move13_data() {
            QTest::addColumn<int>("fromX");
            QTest::addColumn<int>("fromY");
            QTest::addColumn<int>("offX");
            QTest::addColumn<int>("offY");
            QTest::addColumn<int>("toX");
            QTest::addColumn<int>("toY");

            QTest::newRow("0;0 + 1;1") << 0 << 0 << 1 << 1 << 1 << 1;
            QTest::newRow("0;0 + -1;-1") << 0 << 0 << -1 << -1 << -1 << -1;
            QTest::newRow("-1;-1 + -1;-1") << -1 << -1 << -1 << -1 << -2 << -2;
            QTest::newRow("-1;-1 + 1;1") << -1 << -1 << 1 << 1 << 0 << 0;
            QTest::newRow("1;1 + 1;1") << 1 << 1 << 1 << 1 << 2 << 2;
            QTest::newRow("1;1 + -1;-1") << 1 << 1 << -1 << -1 << 0 << 0;

            QTest::newRow("0;0 + 2;4") << 0 << 0 << 2 << 4 << 2 << 4;
            QTest::newRow("0;0 + -2;-4") << 0 << 0 << -2 << -4 << -2 << -4;
            QTest::newRow("-2;-4 + -2;-4") << -2 << -4 << -2 << -4 << -4 << -8;
            QTest::newRow("-2;-4 + 2;4") << -2 << -4 << 2 << 4 << 0 << 0;
            QTest::newRow("2;4 + 2;4") << 2 << 4 << 2 << 4 << 4 << 8;
            QTest::newRow("2;4 + -2;-4") << 2 << 4 << -2 << -4 << 0 << 0;
        }
        void testMovable_move13() {
            QFETCH(int, fromX);
            QFETCH(int, fromY);
            QFETCH(int, offX);
            QFETCH(int, offY);
            QFETCH(int, toX);
            QFETCH(int, toY);

            Coord mov(fromX, fromY);
            Coord mov2(fromX, fromY);
            Coord mov3(fromX, fromY);

            QSignalSpy mov_receiver(&mov, SIGNAL(locationChanged(const AbstractLocated&)));
            QSignalSpy mov2_receiver(&mov2, SIGNAL(locationChanged(const AbstractLocated&)));
            QSignalSpy mov3_receiver(&mov3, SIGNAL(locationChanged(const AbstractLocated&)));

            mov.move(offX, offY);
            mov2.move(Coord(offX, offY));
            mov3>>Coord(offX, offY);

            QCOMPARE(mov.x(), toX);
            QCOMPARE(mov.y(), toY);
            QCOMPARE(mov2.x(), toX);
            QCOMPARE(mov2.y(), toY);
            QCOMPARE(mov3.x(), toX);
            QCOMPARE(mov3.y(), toY);

            QCOMPARE(mov_receiver.count(), 1);
            QCOMPARE(mov2_receiver.count(), 1);
            QCOMPARE(mov3_receiver.count(), 1);
        }
        void testMovable_move2_data() {
            QTest::addColumn<int>("fromX");
            QTest::addColumn<int>("fromY");
            QTest::addColumn<Direction>("dir");
            QTest::addColumn<int>("off");
            QTest::addColumn<int>("toX");
            QTest::addColumn<int>("toY");

            QTest::newRow("0;0 UP 1") << 0 << 0 << Direction::UP << 1 << 0 << -1;
            QTest::newRow("0;0 DOWN_LEFT 1") << 0 << 0 << Direction::DOWN_LEFT << 1 << -1 << 1;
            QTest::newRow("2;-6 UP 10") << 2 << -6 << Direction::UP << 10 << 2 << -16;
            QTest::newRow("-4;7 DOWN_LEFT 8") << -4 << 7 << Direction::DOWN_LEFT << 8 << -4-8 << 7+8;
        }
        void testMovable_move2() {
            QFETCH(int, fromX);
            QFETCH(int, fromY);
            QFETCH(Direction, dir);
            QFETCH(int, off);
            QFETCH(int, toX);
            QFETCH(int, toY);

            Coord mov(fromX, fromY);

            QSignalSpy mov_receiver(&mov, SIGNAL(locationChanged(const AbstractLocated&)));

            mov.move(dir, off);

            QCOMPARE(mov.x(), toX);
            QCOMPARE(mov.y(), toY);

            QCOMPARE(mov_receiver.count(), 1);
        }
        void testMovable_negative_move_data() {
            QTest::addColumn<int>("fromX");
            QTest::addColumn<int>("fromY");
            QTest::addColumn<int>("offX");
            QTest::addColumn<int>("offY");
            QTest::addColumn<int>("toX");
            QTest::addColumn<int>("toY");

            QTest::newRow("0;0 - 1;1") << 0 << 0 << 1 << 1 << -1 << -1;
            QTest::newRow("0;0 - -1;-1") << 0 << 0 << -1 << -1 << 1 << 1;
            QTest::newRow("-1;-1 - -1;-1") << -1 << -1 << -1 << -1 << 0 << 0;
            QTest::newRow("-1;-1 - 1;1") << -1 << -1 << 1 << 1 << -2 << -2;
            QTest::newRow("1;1 - 1;1") << 1 << 1 << 1 << 1 << 0 << 0;
            QTest::newRow("1;1 - -1;-1") << 1 << 1 << -1 << -1 << 2 << 2;

            QTest::newRow("0;0 - 2;4") << 0 << 0 << 2 << 4 << -2 << -4;
            QTest::newRow("0;0 - -2;-4") << 0 << 0 << -2 << -4 << 2 << 4;
            QTest::newRow("-2;-4 - -2;-4") << -2 << -4 << -2 << -4 << 0 << 0;
            QTest::newRow("-2;-4 - 2;4") << -2 << -4 << 2 << 4 << -4 << -8;
            QTest::newRow("2;4 - 2;4") << 2 << 4 << 2 << 4 << 0 << 0;
            QTest::newRow("2;4 - -2;-4") << 2 << 4 << -2 << -4 << 4 << 8;
        }
        void testMovable_negative_move() {
            QFETCH(int, fromX);
            QFETCH(int, fromY);
            QFETCH(int, offX);
            QFETCH(int, offY);
            QFETCH(int, toX);
            QFETCH(int, toY);
            Coord mov(fromX, fromY);

            QSignalSpy mov_receiver(&mov, SIGNAL(locationChanged(const AbstractLocated&)));

            mov << Coord(offX, offY);

            QCOMPARE(mov.x(), toX);
            QCOMPARE(mov.y(), toY);

            QCOMPARE(mov_receiver.count(), 1);
        }

        void testCoord_sum_data() {
            testMovable_move13_data();
        }
        void testCoord_sum() {
            QFETCH(int, fromX);
            QFETCH(int, fromY);
            QFETCH(int, offX);
            QFETCH(int, offY);
            QFETCH(int, toX);
            QFETCH(int, toY);

            Coord src(fromX, fromY);
            Coord off(offX, offY);
            Coord dest1 = src+off;
            Coord dest2 = Coord::sum(src,off);

            QCOMPARE(dest1.x(), toX);
            QCOMPARE(dest1.y(), toY);
            QCOMPARE(dest2.x(), toX);
            QCOMPARE(dest2.y(), toY);
        }
        void testCoord_sub_data() {
            testMovable_negative_move_data();
        }
        void testCoord_sub() {
            QFETCH(int, fromX);
            QFETCH(int, fromY);
            QFETCH(int, offX);
            QFETCH(int, offY);
            QFETCH(int, toX);
            QFETCH(int, toY);

            Coord src(fromX, fromY);
            Coord off(+offX, +offY);
            Coord dest1 = src-off;
            Coord dest2 = Coord::sub(src,off);

            QCOMPARE(dest1.x(), toX);
            QCOMPARE(dest1.y(), toY);
            QCOMPARE(dest2.x(), toX);
            QCOMPARE(dest2.y(), toY);
        }
//		void testCoord_sum_with_direction_data() {
//			testMovable_move2_data();
//		}
//		void testCoord_sum_with_direction() {
//			QFETCH(int, fromX);
//			QFETCH(int, fromY);
//			QFETCH(Direction, dir);
//			QFETCH(int, off);
//			QFETCH(int, toX);
//			QFETCH(int, toY);

//			Coord src(fromX, fromY);
//			Coord dest = Coord::sum(src,dir,off);

//			QCOMPARE(dest.x(), toX);
//			QCOMPARE(dest.y(), toY);

//			if (off == 1) {
//				Coord dest2 = src+dir;

//				QCOMPARE(dest2.x(), toX);
//				QCOMPARE(dest2.y(), toY);
//			}
//		}


//		void testCoord_sub_with_direction_data() {
//			QTest::addColumn<int>("fromX");
//			QTest::addColumn<int>("fromY");
//			QTest::addColumn<Direction>("dir");
//			QTest::addColumn<int>("off");
//			QTest::addColumn<int>("toX");
//			QTest::addColumn<int>("toY");

//			QTest::newRow("0;0 UP 1") << 0 << 0 << Direction::UP << 1<< 0 << 1;
//			QTest::newRow("0;0 DOWN_LEFT 1") << 0 << 0 << Direction::DOWN_LEFT << 1<< +1 << -1;
//			QTest::newRow("4;8 UP 1") << 4 << 8 << Direction::UP << 1 << 4 << +9;
//			QTest::newRow("4;8 DOWN_LEFT 1") << 4 << 8 << Direction::DOWN_LEFT << 1<< 5 << 7;
//			QTest::newRow("0;0 UP 2") << 0 << 0 << Direction::UP << 2 << 0 << +2;
//			QTest::newRow("0;0 DOWN_LEFT 2") << 0 << 0 << Direction::DOWN_LEFT << 2 << +2 << -2;
//			QTest::newRow("4;8 UP 2") << 4 << 8 << Direction::UP << 2 << 4 << 10;
//			QTest::newRow("4;8 DOWN_LEFT 2") << 4 << 8 << Direction::DOWN_LEFT << 2<< 6 << 6;
//		}
//		void testCoord_sub_with_direction() {
//			QFETCH(int, fromX);
//			QFETCH(int, fromY);
//			QFETCH(Direction, dir);
//			QFETCH(int, off);
//			QFETCH(int, toX);
//			QFETCH(int, toY);

//			Coord src(fromX, fromY);
//			Coord dest = Coord::sub(src, dir, off);

//			QCOMPARE(dest.x(), toX);
//			QCOMPARE(dest.y(), toY);

//			if (off == 1) {
//				Coord dest2 = src-dir;

//				QCOMPARE(dest2.x(), toX);
//				QCOMPARE(dest2.y(), toY);
//			}
//		}


        void testCoordSelecter_test_data()  {
            QTest::addColumn<Coord>("loc");

            QTest::newRow("0 0") << Coord(0,0);
            QTest::newRow("1 1") << Coord(1,1);
            QTest::newRow("-1 1") << Coord(-1,1);
        }
        void testCoordSelecter_test1_data() {
            testCoordSelecter_test_data();
        }
        void testCoordSelecter_test1(CoordSelecter* sel)
        {
            QFETCH(Coord, loc);
            QCOMPARE(sel->isSelected(loc), false);
            sel->select(loc);
            QCOMPARE(sel->isSelected(loc), true);
            sel->deSelect(loc);
            QCOMPARE(sel->isSelected(loc), false);
        }
        void testCoordSelecter_test2_data() {
            testCoordSelecter_test_data();
        }
        void testCoordSelecter_test2(CoordSelecter* sel)
        {
            QFETCH(Coord, loc);
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), false);
            sel->select(loc.x(), loc.y());
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), true);
            sel->deSelect(loc.x(), loc.y());
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), false);
        }
        void testCoordSelecter_test3_data() {
            testCoordSelecter_test_data();
        }
        void testCoordSelecter_test3(CoordSelecter* sel)
        {
            QFETCH(Coord, loc);
            QCOMPARE(sel->isSelected(loc), false);
            sel->select(loc);
            sel->select(loc);
            QCOMPARE(sel->isSelected(loc), true);
            sel->deSelect(loc);
            QCOMPARE(sel->isSelected(loc), false);
            sel->deSelect(loc);
            QCOMPARE(sel->isSelected(loc), false);
        }
        void testCoordSelecter_test4_data() {
            testCoordSelecter_test_data();
        }
        void testCoordSelecter_test4(CoordSelecter* sel)
        {
            QFETCH(Coord, loc);
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), false);
            sel->select(loc.x(), loc.y());
            sel->select(loc.x(), loc.y());
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), true);
            sel->deSelect(loc.x(), loc.y());
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), false);
            sel->deSelect(loc.x(), loc.y());
            QCOMPARE(sel->isSelected(loc.x(), loc.y()), false);
        }
        void testCoordSelecter_getSelection_data()
        {
            testCoordSelecter_test_data();
        }
        void testCoordSelecter_getSelection(CoordSelecter* sel)
        {
            QFETCH(Coord, loc);

            Coord loc2(loc.x()-3, loc.y()+3);
            Coord loc3(loc.x()+3, loc.y()-3);
            Coord loc4(loc.x()-5, loc.y()+3);
            Coord loc5(loc.x()+3, loc.y()-1);

            sel->select(loc);
            sel->select(loc2);
            sel->select(loc3);

            const QLinkedList<Coord> list = sel->getSelection();

            QCOMPARE(list.contains(loc), true);
            QCOMPARE(list.contains(loc2), true);
            QCOMPARE(list.contains(loc3), true);
            QCOMPARE(list.contains(loc4), false);
            QCOMPARE(list.contains(loc5), false);
        }


        void testListCoordSelecter_test1_data() {
            testCoordSelecter_test1_data();
        }
        void testListCoordSelecter_test1() {
            ListCoordSelecter* sel = new ListCoordSelecter();
            testCoordSelecter_test1(sel);
            delete sel;
        }
        void testListCoordSelecter_test2_data() {
            testCoordSelecter_test2_data();
        }
        void testListCoordSelecter_test2() {
            ListCoordSelecter* sel = new ListCoordSelecter();
            testCoordSelecter_test2(sel);
            delete sel;
        }
        void testListCoordSelecter_test3_data() {
            testCoordSelecter_test3_data();
        }
        void testListCoordSelecter_test3() {
            ListCoordSelecter* sel = new ListCoordSelecter();
            testCoordSelecter_test3(sel);
            delete sel;
        }
        void testListCoordSelecter_test4_data() {
            testCoordSelecter_test4_data();
        }
        void testListCoordSelecter_test4() {
            ListCoordSelecter* sel = new ListCoordSelecter();
            testCoordSelecter_test4(sel);
            delete sel;
        }
        void testListCoordSelecter_getSelection_data()
        {
            testCoordSelecter_getSelection_data();
        }
        void testListCoordSelecter_getSelection()
        {
            ListCoordSelecter* sel = new ListCoordSelecter();
            testCoordSelecter_getSelection(sel);
            delete sel;
        }


        void testGridCoordSelecter_costructor_data()
        {
            QTest::addColumn<int> ("offX");
            QTest::addColumn<int> ("offY");
            QTest::addColumn<int> ("width");
            QTest::addColumn<int> ("height");
            QTest::addColumn<int> ("width_result");
            QTest::addColumn<int> ("height_result");
            QTest::newRow("0; 0 - 10;10") << 0 << 0 << 10 << 10  << 10 << 10;
            QTest::newRow("0; 0 - -10;-10") << 0 << 0 << -10 << -10  << 0 << 0;
            QTest::newRow("0; 0 - 10;40") << 0 << 0 << 10 << 40  << 10 << 40;
            QTest::newRow("-3; 1 - -61;-10") << -3 << 1 << -61 << -10  << 0 << 0;
        }
        void testGridCoordSelecter_costructor()
        {
            QFETCH(int, offX);
            QFETCH(int, offY);
            QFETCH(int, width);
            QFETCH(int, height);
            QFETCH(int, width_result);
            QFETCH(int, height_result);

            GridCoordSelecter sel(offX, offY, width, height);

            QCOMPARE(sel.offsetX(), offX);
            QCOMPARE(sel.offsetY(), offY);
            QCOMPARE(sel.width(), width_result);
            QCOMPARE(sel.height(), height_result);
        }
        void testGridCoordSelecter_test1_data() {
            testCoordSelecter_test1_data();
        }
        void testGridCoordSelecter_test1() {
            GridCoordSelecter* sel = new GridCoordSelecter(-20, -20, 40, 40);
            testCoordSelecter_test1(sel);
            delete sel;
        }
        void testGridCoordSelecter_test2_data() {
            testCoordSelecter_test2_data();
        }
        void testGridCoordSelecter_test2() {
            GridCoordSelecter* sel = new GridCoordSelecter(-20, -20, 40, 40);
            testCoordSelecter_test2(sel);
            delete sel;
        }
        void testGridCoordSelecter_test3_data() {
            testCoordSelecter_test3_data();
        }
        void testGridCoordSelecter_test3() {
            GridCoordSelecter* sel = new GridCoordSelecter(-20, -20, 40, 40);
            testCoordSelecter_test3(sel);
            delete sel;
        }
        void testGridCoordSelecter_test4_data() {
            testCoordSelecter_test4_data();
        }
        void testGridCoordSelecter_test4() {
            GridCoordSelecter* sel = new GridCoordSelecter(-20, -20, 40, 40);
            testCoordSelecter_test4(sel);
            delete sel;
        }
        void testGridCoordSelecter_getSelection_data()
        {
            testCoordSelecter_getSelection_data();
        }
        void testGridCoordSelecter_getSelection()
        {
            GridCoordSelecter* sel = new GridCoordSelecter(-20, -20, 40, 40);
            testCoordSelecter_getSelection(sel);
            delete sel;
        }

        void testDistanceFunction_data()
        {
            QTest::addColumn <Coord>("loc1");
            QTest::addColumn <Coord>("loc2");
            QTest::addColumn <float> ("dist");

            QTest::newRow("0;0 0;0") << Coord(0,0) << Coord(0,0) << 0.0f;
            QTest::newRow("0;0 10;0") << Coord(0,0) << Coord(10,0) << 10.0f;
            QTest::newRow("0;0 -10;0") << Coord(0,0) << Coord(-10,0) << 10.0f;
            QTest::newRow("0;0 0;10") << Coord(0,0) << Coord(0,10) << 10.0f;
            QTest::newRow("0;0 0;-10") << Coord(0,0) << Coord(0,-10) << 10.0f;
            QTest::newRow("5;0 10;0") << Coord(5,0) << Coord(10,0) << 5.0f;
            QTest::newRow("5;0 -10;0") << Coord(5,0) << Coord(-10,0) << 15.0f;
            QTest::newRow("0:5 0;10") << Coord(0,5) << Coord(0,10) << 5.0f;
            QTest::newRow("0;5 0;-10") << Coord(0,5) << Coord(0,-10) << 15.0f;
            QTest::newRow("-5;0 10;0") << Coord(-5,0) << Coord(10,0) << 15.0f;
            QTest::newRow("-5;0 -10;0") << Coord(-5,0) << Coord(-10,0) << 5.0f;
            QTest::newRow("0:-5 0;10") << Coord(0,-5) << Coord(0,10) << 15.0f;
            QTest::newRow("0;-5 0;-10") << Coord(0,-5) << Coord(0,-10) << 5.0f;
        }
        void testDistanceFunction(const AbstractDistanceFunction& func)
        {
            QFETCH(Coord, loc1);
            QFETCH(Coord, loc2);
            QFETCH(float, dist);

            QCOMPARE(func(loc1,loc2), dist);
            QCOMPARE(func(loc1.x(), loc1.y(), loc2.x(), loc2.y()), dist);
        }

        void testManhattanDistanceFunction_data()
        {
            testDistanceFunction_data();

            QTest::newRow("0;0 10;10") << Coord(0,0) << Coord(10,10) << 20.0f;
            QTest::newRow("0;0 -10;10") << Coord(0,0) << Coord(-10,10) << 20.0f;
            QTest::newRow("0;0 10;-10") << Coord(0,0) << Coord(10,-10) << 20.0f;
            QTest::newRow("0;0 -10;-10") << Coord(0,0) << Coord(-10,-10) << 20.0f;
            QTest::newRow("4;6 10;10") << Coord(4,6) << Coord(10,10) << 10.0f;
            QTest::newRow("4;6 -10;10") << Coord(4,6) << Coord(-10,10) << 18.0f;
            QTest::newRow("4;6 10;-10") << Coord(4,6) << Coord(10,-10) << 22.0f;
            QTest::newRow("4;6 -10;-10") << Coord(4,6) << Coord(-10,-10) << 30.0f;
            QTest::newRow("-4;-6 10;10") << Coord(-4,-6) << Coord(10,10) << 30.0f;
            QTest::newRow("-4;-6 -10;10") << Coord(-4,-6) << Coord(-10,10) << 22.0f;
            QTest::newRow("-4;-6 10;-10") << Coord(-4,-6) << Coord(10,-10) << 18.0f;
            QTest::newRow("-4;-6 -10;-10") << Coord(-4,-6) << Coord(-10,-10) << 10.0f;
        }
        void testManhattanDistanceFunction()
        {
            testDistanceFunction(ManhattanDistanceFunction());
        }


        void testEuclideanDistanceFunction_data()
        {
            testDistanceFunction_data();

            QTest::newRow("0;0 10;10") << Coord(0,0) << Coord(10,10) << (float)qSqrt(200);
            QTest::newRow("0;0 -10;10") << Coord(0,0) << Coord(-10,10) << (float)qSqrt(200);
            QTest::newRow("0;0 10;-10") << Coord(0,0) << Coord(10,-10) << (float)qSqrt(200);
            QTest::newRow("0;0 -10;-10") << Coord(0,0) << Coord(-10,-10) << (float)qSqrt(200);
            QTest::newRow("4;6 10;10") << Coord(4,6) << Coord(10,10) << (float)qSqrt(36+16);
            QTest::newRow("4;6 -10;10") << Coord(4,6) << Coord(-10,10) << (float)qSqrt(14*14+16);
            QTest::newRow("4;6 10;-10") << Coord(4,6) << Coord(10,-10) << (float)qSqrt(36+16*16);
            QTest::newRow("4;6 -10;-10") << Coord(4,6) << Coord(-10,-10) << (float)qSqrt(14*14+16*16);
            QTest::newRow("-4;-6 10;10") << Coord(-4,-6) << Coord(10,10) << (float)qSqrt(14*14+16*16);
            QTest::newRow("-4;-6 -10;10") << Coord(-4,-6) << Coord(-10,10) << (float)qSqrt(36+16*16);
            QTest::newRow("-4;-6 10;-10") << Coord(-4,-6) << Coord(10,-10) << (float)qSqrt(14*14+16);
            QTest::newRow("-4;-6 -10;-10") << Coord(-4,-6) << Coord(-10,-10) << (float)qSqrt(36+16);
        }
        void testEuclideanDistanceFunction()
        {
            testDistanceFunction(EuclideanDistanceFunction());
        }


        void testDiagonalDistanceFunction_data()
        {
            testDistanceFunction_data();

            QTest::newRow("0;0 10;10") << Coord(0,0) << Coord(10,10) << 10.0f;
            QTest::newRow("0;0 -10;10") << Coord(0,0) << Coord(-10,10) << 10.0f;
            QTest::newRow("0;0 10;-10") << Coord(0,0) << Coord(10,-10) << 10.0f;
            QTest::newRow("0;0 -10;-10") << Coord(0,0) << Coord(-10,-10) << 10.0f;
            QTest::newRow("4;6 10;10") << Coord(4,6) << Coord(10,10) << 6.0f;
            QTest::newRow("4;6 -10;10") << Coord(4,6) << Coord(-10,10) << 14.0f;
            QTest::newRow("4;6 10;-10") << Coord(4,6) << Coord(10,-10) << 16.0f;
            QTest::newRow("4;6 -10;-10") << Coord(4,6) << Coord(-10,-10) << 16.0f;
            QTest::newRow("-4;-6 10;10") << Coord(-4,-6) << Coord(10,10) << 16.0f;
            QTest::newRow("-4;-6 -10;10") << Coord(-4,-6) << Coord(-10,10) << 16.0f;
            QTest::newRow("-4;-6 10;-10") << Coord(-4,-6) << Coord(10,-10) << 14.0f;
            QTest::newRow("-4;-6 -10;-10") << Coord(-4,-6) << Coord(-10,-10) << 6.0f;
        }
        void testDiagonalDistanceFunction()
        {
            testDistanceFunction(DiagonalDistanceFunction());
        }


        void testSquaredEuclideanDistanceFunction_data()
        {
            QTest::addColumn <Coord>("loc1");
            QTest::addColumn <Coord>("loc2");
            QTest::addColumn <float> ("dist");

            QTest::newRow("0;0 0;0") << Coord(0,0) << Coord(0,0) << 0.0f;
            QTest::newRow("0;0 10;0") << Coord(0,0) << Coord(10,0) << 100.0f;
            QTest::newRow("0;0 -10;0") << Coord(0,0) << Coord(-10,0) << 100.0f;
            QTest::newRow("0;0 0;10") << Coord(0,0) << Coord(0,10) << 100.0f;
            QTest::newRow("0;0 0;-10") << Coord(0,0) << Coord(0,-10) << 100.0f;
            QTest::newRow("5;0 10;0") << Coord(5,0) << Coord(10,0) << 25.0f;
            QTest::newRow("5;0 -10;0") << Coord(5,0) << Coord(-10,0) << 225.0f;
            QTest::newRow("0:5 0;10") << Coord(0,5) << Coord(0,10) << 25.0f;
            QTest::newRow("0;5 0;-10") << Coord(0,5) << Coord(0,-10) << 225.0f;
            QTest::newRow("-5;0 10;0") << Coord(-5,0) << Coord(10,0) << 225.0f;
            QTest::newRow("-5;0 -10;0") << Coord(-5,0) << Coord(-10,0) << 25.0f;
            QTest::newRow("0:-5 0;10") << Coord(0,-5) << Coord(0,10) << 225.0f;
            QTest::newRow("0;-5 0;-10") << Coord(0,-5) << Coord(0,-10) << 25.0f;

            QTest::newRow("0;0 10;10") << Coord(0,0) << Coord(10,10) << 200.0f;
            QTest::newRow("0;0 -10;10") << Coord(0,0) << Coord(-10,10) << 200.0f;
            QTest::newRow("0;0 10;-10") << Coord(0,0) << Coord(10,-10) << 200.0f;
            QTest::newRow("0;0 -10;-10") << Coord(0,0) << Coord(-10,-10) << 200.0f;
            QTest::newRow("4;6 10;10") << Coord(4,6) << Coord(10,10) << (float)(36+16);
            QTest::newRow("4;6 -10;10") << Coord(4,6) << Coord(-10,10) << (float)(14*14+16);
            QTest::newRow("4;6 10;-10") << Coord(4,6) << Coord(10,-10) << (float)(36+16*16);
            QTest::newRow("4;6 -10;-10") << Coord(4,6) << Coord(-10,-10) << (float)(14*14+16*16);
            QTest::newRow("-4;-6 10;10") << Coord(-4,-6) << Coord(10,10) << (float)(14*14+16*16);
            QTest::newRow("-4;-6 -10;10") << Coord(-4,-6) << Coord(-10,10) << (float)(36+16*16);
            QTest::newRow("-4;-6 10;-10") << Coord(-4,-6) << Coord(10,-10) << (float)(14*14+16);
            QTest::newRow("-4;-6 -10;-10") << Coord(-4,-6) << Coord(-10,-10) << (float)(36+16);
        }
        void testSquaredEuclideanDistanceFunction()
        {
            testDistanceFunction(SquaredEuclideanDistanceFunction());
        }
};

#endif // TESTS_H
