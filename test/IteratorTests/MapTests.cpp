#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\include\mfciterators.h"
#include "IntObject.h"

#include "Specializations.h"  // last include

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IteratorTests
{
   TEST_CLASS(MapTests)
   {
   private:
      template <class T, class TMap>
      void TestNumericMap(int const n)
      {
         std::vector<T> numbers(n);
         std::iota(std::begin(numbers), std::end(numbers), 1);

         TMap map;
         for (auto i : numbers) map[i] = i;

         int count = 0;
         for (auto e : map)
         {
            Assert::AreEqual(e.key, e.value);
            Assert::IsTrue(e.value >= 1 && e.value <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            Assert::AreEqual(e.key, e.value);
            Assert::IsTrue(e.value >= 1 && e.value <= n);
            count++;
         }

         Assert::AreEqual(n, count);
      }

      template <class TObj, class TMap>
      void TestNumericToObjectMap(int const n)
      {
         std::vector<TObj*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new TObj(i + 1));
         }

         TMap map;
         for (auto o : objects)
         {
            auto v = (int)*o;
            map[static_cast<WORD>(v)] = o;
         }

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(*(TObj*)e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(*(TObj*)e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto p : objects)
            delete p;
      }

      template <class TObj, class TMap>
      void TestStringToObjectMap(int const n)
      {
         std::vector<TObj*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new TObj(i + 1));
         }

         TMap map;
         for (auto o : objects)
         {
            auto v = (int)*o;
            CString str; str.Format(L"element_%d", v);
            map[str] = o;
         }

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(*(TObj*)e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(*(TObj*)e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto p : objects)
            delete p;
      }

      void TestStringToStringMap(int const n)
      {
         CMapStringToString map;
         for (int i = 0; i < n; ++i)
         {
            CString str; str.Format(L"%d", i);
            map[str] = str;
         }

         int count = 0;
         for (auto e : map)
         {
            Assert::AreEqual(e.key, e.value);
            count++;
         }

         Assert::AreEqual(n, count);

         CMapStringToString const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            Assert::AreEqual(e.key, e.value);
            count++;
         }

         Assert::AreEqual(n, count);
      }

      template <class TObj, class TMap>
      void TestObjectToNumericMap(int const n)
      {
         std::vector<TObj*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new TObj(i + 1));
         }

         TMap map;
         for (auto o : objects)
         {
            auto v = (int)*o;
            map[o] = v;
         }

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(*(TObj*)e.key);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(*(TObj*)e.key);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto p : objects)
            delete p;
      }

      template <class TObj, class TMap>
      void TestObjectToObjectMap(int const n)
      {
         std::vector<TObj*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new TObj(i + 1));
         }

         TMap map;
         for (auto o : objects)
         {
            map[o] = o;
         }

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(*(TObj*)e.key);
            Assert::IsTrue(v >= 1 && v <= n);
            Assert::AreEqual(e.key, e.value);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(*(TObj*)e.key);
            Assert::IsTrue(v >= 1 && v <= n);
            Assert::AreEqual(e.key, e.value);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto p : objects)
            delete p;
      }

      template <class TObj, class TMap>
      void TestNumericToObjectTypedMap(int const n)
      {
         std::vector<TObj*> objects;
         for (int i = 0; i < n; ++i)
         {
            objects.push_back(new TObj(i + 1));
         }

         TMap map;
         for (auto o : objects)
         {
            auto v = (int)*o;
            map[static_cast<WORD>(v)] = o;
         }

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(*e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(*e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         for (auto p : objects)
            delete p;
      }

   public:
      TEST_METHOD(TestMap_Empty)
      {
         TestNumericMap<int, CMap<int, int, int, int>>(0);
      }

      TEST_METHOD(TestMap_One)
      {
         TestNumericMap<int, CMap<int, int, int, int>>(1);
      }

      TEST_METHOD(TestMap_Many)
      {
         TestNumericMap<int, CMap<int, int, int, int>>(10);
      }

      TEST_METHOD(TestWordToObMap_Empty)
      {
         TestNumericToObjectMap<IntObject, CMapWordToOb>(0);
      }

      TEST_METHOD(TestWordToObMap_One)
      {
         TestNumericToObjectMap<IntObject, CMapWordToOb>(1);
      }

      TEST_METHOD(TestWordToObMap_Many)
      {
         TestNumericToObjectMap<IntObject, CMapWordToOb>(10);
      }

      TEST_METHOD(TestWordToPtrMap_Empty)
      {
         TestNumericToObjectMap<IntObject, CMapWordToPtr>(0);
      }

      TEST_METHOD(TestWordToPtrMap_One)
      {
         TestNumericToObjectMap<IntObject, CMapWordToPtr>(1);
      }

      TEST_METHOD(TestWordToPtrMap_Many)
      {
         TestNumericToObjectMap<IntObject, CMapWordToPtr>(10);
      }

      TEST_METHOD(TestStringToObMap_Empty)
      {
         TestStringToObjectMap<IntObject, CMapStringToOb>(0);
      }

      TEST_METHOD(TestStringToObMap_One)
      {
         TestStringToObjectMap<IntObject, CMapStringToOb>(1);
      }

      TEST_METHOD(TestStringToObMap_Many)
      {
         TestStringToObjectMap<IntObject, CMapStringToOb>(10);
      }

      TEST_METHOD(TestStringToPtrMap_Empty)
      {
         TestStringToObjectMap<IntObject, CMapStringToPtr>(0);
      }

      TEST_METHOD(TestStringToPtrMap_One)
      {
         TestStringToObjectMap<IntObject, CMapStringToPtr>(1);
      }

      TEST_METHOD(TestStringToPtrMap_Many)
      {
         TestStringToObjectMap<IntObject, CMapStringToPtr>(10);
      }

      TEST_METHOD(TestMapStringToString_Empty)
      {
         TestStringToStringMap(0);
      }

      TEST_METHOD(TestMapStringToString_One)
      {
         TestStringToStringMap(1);
      }

      TEST_METHOD(TestMapStringToString_Many)
      {
         TestStringToStringMap(10);
      }

      TEST_METHOD(TestPtrToWordMap_Empty)
      {
         TestObjectToNumericMap<IntObject, CMapPtrToWord>(0);
      }

      TEST_METHOD(TestPtrToWordMap_One)
      {
         TestObjectToNumericMap<IntObject, CMapPtrToWord>(1);
      }

      TEST_METHOD(TestPtrToWordMap_Many)
      {
         TestObjectToNumericMap<IntObject, CMapPtrToWord>(10);
      }

      TEST_METHOD(TestPtrToPtrMap_Empty)
      {
         TestObjectToObjectMap<IntObject, CMapPtrToPtr>(0);
      }

      TEST_METHOD(TestPtrToPtrMap_One)
      {
         TestObjectToObjectMap<IntObject, CMapPtrToPtr>(1);
      }

      TEST_METHOD(TestPtrToPtrMap_Many)
      {
         TestObjectToObjectMap<IntObject, CMapPtrToPtr>(10);
      }

      TEST_METHOD(TestTypedWordToObMap_Empty)
      {
         TestNumericToObjectTypedMap<IntObject, CTypedPtrMap<CMapWordToPtr, WORD, IntObject*>>(0);
      }

      TEST_METHOD(TestTypedWordToObMap_One)
      {
         TestNumericToObjectTypedMap<IntObject, CTypedPtrMap<CMapWordToPtr, WORD, IntObject*>>(1);
      }

      TEST_METHOD(TestTypedWordToObMap_Many)
      {
         TestNumericToObjectTypedMap<IntObject, CTypedPtrMap<CMapWordToPtr, WORD, IntObject*>>(10);
      }
   };
}