#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\include\mfciterators.h"
#include "IntObject.h"

#include "Specializations.h"  // last include

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTests
{
   TEST_CLASS(AlgorithmTests)
   {
      TEST_METHOD(Test_All_Of)
      {
         {
            CArray<int> arr;

            bool odds = std::all_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsTrue(odds);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(3);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::all_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsTrue(odds);
         }

         {
            CArray<int> arr;
            arr.Add(2);
            arr.Add(4);
            arr.Add(6);
            arr.Add(8);

            bool evens = std::all_of(begin(arr), end(arr), [](int const n) {return n % 2 == 0; });
            Assert::IsTrue(evens);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(2);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::all_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsFalse(odds);
         }

         {
            CTypedPtrArray<CObArray, IntObject*> arr;
            arr.Add(new IntObject(1));
            arr.Add(new IntObject(3));
            arr.Add(new IntObject(5));
            arr.Add(new IntObject(7));

            bool all = std::all_of(begin(arr), end(arr),
               [](IntObject* o) { return o->value % 2 == 1; });
            Assert::IsTrue(all);

            for (auto p : arr)
               delete p;
         }
      }
   };
}