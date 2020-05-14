#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\include\mfciterators.h"
#include "IntObject.h"

#include "Specializations.h"  // last include

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTests
{
	TEST_CLASS(ArrayTests)
	{
   private:
		template <class T, class TArray>
		void TestNumericArray(int const n)
		{
			std::vector<T> numbers(n);
			std::iota(std::begin(numbers), std::end(numbers), 1);

			TArray arr;
			for (auto i : numbers) arr.Add(i);

			int count = 0;
			for (auto e : arr)
			{
				Assert::AreEqual(numbers[count], e);
				count++;
			}

			Assert::AreEqual(n, count);

			TArray const& carr = arr;

         count = 0;
         for (auto e : carr)
         {
            Assert::AreEqual(numbers[count], e);
            count++;
         }

         Assert::AreEqual(n, count);
		}

      void TestStringArray(int const n)
      {
         std::vector<CString> texts;
         for (int i = 0; i < n; ++i)
         {
            CString temp; temp.Format(L"element_%d", i);
            texts.push_back(temp);
         }

         CStringArray arr;
         for (auto i : texts) arr.Add(i);

         int count = 0;
         for (auto e : arr)
         {
            Assert::AreEqual(texts[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         CStringArray const& carr = arr;

         count = 0;
         for (auto e : carr)
         {
            Assert::AreEqual(texts[count], e);
            count++;
         }

         Assert::AreEqual(n, count);
      }

      void TestPtrArray(int const n)
      {
         std::vector<int*> numbers;
         for (int i = 0; i < n; ++i)
         {
            numbers.push_back(new int(i+1));
         }

         CPtrArray arr;
         for (auto i : numbers) arr.Add(i);

         int count = 0;
         for (auto e : arr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], static_cast<int*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         CPtrArray const& carr = arr;

         count = 0;
         for (auto e : carr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], static_cast<int*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : numbers)
            delete ptr;
      }

      void TestObjectArray(int const n)
      {
         std::vector<IntObject*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new IntObject(i+1));
         }

         CObArray arr;
         for (auto i : objects) arr.Add(i);

         int count = 0;
         for (auto e : arr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], static_cast<IntObject*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         CObArray const& carr = arr;

         count = 0;
         for (auto e : carr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], static_cast<IntObject*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : objects)
            delete ptr;
      }

      template <class T, class TTArray>
      void TestTypedArray(int const n)
      {
         std::vector<T*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new T(i + 1));
         }

         TTArray arr;
         for (auto i : objects) arr.Add(i);

         int count = 0;
         for (auto e : arr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         TTArray const& carr = arr;

         count = 0;
         for (auto e : carr)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : objects)
            delete ptr;
      }

	public:
		
		TEST_METHOD(TestArray_Empty)
		{						
			TestNumericArray<int, CArray<int>>(0);
		}

      TEST_METHOD(TestArray_One)
      {
			TestNumericArray<int, CArray<int>>(1);
      }

      TEST_METHOD(TestArray_Many)
      {
			TestNumericArray<int, CArray<int>>(10);
      }

      TEST_METHOD(TestByteArray_Empty)
      {
         TestNumericArray<BYTE, CByteArray>(0);
      }

      TEST_METHOD(TestByteArray_One)
      {
         TestNumericArray<BYTE, CByteArray>(1);
      }

      TEST_METHOD(TestByteArray_Many)
      {
         TestNumericArray<BYTE, CByteArray>(10);
      }
      
      TEST_METHOD(TestWordArray_Empty)
      {
         TestNumericArray<WORD, CWordArray>(0);
      }
      
      TEST_METHOD(TestWordArray_One)
      {
         TestNumericArray<WORD, CWordArray>(1);
      }

      TEST_METHOD(TestWordArray_Many)
      {
         TestNumericArray<WORD, CWordArray>(10);
      }
      
      TEST_METHOD(TestDWordArray_Empty)
      {
         TestNumericArray<DWORD, CDWordArray>(0);
      }

      TEST_METHOD(TestDWordArray_One)
      {
         TestNumericArray<DWORD, CDWordArray>(1);
      }

      TEST_METHOD(TestDWordArray_Many)
      {
         TestNumericArray<DWORD, CDWordArray>(10);
      }

      TEST_METHOD(TestUIntArray_Empty)
      {
         TestNumericArray<UINT, CUIntArray>(0);
      }

      TEST_METHOD(TestUIntArray_One)
      {
         TestNumericArray<UINT, CUIntArray>(1);
      }

      TEST_METHOD(TestUIntArray_Many)
      {
         TestNumericArray<UINT, CUIntArray>(10);
      }

      TEST_METHOD(TestStringArray_Empty)
      {
         TestStringArray(0);
      }

      TEST_METHOD(TestStringArray_One)
      {
         TestStringArray(1);
      }

      TEST_METHOD(TestStringArray_Many)
      {
         TestStringArray(10);
      }

      TEST_METHOD(TestPtrArray_Empty)
      {
         TestPtrArray(0);
      }

      TEST_METHOD(TestPtrArray_One)
      {
         TestPtrArray(1);
      }

      TEST_METHOD(TestPtrArray_Many)
      {
         TestPtrArray(10);
      }

      TEST_METHOD(TestObArray_Empty)
      {
         TestObjectArray(0);
      }

      TEST_METHOD(TestObArray_One)
      {
         TestObjectArray(1);
      }

      TEST_METHOD(TestObArray_Many)
      {
         TestObjectArray(10);
      }

      TEST_METHOD(TestTypedPtrArray_Empty)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CPtrArray, IntObject*>>(0);
      }

      TEST_METHOD(TestTypedPtrArray_One)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CPtrArray, IntObject*>>(1);
      }

      TEST_METHOD(TestTypedPtrArray_Many)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CPtrArray, IntObject*>>(10);
      }

      TEST_METHOD(TestTypedObArray_Empty)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CObArray, IntObject*>>(0);
      }

      TEST_METHOD(TestTypedObArray_One)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CObArray, IntObject*>>(1);
      }

      TEST_METHOD(TestTypedObArray_Many)
      {
         TestTypedArray<IntObject, CTypedPtrArray<CObArray, IntObject*>>(10);
      }
	};
}
