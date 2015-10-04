#include "autotest.h"
#include "testEx.h"
#include "testLocated.h"
#include <QDebug>
#define ADD(name,test) at.addTest(name, new test)

int main(int argc, char *argv[])
{
	AutoTest at;

	//Tests
	ADD("ID001", TestLocated);

	//Run test(s)
	if (argc==1) {
		return at.runAll(argc,argv);
	} else {
		int returncode;
		for (int i=1; i<argc; i++)
			if (at.findObject(QString(argv[i])) != NULL)
				returncode += at.run(QString(argv[i]),0,argv);
		return returncode;
	}

}

