#pragma once

struct IntObject : CObject
{
   int value;

   explicit IntObject(int const v) noexcept : value(v) {}

   explicit operator int()
   {
      return value;
   }
};