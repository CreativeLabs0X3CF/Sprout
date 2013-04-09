#ifndef SPROUT_RANGE_ALGORITHM_FIT_UNIQUE_COPY_HPP
#define SPROUT_RANGE_ALGORITHM_FIT_UNIQUE_COPY_HPP

#include <sprout/config.hpp>
#include <sprout/container/functions.hpp>
#include <sprout/algorithm/fit/result_of.hpp>
#include <sprout/algorithm/fit/unique_copy.hpp>

namespace sprout {
	namespace range {
		namespace fit {
			//
			// unique_copy
			//
			template<typename InputRange, typename Result>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng, Result const& result) {
				return sprout::fit::unique_copy(sprout::begin(rng), sprout::end(rng), result);
			}
			template<typename InputRange, typename Result, typename BinaryPredicate>
			inline SPROUT_CONSTEXPR typename sprout::fit::result_of::algorithm<Result>::type
			unique_copy(InputRange const& rng, Result const& result, BinaryPredicate pred) {
				return sprout::fit::unique_copy(sprout::begin(rng), sprout::end(rng), result, pred);
			}
		}	// namespace fit
	}	// namespace range
}	// namespace sprout

#endif	// #ifndef SPROUT_RANGE_ALGORITHM_FIT_UNIQUE_COPY_HPP
