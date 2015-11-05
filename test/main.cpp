
#include "tests.h"
#include <QDebug>

/**
 * @author amreo
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
	Test* test = new Test();
	int res = QTest::qExec(test, argc, argv);
	delete test;
	return res;
}

