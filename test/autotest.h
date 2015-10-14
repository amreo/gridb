#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QTest>
#include <QMap>
#include <QString>

/**
 * @brief The AutoTest class
 * @author amreo
 * @version 0.0
 * @since 0.0
 */
class AutoTest
{
	public:
		typedef QMap<QString, QObject*> TestList;

		inline TestList& testList()
		{
			static TestList list;
			return list;
		}
		inline QObject* findObject(QString name)
		{
			return testList().value(name,NULL);
		}
		inline void addTest(QString name, QObject* object)
		{
			testList().insert(name,object);
		}
		inline int runAll(int argc, char *argv[])
		{
			int ret = 0;

			foreach (QObject* test, testList().values())
			{
				ret += QTest::qExec(test, argc, argv);
			}

			return ret;
		}
		inline int run(QString name, int argc, char *argv[])
		{
			return QTest::qExec(findObject(name),argc,argv);
		}

};
#endif // AUTOTEST_H

