#ifndef SPROUT_LIBS_ALGORITHM_TEST_MINMAX_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_MINMAX_CPP

#include <sprout/algorithm/minmax.hpp>
#include <sprout/array.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_minmax_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 2>{{-1, 1}};

			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::minmax(
					arr1[0],
					arr1[1]
					);
				TESTSPR_BOTH_ASSERT(result.first == arr1[0]);
				TESTSPR_BOTH_ASSERT(result.second == arr1[1]);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::minmax(
					arr1[1],
					arr1[0]
					);
				TESTSPR_BOTH_ASSERT(result.first == arr1[0]);
				TESTSPR_BOTH_ASSERT(result.second == arr1[1]);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::minmax(
					arr1[0],
					arr1[1],
					testspr::less<int>()
					);
				TESTSPR_BOTH_ASSERT(result.first == arr1[0]);
				TESTSPR_BOTH_ASSERT(result.second == arr1[1]);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto result = sprout::minmax(
					arr1[1],
					arr1[0],
					testspr::less<int>()
					);
				TESTSPR_BOTH_ASSERT(result.first == arr1[0]);
				TESTSPR_BOTH_ASSERT(result.second == arr1[1]);
			}
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_minmax_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_MINMAX_CPP