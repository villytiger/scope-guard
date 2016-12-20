
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if defined(__GNUC__)


#define VT_SCOPE_GUARD_PRAGMA(str) _Pragma (#str)
#define VT_SCOPE_GUARD_PRAGMA_ERROR(str) VT_SCOPE_GUARD_PRAGMA(GCC error str)


#if !defined(VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS)

#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1

namespace __cxxabiv1 {

struct __cxa_eh_globals {
	void* caughtExceptions;
	unsigned uncaughtExceptions;
};
	
extern "C" __cxa_eh_globals* __cxa_get_globals() throw();

}

namespace vt {
namespace scopeGuard {
namespace detail {

inline int uncaughtExceptions() {
	return __cxxabiv1::__cxa_get_globals()->uncaughtExceptions;
}
	
}
}
}

#endif


#endif

