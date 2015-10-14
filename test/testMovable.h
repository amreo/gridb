#ifndef TESTMOVABLE_H
#define TESTMOVABLE_H

#include "autotest.h"
#include <QTest>
#include "movable.h"
#include "located.h"

/**
 * @author amreo
 * @brief The TestMovable class
 * @version 0.1
 * @since 0.1
 */
class TestMovable : public QObject
{
		Q_OBJECT

	private slots:
		void common_data() {
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

		void costructor1() {
			Movable l;
			QCOMPARE(l.getX(), 0);
			QCOMPARE(l.getY(), 0);
		}
		void costructor2_data() {
			common_data();
		}
		void costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l(x,y);
			QCOMPARE(l.getX(), x);
			QCOMPARE(l.getY(), y);
		}
		void costructor3_data() {
			common_data();
		}
		void costructor3() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l(x,y);
			Movable l2 = l;
			Movable l3(l);
			Located l4(x,y);
			Movable l5 = l4;
			Movable l6(l4);
			QCOMPARE(l2.getX(), x);
			QCOMPARE(l2.getY(), y);
			QCOMPARE(l3.getX(), x);
			QCOMPARE(l3.getY(), y);
			QCOMPARE(l5.getX(), x);
			QCOMPARE(l5.getY(), y);
			QCOMPARE(l6.getX(), x);
			QCOMPARE(l6.getY(), y);

		}

		void set_data() {
			common_data();
		}
		void set() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l1;
			Movable l2;
			Movable l3;
			l1.setX(x);
			l1.setY(y);
			l2.setMovable(x,y);
			l3.setMovable(l1);
			QCOMPARE(l1.getX(), x);
			QCOMPARE(l1.getY(), y);
			QCOMPARE(l2.getX(), x);
			QCOMPARE(l2.getY(), y);
			QCOMPARE(l3.getX(), x);
			QCOMPARE(l3.getY(), y);
		}

};

#endif // TESTMOVABLE_H
