#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_12_8/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			addTask("Buy groceries", "2023-04-20", "not completed");
			calculatePenalties();
			Assert::AreEqual(head->penalty, 10);
		}
	};
}
