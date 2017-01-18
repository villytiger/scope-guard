
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if defined(_MSC_VER) && _MSC_VER >= 1900

#if !defined(VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS)

#define VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS 1

inline int uncaughtExceptions() {
	return std::uncaught_exceptions();
}

#endif

#endif
