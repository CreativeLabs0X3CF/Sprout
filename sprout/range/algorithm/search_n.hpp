#ifndef SPROUT_RANGE_ALGORITHM_SEARCH_N_HPP
#define SPROUT_RANGE_ALGORITHM_SEARCH_N_HPP

#include <sprout/config.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/utility/forward.hpp>
#include <sprout/range/range_return.hpp>
#include <sprout/algorithm/search_n.hpp>

namespace sprout {
	namespace range {
		// Copyright (C) 2011 RiSK (sscrisk)

		// 25.2.13 Search
		template<typename ForwardRange, typename Size, typename T>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange>::type
		search_n(ForwardRange&& range, Size count, T const& value) {
			return sprout::range::range_return<ForwardRange>::pack(
				sprout::search_n(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					count,
					value
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<typename ForwardRange, typename Size, typename T, typename BinaryPredicate>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange>::type
		search_n(ForwardRange&& range, Size count, T const& value, BinaryPredicate pred) {
			return sprout::range::range_return<ForwardRange>::pack(
				sprout::search_n(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					count,
					value,
					pred
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<sprout::range::range_return_value RetV, typename ForwardRange, typename Size, typename T>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange, RetV>::type
		search_n(ForwardRange&& range, Size count, T const& value) {
			return sprout::range::range_return<ForwardRange, RetV>::pack(
				sprout::search_n(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					count,
					value
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<sprout::range::range_return_value RetV, typename ForwardRange, typename Size, typename T, typename BinaryPredicate>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange, RetV>::type
		search_n(ForwardRange&& range, Size count, T const& value, BinaryPredicate pred) {
			return sprout::range::range_return<ForwardRange, RetV>::pack(
				sprout::search_n(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					count,
					value,
					pred
					),
				sprout::forward<ForwardRange>(range)
				);
		}
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_SEARCH_N_HPP
