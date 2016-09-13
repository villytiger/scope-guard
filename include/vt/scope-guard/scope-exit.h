
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <functional>
#include <utility>

#include "detail/macro.h"
#include "detail/platform.h"

#define SCOPE_EXIT(...) \
	vt::scopeGuard::detail::ScopeExit VT_SCOPE_GUARD_VARIABLE(scopeExit) = [__VA_ARGS__]()

namespace vt {
namespace scopeGuard {
namespace detail {

class ScopeExit {
public:
#ifndef VT_SCOPE_GUARD_NO_SUPPORT_DEFAULT_DELETE
	ScopeExit(ScopeExit&) = delete;
	ScopeExit& operator=(ScopeExit&) = delete;
	ScopeExit(ScopeExit&& other) = default;
	ScopeExit& operator=(ScopeExit&&) = default;
#endif

	template<typename T>
	ScopeExit(T&& action)
		: mAction(std::forward<T>(action))
	{}

	~ScopeExit() {
		VT_SCOPE_GUARD_WRAP_ACTION(mAction);
	}

private:
	std::function<void()> mAction;
};

}
}
}
