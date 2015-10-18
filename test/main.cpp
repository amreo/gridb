
#include "tests.h"
#include <QDebug>
#define ADD(name,test) at.addTest(name, new test)

/**
 * @author amreo
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
	return QTest::qExec(new Test(), argc, argv);
}

