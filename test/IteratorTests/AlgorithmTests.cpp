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
      TEST_METHOD(Test_all_Of)
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

      TEST_METHOD(Test_any_Of)
      {
         {
            CArray<int> arr;

            bool odds = std::any_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsFalse(odds);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(3);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::any_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsTrue(odds);
         }

         {
            CArray<int> arr;
            arr.Add(2);
            arr.Add(4);
            arr.Add(6);
            arr.Add(8);

            bool evens = std::any_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsFalse(evens);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(2);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::any_of(begin(arr), end(arr), [](int const n) {return n % 2 == 0; });
            Assert::IsTrue(odds);
         }

         {
            CTypedPtrArray<CObArray, IntObject*> arr;
            arr.Add(new IntObject(1));
            arr.Add(new IntObject(2));
            arr.Add(new IntObject(5));
            arr.Add(new IntObject(7));

            bool all = std::any_of(begin(arr), end(arr),
               [](IntObject* o) { return o->value % 2 == 0; });
            Assert::IsTrue(all);

            for (auto p : arr)
               delete p;
         }
      }

      TEST_METHOD(Test_aone_Of)
      {
         {
            CArray<int> arr;

            bool odds = std::none_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsTrue(odds);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(3);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::none_of(begin(arr), end(arr), [](int const n) {return n % 2 == 0; });
            Assert::IsTrue(odds);
         }

         {
            CArray<int> arr;
            arr.Add(2);
            arr.Add(4);
            arr.Add(6);
            arr.Add(8);

            bool evens = std::none_of(begin(arr), end(arr), [](int const n) {return n % 2 == 1; });
            Assert::IsTrue(evens);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(2);
            arr.Add(5);
            arr.Add(7);

            bool odds = std::none_of(begin(arr), end(arr), [](int const n) {return n % 2 == 0; });
            Assert::IsFalse(odds);
         }

         {
            CTypedPtrArray<CObArray, IntObject*> arr;
            arr.Add(new IntObject(1));
            arr.Add(new IntObject(2));
            arr.Add(new IntObject(5));
            arr.Add(new IntObject(7));

            bool all = std::none_of(begin(arr), end(arr),
               [](IntObject* o) { return o->value % 2 == 0; });
            Assert::IsFalse(all);

            for (auto p : arr)
               delete p;
         }
      }

      TEST_METHOD(Test_iota)
      {
         {
            CArray<int> arr;
            std::iota(begin(arr), end(arr), 1);
            Assert::IsTrue(arr.IsEmpty());
         }

         {
            CArray<int> arr;
            arr.SetSize(10);
            std::iota(begin(arr), end(arr), 1);
            for (INT_PTR i = 0; i < arr.GetSize(); ++i)
            {
               Assert::AreEqual(i + 1, arr[i]);
            }
         }

         {
            CWordArray arr;
            arr.SetSize(10);
            std::iota(begin(arr), end(arr), 1);
            for (INT_PTR i = 0; i < arr.GetSize(); ++i)
            {
               Assert::AreEqual(static_cast<WORD>(i + 1), arr[i]);
            }
         }
      }

      TEST_METHOD(Test_fill)
      {
         {
            CArray<int> arr;
            std::fill(begin(arr), end(arr), 1);
            Assert::IsTrue(arr.IsEmpty());
         }

         {
            CArray<int> arr;
            arr.SetSize(10);
            constexpr int value = 1;
            std::fill(begin(arr), end(arr), value);
            for (INT_PTR i = 0; i < arr.GetSize(); ++i)
            {
               Assert::AreEqual(value, arr[i]);
            }
         }

         {
            CWordArray arr;
            arr.SetSize(10);
            constexpr WORD value = 1;
            std::fill(begin(arr), end(arr), value);
            for (INT_PTR i = 0; i < static_cast<WORD>(arr.GetSize()); ++i)
            {
               Assert::AreEqual(value, arr[i]);
            }
         }
      }
      /*
      TEST_METHOD(Test_fill_n)
      {
         {
            CArray<int> arr;
            std::fill_n(begin(arr), 1, 1);
            Assert::IsTrue(arr.IsEmpty());
         }
         
         {
            CArray<int> arr;
            arr.SetSize(10);
            constexpr int value = 1;
            std::fill_n(begin(arr), 5, value);
            for (INT_PTR i = 0; i < 5; ++i)
            {
               Assert::AreEqual(value, arr[i]);
            }
         }

         {
            CWordArray arr;
            arr.SetSize(10);
            constexpr WORD value = 1;
            std::fill_n(begin(arr), 5, value);
            for (INT_PTR i = 0; i < 5; ++i)
            {
               Assert::AreEqual(value, arr[i]);
            }
         }

         {
            CWordArray arr;
            arr.SetSize(10);
            constexpr WORD value = 1;
            std::fill_n(begin(arr), 15, value);
            for (INT_PTR i = 0; i < arr.GetSize(); ++i)
            {
               Assert::AreEqual(value, arr[i]);
            }
         }
      }
      */

      TEST_METHOD(Test_accumulate)
      {
         {
            CArray<int> arr;
            auto sum = std::accumulate(begin(arr), end(arr), 0);
            Assert::AreEqual(0, sum);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            auto sum = std::accumulate(begin(arr), end(arr), 0);
            Assert::AreEqual(1, sum);
         }

         {
            CArray<int> arr;
            arr.Add(1);
            arr.Add(2);
            arr.Add(3);
            auto sum = std::accumulate(begin(arr), end(arr), 0);
            Assert::AreEqual(6, sum);
         }

         {
            CWordArray arr;
            arr.Add(1);
            arr.Add(2);
            arr.Add(3);
            auto sum = std::accumulate(begin(arr), end(arr), 0);
            Assert::AreEqual(6, sum);
         }
         /*
         {
            CList<int> arr;
            arr.AddTail(1);
            arr.AddTail(2);
            arr.AddTail(3);
            auto sum = std::accumulate(begin(arr), end(arr), 0);
            Assert::AreEqual(6, sum);
         }
         */
         {
            CTypedPtrArray<CObArray, IntObject*> arr;
            arr.Add(new IntObject(1));
            arr.Add(new IntObject(2));
            arr.Add(new IntObject(3));

            auto sum = std::accumulate(
               begin(arr), end(arr),
               0,
               [](int total, IntObject* o) { return total + o->value; });
            Assert::AreEqual(6, sum);

            for (auto p : arr)
               delete p;
         }
      }
   };
}