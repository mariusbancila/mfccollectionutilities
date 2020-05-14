#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\include\mfciterators.h"
#include "IntObject.h"

#include "Specializations.h"  // last include

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTests
{
   TEST_CLASS(ListTests)
   {
   private:
      template <class T, class TList>
      void TestNumericList(int const n)
      {
         std::vector<T> numbers(n);
         std::iota(std::begin(numbers), std::end(numbers), 1);

         TList list;
         for (auto i : numbers) list.AddTail(i);

         int count = 0;
         for (auto e : list)
         {
            Assert::AreEqual(numbers[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         TList const& clist = list;

         count = 0;
         for (auto e : clist)
         {
            Assert::AreEqual(numbers[count], e);
            count++;
         }

         Assert::AreEqual(n, count);
      }

      void TestStringList(int const n)
      {
         std::vector<CString> texts;
         for (int i = 0; i < n; ++i)
         {
            CString temp; temp.Format(L"element_%d", i);
            texts.push_back(temp);
         }

         CStringList list;
         for (auto i : texts) list.AddTail(i);

         int count = 0;
         for (auto e : list)
         {
            Assert::AreEqual(texts[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         CStringList const& clist = list;

         count = 0;
         for (auto e : clist)
         {
            Assert::AreEqual(texts[count], e);
            count++;
         }

         Assert::AreEqual(n, count);
      }

      void TestPtrList(int const n)
      {
         std::vector<int*> numbers;
         for (int i = 0; i < n; ++i)
         {
            numbers.push_back(new int(i + 1));
         }

         CPtrList list;
         for (auto i : numbers) list.AddTail(i);

         int count = 0;
         for (auto e : list)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], static_cast<int*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         CPtrList const& clist = list;

         count = 0;
         for (auto e : clist)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], const_cast<int*>(static_cast<int const*>(e)));
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : numbers)
            delete ptr;
      }

      void TestObjectList(int const n)
      {
         std::vector<IntObject*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new IntObject(i + 1));
         }

         CObList list;
         for (auto i : objects) list.AddTail(i);

         int count = 0;
         for (auto e : list)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], static_cast<IntObject*>(e));
            count++;
         }

         Assert::AreEqual(n, count);

         CObList const& clist = list;

         count = 0;
         for (auto e : clist)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(objects[count], const_cast<IntObject*>(static_cast<IntObject const*>(e)));
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : objects)
            delete ptr;
      }

      template <class T>
      void TestTypedPtrList(int const n)
      {
         std::vector<T*> numbers;
         for (int i = 0; i < n; ++i)
         {
            numbers.push_back(new T(i + 1));
         }

         CTypedPtrList<CPtrList, T*> list;
         for (auto i : numbers) list.AddTail(i);

         int count = 0;
         for (auto e : list)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         CTypedPtrList<CPtrList, T*> const& clist = list;

         count = 0;
         for (auto e : clist)
         {
            Assert::IsNotNull(e);
            Assert::AreEqual(numbers[count], e);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto ptr : numbers)
            delete ptr;
      }

   public:
      TEST_METHOD(TestList_Empty)
      {
         TestNumericList<int, CList<int>>(0);
      }

      TEST_METHOD(TestList_One)
      {
         TestNumericList<int, CList<int>>(1);
      }

      TEST_METHOD(TestList_Many)
      {
         TestNumericList<int, CList<int>>(10);
      }

      TEST_METHOD(TestStringList_Empty)
      {
         TestStringList(0);
      }

      TEST_METHOD(TestStringList_One)
      {
         TestStringList(1);
      }

      TEST_METHOD(TestStringList_Many)
      {
         TestStringList(10);
      }

      TEST_METHOD(TestPtrList_Empty)
      {
         TestPtrList(0);
      }

      TEST_METHOD(TestPtrList_One)
      {
         TestPtrList(1);
      }

      TEST_METHOD(TestPtrList_Many)
      {
         TestPtrList(10);
      }

      TEST_METHOD(TestObList_Empty)
      {
         TestObjectList(0);
      }

      TEST_METHOD(TestObList_One)
      {
         TestObjectList(1);
      }

      TEST_METHOD(TestObList_Many)
      {
         TestObjectList(10);
      }

      TEST_METHOD(TestTypedPtrList_Empty)
      {
         TestTypedPtrList<IntObject>(0);
      }

      TEST_METHOD(TestTypedPtrList_One)
      {
         TestTypedPtrList<IntObject>(1);
      }

      TEST_METHOD(TestTypedPtrList_Many)
      {
         TestTypedPtrList<IntObject>(10);
      }
   };
}