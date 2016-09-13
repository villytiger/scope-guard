#pragma once

#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411
#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1
#endif

#if defined(_MSC_VER) && _MSC_VER >= 1900
#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1
#endif

#if defined(__GNUC__)
#define VT_SCOPE_GUARD_PRAGMA(str) _Pragma (#str)
#define VT_SCOPE_GUARD_PRAGMA_ERROR(str) VT_SCOPE_GUARD_PRAGMA(GCC error str)
#endif
