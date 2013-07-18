#include "floyd.h"

int main(int argc, char* argv[])
{
	Floyd test(6);
	test.input();
	Floyd copyTest(test);
	copyTest.solve();
	system("pause");
	return 0;
}