# MFC Collection Utilities
This is a small library that enables developers to use MFC containers (arrays, lists, maps) with range-based for loops. The library consists of a single header that you include in your MFC projects.

## How to use it

To be able to use the MFC containers in range-based for loops include the `mfciterators.h` header.

The following sample shows how to iterate over a `CStringArray` using range-based for loops.

```
#include "mfciterators.h"

void func(CStringArray const & arr)
{
   for(auto const & str : arr)
   {
      // do something with str
   }
}
```

For maps you get access to the content through a key-value pair that has two fields: key and value.

The following example shows how to iterate through a `CMap<int, CString>`.

```
#include "mfciterators.h"

CMap<int, CString> map;
map.SetAt(1, "one");
map.SetAt(2, "two");
map.SetAt(3, "three");
for(auto const & kvp : map)
{
   // do something with the key-value pair
   TRACE("%d-%s\n", kvp.key, kvp.value);
}
```

## Motivation
C++11 added support for range-based for loops. They allow iterating over the elements of a range without an index.

```
std::vector<int> v = {1, 2, 3, 4, 5};
for(auto& e : v)
  e *= 2;
```

However, if you try the above with MFC containers you get some errors because the compiler is looking for a `begin()` and `end()` function that provides access to the first and last element of the range:

```
1>error C3312: no callable 'begin' function found for type 'CStringArray'
1>error C3312: no callable 'end' function found for type 'CStringArray'
```

MFC does not define such functions for its containers. The MFC Collections Utilities libraries provides this for all MFC containers.

## Supported containers
Template collections

| Arrays | Lists | Maps |
| ------ | ----- | ---- |
| CArray | CList | CMap |
| CTypedPtrArray | CTypedPtrList | CTypedPtrMap |

Non-template collections

| Arrays | Lists | Maps |
| ------ | ----- | ---- |
| CObArray | CObList | CMapPtrToWord |
| CByteArray | CPtrList | CMapPtrToPtr |
| CDWordArray | CStringList | CMapStringToOb |
| CPtrArray | | CMapStringToPtr |
| CStringArray | | CMapStringToString |
| CWordArray |  | CMapWordToOb |
| CUIntArray |  | CMapWordToPtr |

## Compiler support
The library requires Visual Studio 2012 or a newer version.

## More examples

**Arrays**
```
CStringArray arr;
arr.Add("this");
arr.Add("is");
arr.Add("a");
arr.Add("sample");

for(auto & s : arr)
{
   s.MakeUpper();
}
```
```
CArray<int> arr;
arr.Add(1);
arr.Add(2);
arr.Add(3);
arr.Add(4);

for(auto const n : arr)
{
   std::cout << n << std::endl;
}
```

**Lists**
```
class CFoo
{
public:
   int value;

   CFoo(int const v): value(v) {}
};

CTypedPtrList<CPtrList, CFoo*> ptrlist;
ptrlist.AddTail(new CFoo(1));
ptrlist.AddTail(new CFoo(2));
ptrlist.AddTail(new CFoo(3));

for(auto & o : ptrlist)
   o->value *= 2;
```
```
CList<int> list;
list.AddTail(1);
list.AddTail(2);
list.AddTail(3);

auto const & clist = list;
for(auto const n : clist)
{
   std::cout << n << std::endl;
}
```

**Maps**
```
CMap<int, int, CString, CString> map;

map.SetAt(1, "one");
map.SetAt(2, "two");
map.SetAt(3, "three");

for(auto & kvp : map)
{
   kvp.value.MakeUpper();
}

for(auto const & kvp : map)
{
   CString temp;
   temp.Format("key=%d, value=%s", kvp.key, kvp.value);
}
```
```
CTypedPtrMap<CMapWordToPtr, WORD, CFoo*> map;

map.SetAt(1, new CFoo(1));
map.SetAt(2, new CFoo(2));
map.SetAt(3, new CFoo(3));

// do something with map

for(auto & kvp : map)
{
   delete kvp.value;
}
```
