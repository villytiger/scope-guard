
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include <utility>

#include "detail/macro.h"

#define SCOPE_EXIT(...) \
	auto VT_SCOPE_GUARD_VARIABLE(scopeExit) = vt::scopeGuard::detail::ScopeExitProducer() << [__VA_ARGS__]()

namespace vt {
namespace scopeGuard {
namespace detail {

template<typename T>
class ScopeExit {
public:
	ScopeExit(T&& action)
		: mAction(std::forward<T>(action))
	{}

	~ScopeExit() {
		VT_SCOPE_GUARD_WRAP_ACTION(mAction);
	}

private:
	T mAction;
};

class ScopeExitProducer {
public:
	template<typename T>
	ScopeExit<T> operator<<(T&& action) {
		return ScopeExit<T>(std::forward<T>(action));
	}
};

}
}
}
