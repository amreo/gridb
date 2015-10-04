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

		void costructor1() {
			Located l;
			QVERIFY(l.x == 0);
			QVERIFY(l.y == 0);
		}
		void costructor2_data() {
			QTest::addColumn<int>("x");
			QTest::addColumn<int>("y");
			QTest::newRow("x=0 y=0") << 0 << 0;
			QTest::newRow("x=1 y=0") << 1 << 0;
			QTest::newRow("x=0 y=1") << 0 << 1;
			QTest::newRow("x=1 y=1") << 1 << 1;
		}
		void costructor2() {
			QFETCH(int, x);
			QFETCH(int, y);
			Located l(x,y);
			QVERIFY(l.x == x);
			QVERIFY(l.y == y);
		}
};

#endif // TESTLOCATED_H
