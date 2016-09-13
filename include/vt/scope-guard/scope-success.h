
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

#define SCOPE_SUCCESS(...) \
	vt::scopeGuard::detail::ScopeSuccess VT_SCOPE_GUARD_VARIABLE(scopeSuccess) = [__VA_ARGS__]()

namespace vt {
namespace scopeGuard {
namespace detail {

class ScopeSuccess {
public:
	ScopeSuccess(ScopeSuccess&) = delete;
	ScopeSuccess& operator=(ScopeSuccess&) = delete;
	ScopeSuccess(ScopeSuccess&& other) = default;
	ScopeSuccess& operator=(ScopeSuccess&&) = default;

	template<typename T>
	ScopeSuccess(T&& action)
		: mExceptionCount(std::uncaught_exceptions())
		, mAction(std::forward<T>(action))
	{}

	~ScopeSuccess() {
		if (std::uncaught_exceptions() == mExceptionCount)
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

#include "detail/platform.h"

#ifdef VT_SCOPE_GUARD_PRAGMA_ERROR
#define SCOPE_SUCCESS(...) VT_SCOPE_GUARD_PRAGMA_ERROR("std::uncaught_exceptions is not supported by compiler")
#endif

#endif
