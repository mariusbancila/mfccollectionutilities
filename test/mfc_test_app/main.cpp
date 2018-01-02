#include <SDKDDKVer.h>
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>

#include <iostream>

#include "..\..\include\mfciterators.h"

class CFoo
{
public:
   int value;

   explicit CFoo(int const v) noexcept : value(v) {}
};

int main()
{
   {
      CStringArray arr;
      arr.Add("this");
      arr.Add("is");
      arr.Add("a");
      arr.Add("sample");

      for (auto & s : arr)
      {
         s.MakeUpper();
      }
   }

   {
      CArray<int> arr;
      arr.Add(1);
      arr.Add(2);
      arr.Add(3);
      arr.Add(4);

      for (auto const n : arr)
      {
         std::cout << n << std::endl;
      }
   }

   {
      CTypedPtrList<CPtrList, CFoo*> ptrlist;
      ptrlist.AddTail(new CFoo(1));
      ptrlist.AddTail(new CFoo(2));
      ptrlist.AddTail(new CFoo(3));

      for (auto & o : ptrlist)
         o->value *= 2;

      for (auto & o : ptrlist)
         delete o;
   }

   {
      CList<int> list;
      list.AddTail(1);
      list.AddTail(2);
      list.AddTail(3);

      auto const & clist = list;
      for (auto const n : clist)
      {
         std::cout << n << std::endl;
      }
   }

   {
      CMap<int, int, CString, CString> map;

      map.SetAt(1, "one");
      map.SetAt(2, "two");
      map.SetAt(3, "three");

      for (auto & kvp : map)
      {
         kvp.value.MakeUpper();
      }

      for (auto const & kvp : map)
      {
         CString temp;
         temp.Format("key=%d, value=%s", kvp.key, kvp.value);
      }
   }

   {
      CTypedPtrMap<CMapWordToPtr, WORD, CFoo*> map;

      map.SetAt(1, new CFoo(1));
      map.SetAt(2, new CFoo(2));
      map.SetAt(3, new CFoo(3));

      // do something with map

      for (auto & kvp : map)
      {
         delete kvp.value;
      }
   }
}