#include "pch.h"
#include "CppUnitTest.h"
#include "/ap_labs/lab6.2.rek/lab6.2.rek/lab6.2.rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rek
{
	TEST_CLASS(UnitTest62rek)
	{
	public:
		
        TEST_METHOD(TestF)
        {
            const int size = 100;
            int a[size];
            F(a, size, -50, 50);
            for (int i = 0; i < size; i++)
            {
                Assert::IsTrue(a[i] >= -50 && a[i] <= 50);
            }
        }

        TEST_METHOD(TestFindMax)
        {
            int a[] = { 3, -7, 12, 0, 5 };
            int t = FindMax(a, 5);
            Assert::AreEqual(12, t);
        }

        TEST_METHOD(TestFindMin)
        {
            int a[] = { 3, -7, 12, 0, 5 };
            int t = FindMin(a, 5);
            Assert::AreEqual(-7, t);
        }

        TEST_METHOD(TestSum)
        {
            int a[] = { 3, -7, 12, 0, 5 };
            int t = Sum(a, 5);
            Assert::AreEqual(5, t);   // 12 + (-7)
        }
	};
}
