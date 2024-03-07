#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_8.1_REC/main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCount)
		{
			// Arrange
			char str1[] = "abc***def***ghi***jkl";
			char str2[] = "***";
			char str3[] = "abc";

			// Act
			int count1 = Count(str1, 0);
			int count2 = Count(str2, 0);
			int count3 = Count(str3, 0);

			// Assert
			Assert::AreEqual(3, count1);
			Assert::AreEqual(1, count2);
			Assert::AreEqual(0, count3);
		}

		TEST_METHOD(TestChange)
		{
			// Arrange
			char str1[] = "abc***def***ghi***jkl";
			char str2[] = "abc";

			// Act
			char* result1 = new char[strlen(str1) * 4 / 3 + 1];
			result1[0] = '\0';
			char* result2 = new char[strlen(str2) * 4 / 3 + 1];
			result2[0] = '\0';
			Change(result1, str1, result1, 0);
			Change(result2, str2, result2, 0);

			// Assert
			Assert::AreEqual("abc!!def!!ghi!!jkl", result1);
			Assert::AreEqual("abc", result2);

			// Clean up
			delete[] result1;
			delete[] result2;
		}
	};
}
