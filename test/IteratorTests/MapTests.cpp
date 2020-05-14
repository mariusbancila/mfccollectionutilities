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
         for (auto o : objects) map[static_cast<WORD>((int)(*o))] = o;

         int count = 0;
         for (auto e : map)
         {
            auto v = (int)(e.value);
            Assert::IsTrue(v >= 1 && v <= n);
            count++;
         }

         Assert::AreEqual(n, count);

         TMap const& cmap = map;

         count = 0;
         for (auto e : cmap)
         {
            auto v = (int)(e.value);
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
   };
}