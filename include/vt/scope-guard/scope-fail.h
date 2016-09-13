
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <exception>

#include "detail/platform.h"

#ifdef VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS

#include <functional>
#include <utility>

#include "detail/macro.h"

#define SCOPE_FAIL(...) \
	vt::scopeGuard::detail::ScopeFail VT_SCOPE_GUARD_VARIABLE(scopeFail) = [__VA_ARGS__]()

namespace vt {
namespace scopeGuard {
namespace detail {

class ScopeFail {
public:
	ScopeFail(ScopeFail&) = delete;
	ScopeFail& operator=(ScopeFail&) = delete;
	ScopeFail(ScopeFail&& other) = default;
	ScopeFail& operator=(ScopeFail&&) = default;

	template<typename T>
	ScopeFail(T&& action)
		: mExceptionCount(std::uncaught_exceptions())
		, mAction(std::forward<T>(action))
	{}

	~ScopeFail() {
		if (std::uncaught_exceptions() > mExceptionCount)
			VT_SCOPE_GUARD_WRAP_ACTION(mAction);
	}

private:
	int mExceptionCount;
	std::function<void()> mAction;
};

}
}
}

#else

#ifdef VT_SCOPE_GUARD_PRAGMA_ERROR
#define SCOPE_FAIL(...) VT_SCOPE_GUARD_PRAGMA_ERROR("std::uncaught_exceptions is not supported by compiler")
#endif

#endif
