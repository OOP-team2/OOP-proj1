#include "pch.h"
#include "CppUnitTest.h"
#include "Date.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IIKHTest
{
	TEST_CLASS(IIKHTest)
	{
	public:
		
		DateTest(DateEqualTest)
		{
			Date dateA = Date(2022, 10, 1);
			Date dateB = Date(2022, 10, 1);
			Assert::AreEqual(dateA, dateB);
		}
		DateInequalTest(DateInequalTest) {
			Date dateA = Date(2022, 10, 1);
			Date dateB = Date(2022, 10, 2);
			Assert::AreNotEqual(dateA, dateB);
		}
	};
}
