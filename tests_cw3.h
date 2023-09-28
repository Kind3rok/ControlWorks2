#ifndef TESTS_CW3_H
#define TESTS_CW3_H

#include <vector>


class UnitTestCW3
{
public:
	void PrintArray(std::vector<int> array);

	bool TestCaseOne();
	bool TestCaseTwo();
	bool TestCaseThree();
	bool TestCaseFour();
	bool TestCaseFive();

	void RunAllTests();
};

#endif