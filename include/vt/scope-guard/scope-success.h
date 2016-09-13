
//          Copyright Ilya Lyubimov 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#include "detail/platform.h"


#ifdef VT_SCOPE_GUARD_SUPPORT_UNCAUGHT_EXCEPTIONS

#include <utility>

#include "detail/macro.h"


#define SCOPE_SUCCESS(...) \
	auto VT_SCOPE_GUARD_VARIABLE(scopeSuccess) = vt::scopeGuard::detail::ScopeSuccessProducer() << [__VA_ARGS__]()

namespace vt {
namespace scopeGuard {
namespace detail {

template<typename T>
class ScopeSuccess {
public:
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
	T mAction;
};

class ScopeSuccessProducer {
public:
	template<typename T>
	ScopeSuccess<T> operator<<(T&& action) {
		return ScopeSuccess<T>(std::forward<T>(action));
	}
};

}
}
}


#else


#ifdef VT_SCOPE_GUARD_PRAGMA_ERROR
#define SCOPE_SUCCESS(...) VT_SCOPE_GUARD_PRAGMA_ERROR("std::uncaught_exceptions is not supported by compiler")
#endif


#endif
