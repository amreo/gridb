#ifndef TESTLOCATED_H
#define TESTLOCATED_H

#include "autotest.h"
#include <QTest>
#include "located.h"

/**
 * @author amreo
 * @brief The TestLocated class
 * @version 0.1
 * @since 0.1
 */
class TestLocated : public QObject
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
			Located l;
			QCOMPARE(l.x(), 0);
			QCOMPARE(l.y(), 0);
		}
		void costructor2_data() {
			common_data();
		}
		void costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			QCOMPARE(l.x(), x);
			QCOMPARE(l.y(), y);
		}
		void costructor3_data() {
			common_data();
		}
		void costructor3() {
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
		void getLocation_data() {
			common_data();
		}
		void getLocation() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			Located l2 = l.getLocation();
			QCOMPARE(l2.x(), x);
			QCOMPARE(l2.y(), y);
		}
};

#endif // TESTLOCATED_H
