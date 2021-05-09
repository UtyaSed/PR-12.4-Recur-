#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 12.4(Recur)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* one;
			one = new Elem;

			one->info = 29;
			one->link = new Elem;

			one->link->info = 60;
			one->link->link = new Elem;

			one->link->link->info = 97;
			one->link->link->link = one;

			Elem* two = NULL;
			Elem* start = one;
			process(one, two, start, 3, 0);

			Assert::AreEqual(two->info, 97);
		}
	};
}
