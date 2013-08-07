#ifndef SPROUT_RANGE_ALGORITHM_ADJACENT_FIND_HPP
#define SPROUT_RANGE_ALGORITHM_ADJACENT_FIND_HPP

#include <sprout/config.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/utility/forward.hpp>
#include <sprout/range/range_return.hpp>
#include <sprout/algorithm/adjacent_find.hpp>

namespace sprout {
	namespace range {
		// Copyright (C) 2011 RiSK (sscrisk)

		// 25.2.8 Adjacent find
		template<typename ForwardRange>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange>::type
		adjacent_find(ForwardRange&& range) {
			return sprout::range::range_return<ForwardRange>::pack(
				sprout::adjacent_find(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range))
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<typename ForwardRange, typename BinaryPredicate>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange>::type
		adjacent_find(ForwardRange&& range, BinaryPredicate pred) {
			return sprout::range::range_return<ForwardRange>::pack(
				sprout::adjacent_find(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					pred
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<sprout::range::range_return_value RetV, typename ForwardRange>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange, RetV>::type
		adjacent_find(ForwardRange&& range) {
			return sprout::range::range_return<ForwardRange, RetV>::pack(
				sprout::adjacent_find(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range))
					),
				sprout::forward<ForwardRange>(range)
				);
		}

		template<sprout::range::range_return_value RetV, typename ForwardRange, typename BinaryPredicate>
		inline SPROUT_CONSTEXPR typename sprout::range::range_return<ForwardRange, RetV>::type
		adjacent_find(ForwardRange&& range, BinaryPredicate pred) {
			return sprout::range::range_return<ForwardRange, RetV>::pack(
				sprout::adjacent_find(
					sprout::begin(sprout::forward<ForwardRange>(range)),
					sprout::end(sprout::forward<ForwardRange>(range)),
					pred
					),
				sprout::forward<ForwardRange>(range)
				);
		}
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_ADJACENT_FIND_HPP
