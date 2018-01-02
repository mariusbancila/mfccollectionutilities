// ----------------------------------------------------------------------------
// MFC Collection Utilities
// https://github.com/mariusbancila/mfccollectionutilities
// GNU General Public License v3.0 https://github.com/mariusbancila/mfccollectionutilities/blob/master/LICENSE
// Copyright Tom Kirby-Green, Marius Bancila 2014-2018
// ----------------------------------------------------------------------------

#pragma once

#pragma region array iterators

template<typename T, typename TArg = T const &>
class CArrayIterator
{
public:
   explicit CArrayIterator(CArray<T, TArg>& collection, INT_PTR const index) noexcept :
      m_index(index),
      m_collection(collection)
   {}

   bool operator!= (CArrayIterator const & other) const noexcept
   {
      return m_index != other.m_index;
   }

   T& operator* () const
   {
      return m_collection[m_index];
   }

   CArrayIterator<T, TArg> const & operator++ ()
   {
      ++m_index;
      return *this;
   }

private:
   INT_PTR           m_index;
   CArray<T, TArg>&  m_collection;
};

template<typename T, typename TArg = T const &>
class CArrayConstIterator
{
public:
   explicit CArrayConstIterator(CArray<T, TArg> const & collection, INT_PTR const index) noexcept :
      m_index(index),
      m_collection(collection)
   {
   }

   bool operator!= (CArrayConstIterator<T, TArg> const & other) const noexcept
   {
      return m_index != other.m_index;
   }

   T const & operator* () const
   {
      return m_collection[m_index];
   }

   CArrayConstIterator<T, TArg> const & operator++ ()
   {
      ++m_index;
      return *this;
   }

private:
   INT_PTR                 m_index;
   CArray<T, TArg> const & m_collection;
};

template <typename A, typename T>
class CTypeArrayIterator
{
public:
   explicit CTypeArrayIterator(A& collection, INT_PTR const index) noexcept :
      m_index(index),
      m_collection(collection)
   {
   }

   bool operator!= (CTypeArrayIterator<A, T> const & other) const noexcept
   {
      return m_index != other.m_index;
   }

   T& operator* () const
   {
      return m_collection[m_index];
   }

   CTypeArrayIterator<A, T> const & operator++ ()
   {
      ++m_index;
      return *this;
   }

private:
   INT_PTR  m_index;
   A&       m_collection;
};

template <typename A, typename T>
class CTypeArrayConstIterator
{
public:
   explicit CTypeArrayConstIterator(A const & collection, INT_PTR const index) noexcept :
      m_index(index),
      m_collection(collection)
   {
   }

   bool operator!= (CTypeArrayConstIterator<A, T> const & other) const noexcept
   {
      return m_index != other.m_index;
   }

   T const operator* () const
   {
      return m_collection[m_index];
   }

   CTypeArrayConstIterator<A, T> const & operator++ ()
   {
      ++m_index;
      return *this;
   }

private:
   INT_PTR     m_index;
   A const &   m_collection;
};

#pragma endregion

#pragma region list iterators

template<typename T, typename TArg = T const &>
class CListIterator
{
public:
   explicit CListIterator(CList<T, TArg>& collection, POSITION const pos) noexcept :
      m_value(nullptr),
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CListIterator<T, TArg>& other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   T& operator* ()
   {
      m_value = &m_collection.GetAt(m_pos);
      return *m_value;
   }

   CListIterator<T, TArg> const & operator++ ()
   {
      m_collection.GetNext(m_pos);
      return *this;
   }

private:
   T*                m_value;
   POSITION          m_pos;
   CList<T, TArg>&   m_collection;
};

template<typename T, typename TArg = T const &>
class CListConstIterator
{
public:
   explicit CListConstIterator(CList<T, TArg> const & collection, POSITION const pos) noexcept :
      m_value(nullptr),
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CListConstIterator<T, TArg> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   T const & operator* () const
   {
      m_value = &m_collection.GetAt(m_pos);
      return *m_value;
   }

   CListConstIterator<T, TArg> const & operator++ ()
   {
      static_cast<void>(m_collection.GetNext(m_pos));
      return *this;
   }

private:
   mutable const T*        m_value;
   POSITION                m_pos;
   CList<T, TArg> const &  m_collection;
};

template <typename L, typename T>
class CTypeListIterator
{
public:
   explicit CTypeListIterator(L& collection, POSITION const pos) noexcept :
      m_value(nullptr),
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CTypeListIterator<L, T> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   T& operator* ()
   {
      m_value = &m_collection.GetAt(m_pos);
      return *m_value;
   }

   CTypeListIterator<L, T> const & operator++ ()
   {
      m_collection.GetNext(m_pos);
      return *this;
   }

private:
   T*       m_value;
   POSITION m_pos;
   L&       m_collection;
};


template <typename L, typename T>
class CTypeListConstIterator
{
public:
   explicit CTypeListConstIterator(L const & collection, POSITION const pos) noexcept :
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CTypeListConstIterator<L, T> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   T operator* () const
   {
      return m_collection.GetAt(m_pos);
   }

   CTypeListConstIterator<L, T> const & operator++ ()
   {
      m_collection.GetNext(m_pos);
      return *this;
   }

private:
   POSITION          m_pos;
   L const &         m_collection;
};

#pragma endregion

#pragma region map iterators

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
class CMapIterator
{
public:
   explicit CMapIterator(CMap<TKey, TKeyArg, TValue, TValueArg>& collection, typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair* pos) noexcept :
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CMapIterator<TKey, TKeyArg, TValue, TValueArg> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair& operator* () const
   {
      return *m_pos;
   }

   CMapIterator<TKey, TKeyArg, TValue, TValueArg> const & operator++ ()
   {
      m_pos = m_collection.PGetNextAssoc(m_pos);
      return *this;
   }

private:
   typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair* m_pos;
   CMap<TKey, TKeyArg, TValue, TValueArg>&                 m_collection;
};

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
class CMapConstIterator
{
public:
   explicit CMapConstIterator(
      CMap<TKey, TKeyArg, TValue, TValueArg> const & collection, 
      typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair const * pos) noexcept :
      m_pos(pos),
      m_collection(collection)
   {
   }

   bool operator!= (CMapConstIterator<TKey, TKeyArg, TValue, TValueArg> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair const & operator* () const
   {
      return *m_pos;
   }

   CMapConstIterator<TKey, TKeyArg, TValue, TValueArg> const & operator++ ()
   {
      m_pos = m_collection.PGetNextAssoc(m_pos);
      return *this;
   }

private:
   mutable typename CMap<TKey, TKeyArg, TValue, TValueArg>::CPair const * m_pos;
   CMap<TKey, TKeyArg, TValue, TValueArg> const &                         m_collection;
};

template <typename TKey, typename TValue>
struct CMapPair
{
   TKey     key;
   TValue   value;
};

POSITION const PAST_END_POSITION = reinterpret_cast<POSITION>(-2L);

template<typename M, typename TKey, typename TValue>
class CTypeMapIterator
{
public:
   explicit CTypeMapIterator(M& collection, POSITION const pos) noexcept :
      m_collection(collection),
      m_pos(pos)
   {
      if(pos == BEFORE_START_POSITION)
         m_collection.GetNextAssoc(m_pos, m_value.key, m_value.value);
   }

   bool operator!= (CTypeMapIterator<M, TKey, TValue> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   CMapPair<TKey, TValue>& operator* () noexcept
   {
      return m_value;
   }

   CTypeMapIterator<M, TKey, TValue> const & operator++ ()
   {
      if(m_pos == nullptr)
         m_pos = PAST_END_POSITION;
      else if(m_pos != PAST_END_POSITION)
         m_collection.GetNextAssoc(m_pos, m_value.key, m_value.value);

      return *this;
   }
private:
   POSITION                m_pos;
   M&                      m_collection;
   CMapPair<TKey, TValue>  m_value;
};

template<typename M, typename TKey, typename TValue>
class CTypeMapConstIterator
{
public:
   explicit CTypeMapConstIterator(M const & collection, POSITION const pos) noexcept :
      m_collection(collection),
      m_pos(pos)
   {
      if(pos == BEFORE_START_POSITION)
         m_collection.GetNextAssoc(m_pos, m_value.key, m_value.value);
   }

   bool operator!= (CTypeMapConstIterator<M, TKey, TValue> const & other) const noexcept
   {
      return m_pos != other.m_pos;
   }

   CMapPair<TKey, TValue> const & operator* () const noexcept
   {
      return m_value;
   }

   CTypeMapConstIterator<M, TKey, TValue> const & operator++ ()
   {
      if(m_pos == nullptr)
         m_pos = PAST_END_POSITION;
      else if(m_pos != PAST_END_POSITION)
         m_collection.GetNextAssoc(m_pos, m_value.key, m_value.value);

      return *this;
   }
private:
   POSITION                m_pos;
   M const&                m_collection;
   CMapPair<TKey, TValue>  m_value;
};

#pragma endregion

#pragma region array functions

// CArray<T, TArg>
template<typename T, typename TArg>
inline CArrayIterator<T, TArg> begin(CArray<T, TArg>& collection)
{
   return CArrayIterator<T, TArg>(collection, 0);
}

template<typename T, typename TArg>
inline CArrayIterator<T, TArg> end(CArray<T, TArg>& collection)
{
   return CArrayIterator<T, TArg>(collection, collection.GetCount());
}

template<typename T, typename TArg>
inline CArrayConstIterator<T, TArg> begin(CArray<T, TArg> const & collection)
{
   return CArrayConstIterator<T, TArg>(collection, 0);
}

template<typename T, typename TArg>
inline CArrayConstIterator<T, TArg> end(CArray<T, TArg> const & collection)
{
   return CArrayConstIterator<T, TArg>(collection, collection.GetCount());
}

// CTypedPtrArray<CObArray, T>

template <class T>
inline CTypeArrayIterator<CTypedPtrArray<CObArray, T>, T> begin(CTypedPtrArray<CObArray, T>& collection)
{
   return CTypeArrayIterator<CTypedPtrArray<CObArray, T>, T>(collection, 0);
}

template <class T>
inline CTypeArrayIterator<CTypedPtrArray<CObArray, T>, T> end(CTypedPtrArray<CObArray, T>& collection)
{
   return CTypeArrayIterator<CTypedPtrArray<CObArray, T>, T>(collection, collection.GetCount());
}

template <class T>
inline CTypeArrayConstIterator<CTypedPtrArray<CObArray, T>, T> begin(CTypedPtrArray<CObArray, T> const & collection)
{
   return CTypeArrayConstIterator<CTypedPtrArray<CObArray, T>, T>(collection, 0);
}

template <class T>
inline CTypeArrayConstIterator<CTypedPtrArray<CObArray, T>, T> end(CTypedPtrArray<CObArray, T> const & collection)
{
   return CTypeArrayConstIterator<CTypedPtrArray<CObArray, T>, T>(collection, collection.GetCount());
}

// CTypedPtrArray<CPtrArray, T>

template <typename T>
inline CTypeArrayIterator<CTypedPtrArray<CPtrArray, T>, T> begin(CTypedPtrArray<CPtrArray, T>& collection)
{
   return CTypeArrayIterator<CTypedPtrArray<CPtrArray, T>, T>(collection, 0);
}

template <typename T>
inline CTypeArrayIterator<CTypedPtrArray<CPtrArray, T>, T> end(CTypedPtrArray<CPtrArray, T>& collection)
{
   return CTypeArrayIterator<CTypedPtrArray<CPtrArray, T>, T>(collection, collection.GetCount());
}

template <typename T>
inline CTypeArrayConstIterator<CTypedPtrArray<CPtrArray, T>, T> begin(CTypedPtrArray<CPtrArray, T> const & collection)
{
   return CTypeArrayConstIterator<CTypedPtrArray<CPtrArray, T>, T>(collection, 0);
}

template <typename T>
inline CTypeArrayConstIterator<CTypedPtrArray<CPtrArray, T>, T> end(CTypedPtrArray<CPtrArray, T> const & collection)
{
   return CTypeArrayConstIterator<CTypedPtrArray<CPtrArray, T>, T>(collection, collection.GetCount());
}

// CObArray

inline CTypeArrayIterator<CObArray, CObject*> begin(CObArray& collection)
{
   return CTypeArrayIterator<CObArray, CObject*>(collection, 0);
}

inline CTypeArrayIterator<CObArray, CObject*> end(CObArray& collection)
{
   return CTypeArrayIterator<CObArray, CObject*>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CObArray, CObject*> begin(CObArray const & collection)
{
   return CTypeArrayConstIterator<CObArray, CObject*>(collection, 0);
}

inline CTypeArrayConstIterator<CObArray, CObject*> end(CObArray const & collection)
{
   return CTypeArrayConstIterator<CObArray, CObject*>(collection, collection.GetCount());
}

// CByteArray

inline CTypeArrayIterator<CByteArray, BYTE> begin(CByteArray& collection)
{
   return CTypeArrayIterator<CByteArray, BYTE>(collection, 0);
}

inline CTypeArrayIterator<CByteArray, BYTE> end(CByteArray& collection)
{
   return CTypeArrayIterator<CByteArray, BYTE>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CByteArray, BYTE> begin(CByteArray const & collection)
{
   return CTypeArrayConstIterator<CByteArray, BYTE>(collection, 0);
}

inline CTypeArrayConstIterator<CByteArray, BYTE> end(CByteArray const & collection)
{
   return CTypeArrayConstIterator<CByteArray, BYTE>(collection, collection.GetCount());
}

// CDWordArray

inline CTypeArrayIterator<CDWordArray, DWORD> begin(CDWordArray& collection)
{
   return CTypeArrayIterator<CDWordArray, DWORD>(collection, 0);
}

inline CTypeArrayIterator<CDWordArray, DWORD> end(CDWordArray& collection)
{
   return CTypeArrayIterator<CDWordArray, DWORD>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CDWordArray, DWORD> begin(CDWordArray const & collection)
{
   return CTypeArrayConstIterator<CDWordArray, DWORD>(collection, 0);
}

inline CTypeArrayConstIterator<CDWordArray, DWORD> end(CDWordArray const & collection)
{
   return CTypeArrayConstIterator<CDWordArray, DWORD>(collection, collection.GetCount());
}

// CPtrArray

inline CTypeArrayIterator<CPtrArray, void*> begin(CPtrArray& collection)
{
   return CTypeArrayIterator<CPtrArray, void*>(collection, 0);
}

inline CTypeArrayIterator<CPtrArray, void*> end(CPtrArray& collection)
{
   return CTypeArrayIterator<CPtrArray, void*>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CPtrArray, void*> begin(CPtrArray const & collection)
{
   return CTypeArrayConstIterator<CPtrArray, void*>(collection, 0);
}

inline CTypeArrayConstIterator<CPtrArray, void*> end(CPtrArray const & collection)
{
   return CTypeArrayConstIterator<CPtrArray, void*>(collection, collection.GetCount());
}

// CStringArray

inline CTypeArrayIterator<CStringArray, CString> begin(CStringArray& collection)
{
   return CTypeArrayIterator<CStringArray, CString>(collection, 0);
}

inline CTypeArrayIterator<CStringArray, CString> end(CStringArray& collection)
{
   return CTypeArrayIterator<CStringArray, CString>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CStringArray, CString> begin(CStringArray const & collection)
{
   return CTypeArrayConstIterator<CStringArray, CString>(collection, 0);
}

inline CTypeArrayConstIterator<CStringArray, CString> end(CStringArray const & collection)
{
   return CTypeArrayConstIterator<CStringArray, CString>(collection, collection.GetCount());
}

// CWordArray

inline CTypeArrayIterator<CWordArray, WORD> begin(CWordArray& collection)
{
   return CTypeArrayIterator<CWordArray, WORD>(collection, 0);
}

inline CTypeArrayIterator<CWordArray, WORD> end(CWordArray& collection)
{
   return CTypeArrayIterator<CWordArray, WORD>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CWordArray, WORD> begin(CWordArray const & collection)
{
   return CTypeArrayConstIterator<CWordArray, WORD>(collection, 0);
}

inline CTypeArrayConstIterator<CWordArray, WORD> end(CWordArray const & collection)
{
   return CTypeArrayConstIterator<CWordArray, WORD>(collection, collection.GetCount());
}

// CUIntArray

inline CTypeArrayIterator<CUIntArray, UINT> begin(CUIntArray& collection)
{
   return CTypeArrayIterator<CUIntArray, UINT>(collection, 0);
}

inline CTypeArrayIterator<CUIntArray, UINT> end(CUIntArray& collection)
{
   return CTypeArrayIterator<CUIntArray, UINT>(collection, collection.GetCount());
}

inline CTypeArrayConstIterator<CUIntArray, UINT> begin(CUIntArray const & collection)
{
   return CTypeArrayConstIterator<CUIntArray, UINT>(collection, 0);
}

inline CTypeArrayConstIterator<CUIntArray, UINT> end(CUIntArray const & collection)
{
   return CTypeArrayConstIterator<CUIntArray, UINT>(collection, collection.GetCount());
}

#pragma endregion

#pragma region list functions

// CTypedPtrList<CObList, T>

template <class T>
inline CTypeListIterator<CTypedPtrList<CObList, T>, T> begin(CTypedPtrList<CObList, T>& collection)
{
   return CTypeListIterator<CTypedPtrList<CObList, T>, T>(collection, collection.GetHeadPosition());
}

template <class T>
inline CTypeListIterator<CTypedPtrList<CObList, T>, T> end(CTypedPtrList<CObList, T>& collection)
{
   return CTypeListIterator<CTypedPtrList<CObList, T>, T>(collection, nullptr);
}

template <class T>
inline CTypeListConstIterator<CTypedPtrList<CObList, T>, T> begin(CTypedPtrList<CObList, T> const & collection)
{
   return CTypeListConstIterator<CTypedPtrList<CObList, T>, T>(collection, collection.GetHeadPosition());
}

template <class T>
inline CTypeListConstIterator<CTypedPtrList<CObList, T>, T> end(CTypedPtrList<CObList, T> const & collection)
{
   return CTypeListConstIterator<CTypedPtrList<CObList, T>, T>(collection, nullptr);
}

// CTypedPtrList<CPtrList, T>

template <typename T>
inline CTypeListIterator<CTypedPtrList<CPtrList, T>, T> begin(CTypedPtrList<CPtrList, T>& collection)
{
   return CTypeListIterator<CTypedPtrList<CPtrList, T>, T>(collection, collection.GetHeadPosition());
}

template <typename T>
inline CTypeListIterator<CTypedPtrList<CPtrList, T>, T> end(CTypedPtrList<CPtrList, T>& collection)
{
   return CTypeListIterator<CTypedPtrList<CPtrList, T>, T>(collection, nullptr);
}

template <typename T>
inline CTypeListConstIterator<CTypedPtrList<CPtrList, T>, T> begin(CTypedPtrList<CPtrList, T> const & collection)
{
   return CTypeListConstIterator<CTypedPtrList<CPtrList, T>, T>(collection, collection.GetHeadPosition());
}

template <typename T>
inline CTypeListConstIterator<CTypedPtrList<CPtrList, T>, T> end(CTypedPtrList<CPtrList, T> const & collection)
{
   return CTypeListConstIterator<CTypedPtrList<CPtrList, T>, T>(collection, nullptr);
}

// CObList

inline CTypeListIterator<CObList, CObject*> begin(CObList& collection)
{
   return CTypeListIterator<CObList, CObject*>(collection, collection.GetHeadPosition());
}

inline CTypeListIterator<CObList, CObject*> end(CObList& collection)
{
   return CTypeListIterator<CObList, CObject*>(collection, nullptr);
}

inline CTypeListConstIterator<CObList, CObject const *> begin(CObList const & collection)
{
   return CTypeListConstIterator<CObList, CObject const *>(collection, collection.GetHeadPosition());
}

inline CTypeListConstIterator<CObList, CObject const *> end(CObList const & collection)
{
   return CTypeListConstIterator<CObList, CObject const *>(collection, nullptr);
}

// CPtrList

inline CTypeListIterator<CPtrList, void*> begin(CPtrList& collection)
{
   return CTypeListIterator<CPtrList, void*>(collection, collection.GetHeadPosition());
}

inline CTypeListIterator<CPtrList, void*> end(CPtrList& collection)
{
   return CTypeListIterator<CPtrList, void*>(collection, nullptr);
}

inline CTypeListConstIterator<CPtrList, void const *> begin(CPtrList const & collection)
{
   return CTypeListConstIterator<CPtrList, void const *>(collection, collection.GetHeadPosition());
}

inline CTypeListConstIterator<CPtrList, void const *> end(CPtrList const & collection)
{
   return CTypeListConstIterator<CPtrList, void const *>(collection, nullptr);
}

// CStringList

inline CTypeListIterator<CStringList, CString> begin(CStringList& collection)
{
   return CTypeListIterator<CStringList, CString>(collection, collection.GetHeadPosition());
}

inline CTypeListIterator<CStringList, CString> end(CStringList& collection)
{
   return CTypeListIterator<CStringList, CString>(collection, nullptr);
}

inline CTypeListConstIterator<CStringList, CString> begin(CStringList const & collection)
{
   return CTypeListConstIterator<CStringList, CString>(collection, collection.GetHeadPosition());
}

inline CTypeListConstIterator<CStringList, CString> end(CStringList const & collection)
{
   return CTypeListConstIterator<CStringList, CString>(collection, nullptr);
}

// CList<T, TArg>

template<typename T, typename TArg>
inline CListIterator<T, TArg> begin(CList<T, TArg>& collection)
{
   return CListIterator<T, TArg>(collection, collection.GetHeadPosition());
}

template<typename T, typename TArg>
inline CListIterator<T, TArg> end(CList<T, TArg>& collection)
{
   return CListIterator<T, TArg>(collection, nullptr);
}


template<typename T, typename TArg>
inline CListConstIterator<T, TArg> begin(CList<T, TArg> const & collection)
{
   return CListConstIterator<T, TArg>(collection, collection.GetHeadPosition());
}

template<typename T, typename TArg>
inline CListConstIterator<T, TArg> end(CList<T, TArg> const & collection)
{
   return CListConstIterator<T, TArg>(collection, nullptr);
}

#pragma endregion

#pragma region map functions

// CMap<TKey, TValue>

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
inline CMapIterator<TKey, TKeyArg, TValue, TValueArg> begin(CMap<TKey, TKeyArg, TValue, TValueArg>& collection)
{
   return CMapIterator<TKey, TKeyArg, TValue, TValueArg>(collection, collection.PGetFirstAssoc());
}

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
inline CMapIterator<TKey, TKeyArg, TValue, TValueArg> end(CMap<TKey, TKeyArg, TValue, TValueArg>& collection)
{
   return CMapIterator<TKey, TKeyArg, TValue, TValueArg>(collection, nullptr);
}

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
inline CMapConstIterator<TKey, TKeyArg, TValue, TValueArg> begin(CMap<TKey, TKeyArg, TValue, TValueArg> const & collection)
{
   return CMapConstIterator<TKey, TKeyArg, TValue, TValueArg>(collection, collection.PGetFirstAssoc());
}

template<typename TKey, typename TKeyArg, typename TValue, typename TValueArg>
inline CMapConstIterator<TKey, TKeyArg, TValue, TValueArg> end(CMap<TKey, TKeyArg, TValue, TValueArg> const & collection)
{
   return CMapConstIterator<TKey, TKeyArg, TValue, TValueArg>(collection, nullptr);
}

// CTypedPtrMap<CMapPtrToPtr, TKey, TValue>

template <typename TKey, typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue> begin(CTypedPtrMap<CMapPtrToPtr, TKey, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue>(collection, collection.GetStartPosition());
}

template <typename TKey, typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue> end(CTypedPtrMap<CMapPtrToPtr, TKey, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue>(collection, PAST_END_POSITION);
}

template <typename TKey, typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue> begin(CTypedPtrMap<CMapPtrToPtr, TKey, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue>(collection, collection.GetStartPosition());
}

template <typename TKey, typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue> end(CTypedPtrMap<CMapPtrToPtr, TKey, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapPtrToPtr, TKey, TValue>, TKey, TValue>(collection, PAST_END_POSITION);
}

// CTypedPtrMap<CMapPtrToWord, TKey, WORD>

template <typename TKey>
inline CTypeMapIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD> begin(CTypedPtrMap<CMapPtrToWord, TKey, WORD>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD>(collection, collection.GetStartPosition());
}

template <typename TKey>
inline CTypeMapIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD> end(CTypedPtrMap<CMapPtrToWord, TKey, WORD>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD>(collection, PAST_END_POSITION);
}

template <typename TKey>
inline CTypeMapConstIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD> begin(CTypedPtrMap<CMapPtrToWord, TKey, WORD> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD>(collection, collection.GetStartPosition());
}

template <typename TKey>
inline CTypeMapConstIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD> end(CTypedPtrMap<CMapPtrToWord, TKey, WORD> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapPtrToWord, TKey, WORD>, TKey, WORD>(collection, PAST_END_POSITION);
}

// CTypedPtrMap<CMapWordToPtr, WORD, TValue>

template <typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue> begin(CTypedPtrMap<CMapWordToPtr, WORD, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue>(collection, collection.GetStartPosition());
}

template <typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue> end(CTypedPtrMap<CMapWordToPtr, WORD, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue>(collection, PAST_END_POSITION);
}

template <typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue> begin(CTypedPtrMap<CMapWordToPtr, WORD, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue>(collection, collection.GetStartPosition());
}

template <typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue> end(CTypedPtrMap<CMapWordToPtr, WORD, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapWordToPtr, WORD, TValue>, WORD, TValue>(collection, PAST_END_POSITION);
}

// CTypedPtrMap<CMapStringToPtr, CString, TValue>

template <typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue> begin(CTypedPtrMap<CMapStringToPtr, CString, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue>(collection, collection.GetStartPosition());
}

template <typename TValue>
inline CTypeMapIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue> end(CTypedPtrMap<CMapStringToPtr, CString, TValue>& collection)
{
   return CTypeMapIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue>(collection, PAST_END_POSITION);
}

template <typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue> begin(CTypedPtrMap<CMapStringToPtr, CString, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue>(collection, collection.GetStartPosition());
}

template <typename TValue>
inline CTypeMapConstIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue> end(CTypedPtrMap<CMapStringToPtr, CString, TValue> const & collection)
{
   return CTypeMapConstIterator<CTypedPtrMap<CMapStringToPtr, CString, TValue>, CString, TValue>(collection, PAST_END_POSITION);
}

// CMapPtrToWord

inline CTypeMapIterator<CMapPtrToWord, void*, WORD> begin(CMapPtrToWord& collection)
{
   return CTypeMapIterator<CMapPtrToWord, void*, WORD>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapPtrToWord, void*, WORD> end(CMapPtrToWord& collection)
{
   return CTypeMapIterator<CMapPtrToWord, void*, WORD>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapPtrToWord, void*, WORD> begin(CMapPtrToWord const & collection)
{
   return CTypeMapConstIterator<CMapPtrToWord, void*, WORD>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapPtrToWord, void*, WORD> end(CMapPtrToWord const & collection)
{
   return CTypeMapConstIterator<CMapPtrToWord, void*, WORD>(collection, PAST_END_POSITION);
}

// CMapPtrToPtr

inline CTypeMapIterator<CMapPtrToPtr, void*, void*> begin(CMapPtrToPtr& collection)
{
   return CTypeMapIterator<CMapPtrToPtr, void*, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapPtrToPtr, void*, void*> end(CMapPtrToPtr& collection)
{
   return CTypeMapIterator<CMapPtrToPtr, void*, void*>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapPtrToPtr, void*, void*> begin(CMapPtrToPtr const & collection)
{
   return CTypeMapConstIterator<CMapPtrToPtr, void*, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapPtrToPtr, void*, void*> end(CMapPtrToPtr const & collection)
{
   return CTypeMapConstIterator<CMapPtrToPtr, void*, void*>(collection, PAST_END_POSITION);
}

// CMapStringToOb

inline CTypeMapIterator<CMapStringToOb, CString, CObject*> begin(CMapStringToOb& collection)
{
   return CTypeMapIterator<CMapStringToOb, CString, CObject*>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapStringToOb, CString, CObject*> end(CMapStringToOb& collection)
{
   return CTypeMapIterator<CMapStringToOb, CString, CObject*>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapStringToOb, CString, CObject*> begin(CMapStringToOb const & collection)
{
   return CTypeMapConstIterator<CMapStringToOb, CString, CObject*>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapStringToOb, CString, CObject*> end(CMapStringToOb const & collection)
{
   return CTypeMapConstIterator<CMapStringToOb, CString, CObject*>(collection, PAST_END_POSITION);
}

// CMapStringToPtr

inline CTypeMapIterator<CMapStringToPtr, CString, void*> begin(CMapStringToPtr& collection)
{
   return CTypeMapIterator<CMapStringToPtr, CString, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapStringToPtr, CString, void*> end(CMapStringToPtr& collection)
{
   return CTypeMapIterator<CMapStringToPtr, CString, void*>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapStringToPtr, CString, void*> begin(CMapStringToPtr const & collection)
{
   return CTypeMapConstIterator<CMapStringToPtr, CString, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapStringToPtr, CString, void*> end(CMapStringToPtr const & collection)
{
   return CTypeMapConstIterator<CMapStringToPtr, CString, void*>(collection, PAST_END_POSITION);
}

// CMapStringToString

inline CTypeMapIterator<CMapStringToString, CString, CString> begin(CMapStringToString& collection)
{
   return CTypeMapIterator<CMapStringToString, CString, CString>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapStringToString, CString, CString> end(CMapStringToString& collection)
{
   return CTypeMapIterator<CMapStringToString, CString, CString>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapStringToString, CString, CString> begin(CMapStringToString const & collection)
{
   return CTypeMapConstIterator<CMapStringToString, CString, CString>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapStringToString, CString, CString> end(CMapStringToString const & collection)
{
   return CTypeMapConstIterator<CMapStringToString, CString, CString>(collection, PAST_END_POSITION);
}

// CMapWordToOb

inline CTypeMapIterator<CMapWordToOb, WORD, CObject*> begin(CMapWordToOb& collection)
{
   return CTypeMapIterator<CMapWordToOb, WORD, CObject*>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapWordToOb, WORD, CObject*> end(CMapWordToOb& collection)
{
   return CTypeMapIterator<CMapWordToOb, WORD, CObject*>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapWordToOb, WORD, CObject*> begin(CMapWordToOb const & collection)
{
   return CTypeMapConstIterator<CMapWordToOb, WORD, CObject*>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapWordToOb, WORD, CObject*> end(CMapWordToOb const & collection)
{
   return CTypeMapConstIterator<CMapWordToOb, WORD, CObject*>(collection, PAST_END_POSITION);
}

// CMapWordToPtr

inline CTypeMapIterator<CMapWordToPtr, WORD, void*> begin(CMapWordToPtr& collection)
{
   return CTypeMapIterator<CMapWordToPtr, WORD, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapIterator<CMapWordToPtr, WORD, void*> end(CMapWordToPtr& collection)
{
   return CTypeMapIterator<CMapWordToPtr, WORD, void*>(collection, PAST_END_POSITION);
}

inline CTypeMapConstIterator<CMapWordToPtr, WORD, void*> begin(CMapWordToPtr const & collection)
{
   return CTypeMapConstIterator<CMapWordToPtr, WORD, void*>(collection, collection.GetStartPosition());
}

inline CTypeMapConstIterator<CMapWordToPtr, WORD, void*> end(CMapWordToPtr const & collection)
{
   return CTypeMapConstIterator<CMapWordToPtr, WORD, void*>(collection, PAST_END_POSITION);
}

#pragma endregion
