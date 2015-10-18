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
			QCOMPARE(l.x(), 0);
			QCOMPARE(l.y(), 0);
		}
		void costructor2_data() {
			common_data();
		}
		void costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Movable l(x,y);
			QCOMPARE(l.x(), x);
			QCOMPARE(l.y(), y);
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
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
			QCOMPARE(l3.x(), x);
			QCOMPARE(l3.y(), y);
			QCOMPARE(l5.x(), x);
			QCOMPARE(l5.y(), y);
			QCOMPARE(l6.x(), x);
			QCOMPARE(l6.y(), y);

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

#endif // TESTMOVABLE_H
