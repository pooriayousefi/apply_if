
#pragma once
#include <type_traits>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <execution>

namespace
{
	template<typename T>
	using arithmetic = std::enable_if_t<std::is_arithmetic_v<T>, T>;

	template<typename Iterator>
	using iter_value_t = typename std::iterator_traits<Iterator>::value_type;

	template<typename Iter, typename T = arithmetic<iter_value_t<Iter> >, typename F>
	auto apply(Iter beg, Iter end, F&& f)->void
	{
		if constexpr (std::is_invocable_v<F, T&>)
		{
			std::for_each(std::execution::seq,
				beg,
				end,
				[&](T & val) { std::forward<F>(f)(val); });
		}
	}

	template<typename Iter, typename T = arithmetic<iter_value_t<Iter> >, typename Pred, typename F>
	auto apply_if(Iter beg, Iter end, Pred&& pred, F&& f)->void
	{
		if constexpr (std::is_invocable_r_v<bool, Pred, const T&> && std::is_invocable_v<F, T&>)
		{
			std::for_each(std::execution::seq,
				beg,
				end,
				[&](T & val)
				{
					if (std::forward<Pred>(pred)(val))
						std::forward<F>(f)(val);
				});
		}
	}
}
