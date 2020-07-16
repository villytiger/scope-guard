
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <exception>


#if defined(__cpp_lib_uncaught_exceptions) && __cpp_lib_uncaught_exceptions >= 201411

#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1

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
