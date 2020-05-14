#pragma once

namespace Microsoft
{
   namespace VisualStudio
   {
      namespace CppUnitTestFramework
      {
         template<>
         static std::wstring ToString<WORD>(WORD const& value)
         {
            return std::to_wstring(static_cast<unsigned long>(value));
         }

         template<>
         static std::wstring ToString<CString>(CString const& value)
         {
            return std::wstring((LPCTSTR)value);
         }

         template<>
         static std::wstring ToString<IntObject>(IntObject* value)
         {
            return value == nullptr ? L"(null)" : std::to_wstring(value->value);
         }
      }
   }
}