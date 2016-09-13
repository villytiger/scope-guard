
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#ifndef VT_SCOPE_GUARD_ON_STD_EXCEPTION
#include <iostream>
#define VT_SCOPE_GUARD_ON_STD_EXCEPTION(exception) \
	do { \
		std::cerr << e.what() << std::endl; \
	} while (false)
#endif // VT_SCOPE_GUARD_ON_STD_EXCEPTION

#ifndef VT_SCOPE_GUARD_ON_ANY_EXCEPTION
#include <iostream>
#define VT_SCOPE_GUARD_ON_ANY_EXCEPTION() \
	do { \
		std::cerr << "An error occured in scope guard" << std::endl; \
	} while (false)
#endif // VT_SCOPE_GUARD_ON_ANY_EXCEPTION

#ifndef VT_SCOPE_GUARD_WRAP_ACTION
#include <exception>
#define VT_SCOPE_GUARD_WRAP_ACTION(action) \
	do { \
		try { \
			action(); \
		} catch (const std::exception& e) { \
			try { \
				VT_SCOPE_GUARD_ON_STD_EXCEPTION(e); \
			} catch (...) { \
			} \
		} catch (...) { \
			try { \
				VT_SCOPE_GUARD_ON_ANY_EXCEPTION(); \
			} catch (...) { \
			} \
		} \
	} while (false)
#endif // VT_SCOPE_GUARD_WRAP_ACTION

#define VT_SCOPE_GUARD_DO_STRING_JOIN(arg1, arg2) arg1 ## arg2
#define VT_SCOPE_GUARD_STRING_JOIN(arg1, arg2) VT_SCOPE_GUARD_DO_STRING_JOIN(arg1, arg2)

#ifdef __COUNTER__
#define VT_SCOPE_GUARD_VARIABLE(arg) VT_SCOPE_GUARD_STRING_JOIN(arg, __COUNTER__)
#else
#define VT_SCOPE_GUARD_VARIABLE(arg) VT_SCOPE_GUARD_STRING_JOIN(arg, __LINE__)
#endif
