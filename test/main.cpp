
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
	return QTest::qExec(new Test(), argc, argv);
}

