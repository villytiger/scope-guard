
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <exception>


#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411
#if defined(__APPLE__)

#include <Availability.h>

#if defined(__MAC_OS_X_VERSION_MIN_REQUIRED) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101200 \
	|| defined(__IPHONE_OS_VERSION_MIN_REQUIRED) && __IPHONE_OS_VERSION_MIN_REQUIRED >= 100000 \
	|| defined(__TV_OS_VERSION_MIN_REQUIRED) && __TV_OS_VERSION_MIN_REQUIRED >= 100000 \
	|| defined(__WATCH_OS_VERSION_MIN_REQUIRED) && __WATCH_OS_VERSION_MIN_REQUIRED >= 30000
#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1
#endif

#else

#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1

#endif
#endif


#if defined(VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS)

namespace vt {
namespace scopeGuard {
namespace detail {

inline int uncaughtExceptions() {
	return std::uncaught_exceptions();
}

} // namespace detail
} // namespace scopeGuard
} // namespace vt

#endif


#include "gcc.h"
#include "msvc.h"
