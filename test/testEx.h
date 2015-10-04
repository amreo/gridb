#ifndef TESTEX_H
#define TESTEX_H

#include "autotest.h"
#include <QTest>

class TestEx : public QObject
{
		Q_OBJECT

	private slots:
		//void initTestCase();
		void test_data() {
			QTest::addColumn<QString>("string");
			QTest::addColumn<QString>("result");

			QTest::newRow("all lower") << "hello" << "HELLO";
			QTest::newRow("mixed")     << "Hello" << "HELLO";
			QTest::newRow("all upper") << "HELLO" << "HELLO";
		}
		void test() {
			QFETCH(QString, string);
			QFETCH(QString, result);

			QCOMPARE(string.toUpper(), result);
		}
		//void cleanupTestCase();
};

#endif // TESTEX_H

