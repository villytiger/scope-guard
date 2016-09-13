#pragma once

#include <exception>


#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411
#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1
#endif


#ifdef _MSC_VER

#if _MSC_VER >= 1900
#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1
#endif

#endif // _MSC_VER


#if defined(__GNUC__)
#define VT_SCOPE_GUARD_PRAGMA(str) _Pragma (#str)
#define VT_SCOPE_GUARD_PRAGMA_ERROR(str) VT_SCOPE_GUARD_PRAGMA(GCC error str)
#endif
