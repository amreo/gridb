#ifndef TESTLOCATED_H
#define TESTLOCATED_H

#include "autotest.h"
#include <QTest>
#include "located.h"

/**
 * @author amreo
 * @brief The TestLocated class
 * @version 1.0
 * @since 1.0
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
		}

		void costructor1() {
			Located l;
			QVERIFY(l.getX() == 0);
			QVERIFY(l.getY() == 0);
		}
		void costructor2_data() {
			common_data();
		}
		void costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			QVERIFY(l.getX() == x);
			QVERIFY(l.getY() == y);
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
			QVERIFY(l2.getX() == x);
			QVERIFY(l2.getY() == y);
			QVERIFY(l3.getX() == x);
			QVERIFY(l3.getY() == y);
		}
		void getLocation_data() {
			common_data();
		}
		void getLocation() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			Located l2 = l.getLocation();
			QVERIFY(l2.getX() == x);
			QVERIFY(l2.getY() == y);
		}
};

#endif // TESTLOCATED_H
