#ifndef SPROUT_LIBS_TUPLE_TEST_TUPLE_CPP
#define SPROUT_LIBS_TUPLE_TEST_TUPLE_CPP

#include <sstream>
#include <sprout/tuple/tuple.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void tuple_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto tup1 = sprout::tuples::tuple<int, double>(1, 1.0);
			SPROUT_STATIC_CONSTEXPR auto tup2 = sprout::tuples::tuple<int, double>();

			// constructor
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>();
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 0);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(tup1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(1, 1.0);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(1l);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(1l, 1.0f);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(1l, 1.0f, '-');
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}

			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(sprout::tuples::tuple<long>(1l));
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(sprout::tuples::tuple<long, float>(1l, 1.0f));
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}
			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple<int, double>(sprout::tuples::tuple<long, float, char>(1l, 1.0f, '-'));
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}

			// operator=
			{
				auto tup3 = tup2;
				tup3 = sprout::tuples::tuple<int, double>(1, 1.0);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}
			{
				auto tup3 = tup2;
				tup3 = sprout::tuples::tuple<long>(1l);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
			}
			{
				auto tup3 = tup2;
				tup3 = sprout::tuples::tuple<long, float>(1l, 1.0f);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}
			{
				auto tup3 = tup2;
				tup3 = sprout::tuples::tuple<long, float, char>(1l, 1.0f, '-');
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}

			// swap
			{
				auto tup3 = tup1;
				auto tup4 = tup2;
				tup3.swap(tup4);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 0);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup4) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup4) == 1.0);
			}
			{
				auto tup3 = tup1;
				auto tup4 = tup2;
				swap(tup3, tup4);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 0);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 0.0);
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup4) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup4) == 1.0);
			}

			// std::tuple_size
			TESTSPR_BOTH_ASSERT(std::tuple_size<decltype(tup1)>::value == 2);

			// std::tuple_element
			TESTSPR_BOTH_ASSERT((std::is_same<std::tuple_element<0, decltype(tup1)>::type, int const>::value));
			TESTSPR_BOTH_ASSERT((std::is_same<std::tuple_element<1, decltype(tup1)>::type, double const>::value));

			// operator==
			TESTSPR_BOTH_ASSERT(!(tup1 == tup2));
			TESTSPR_BOTH_ASSERT((tup1 == sprout::tuples::tuple<int, double>(1, 1.0)));
			TESTSPR_BOTH_ASSERT((!(tup1 == sprout::tuples::tuple<long, float>())));
			TESTSPR_BOTH_ASSERT((tup1 == sprout::tuples::tuple<long, float>(1l, 1.0f)));

			// operator!=
			TESTSPR_BOTH_ASSERT(tup1 != tup2);
			TESTSPR_BOTH_ASSERT((!(tup1 != sprout::tuples::tuple<int, double>(1, 1.0))));
			TESTSPR_BOTH_ASSERT((tup1 != sprout::tuples::tuple<long, float>()));
			TESTSPR_BOTH_ASSERT((!(tup1 != sprout::tuples::tuple<long, float>(1l, 1.0f))));

			// operator<
			TESTSPR_BOTH_ASSERT(!(tup1 < tup2));
			TESTSPR_BOTH_ASSERT((!(tup1 < sprout::tuples::tuple<int, double>(1, -1.0))));
			TESTSPR_BOTH_ASSERT((!(tup1 < sprout::tuples::tuple<int, double>(1, 1.0))));
			TESTSPR_BOTH_ASSERT((tup1 < sprout::tuples::tuple<int, double>(1, 2.0)));
			TESTSPR_BOTH_ASSERT((!(tup1 < sprout::tuples::tuple<long, float>())));
			TESTSPR_BOTH_ASSERT((!(tup1 < sprout::tuples::tuple<long, float>(1l, -1.0f))));
			TESTSPR_BOTH_ASSERT((!(tup1 < sprout::tuples::tuple<long, float>(1l, 1.0f))));
			TESTSPR_BOTH_ASSERT((tup1 < sprout::tuples::tuple<long, float>(1l, 2.0f)));

			// operator>
			TESTSPR_BOTH_ASSERT(tup1 > tup2);
			TESTSPR_BOTH_ASSERT((tup1 > sprout::tuples::tuple<int, double>(1, -1.0)));
			TESTSPR_BOTH_ASSERT((!(tup1 > sprout::tuples::tuple<int, double>(1, 1.0))));
			TESTSPR_BOTH_ASSERT((!(tup1 > sprout::tuples::tuple<int, double>(1, 2.0))));
			TESTSPR_BOTH_ASSERT((tup1 > sprout::tuples::tuple<long, float>()));
			TESTSPR_BOTH_ASSERT((tup1 > sprout::tuples::tuple<long, float>(1l, -1.0f)));
			TESTSPR_BOTH_ASSERT((!(tup1 > sprout::tuples::tuple<long, float>(1l, 1.0f))));
			TESTSPR_BOTH_ASSERT((!(tup1 > sprout::tuples::tuple<long, float>(1l, 2.0f))));

			// operator<=
			TESTSPR_BOTH_ASSERT(!(tup1 <= tup2));
			TESTSPR_BOTH_ASSERT((!(tup1 <= sprout::tuples::tuple<int, double>(1, -1.0))));
			TESTSPR_BOTH_ASSERT((tup1 <= sprout::tuples::tuple<int, double>(1, 1.0)));
			TESTSPR_BOTH_ASSERT((tup1 <= sprout::tuples::tuple<int, double>(1, 2.0)));
			TESTSPR_BOTH_ASSERT((!(tup1 <= sprout::tuples::tuple<long, float>())));
			TESTSPR_BOTH_ASSERT((!(tup1 <= sprout::tuples::tuple<long, float>(1l, -1.0f))));
			TESTSPR_BOTH_ASSERT((tup1 <= sprout::tuples::tuple<long, float>(1l, 1.0f)));
			TESTSPR_BOTH_ASSERT((tup1 <= sprout::tuples::tuple<long, float>(1l, 2.0f)));

			// operator>=
			TESTSPR_BOTH_ASSERT(tup1 >= tup2);
			TESTSPR_BOTH_ASSERT((tup1 >= sprout::tuples::tuple<int, double>(1, -1.0)));
			TESTSPR_BOTH_ASSERT((tup1 >= sprout::tuples::tuple<int, double>(1, 1.0)));
			TESTSPR_BOTH_ASSERT((!(tup1 >= sprout::tuples::tuple<int, double>(1, 2.0))));
			TESTSPR_BOTH_ASSERT((tup1 >= sprout::tuples::tuple<long, float>()));
			TESTSPR_BOTH_ASSERT((tup1 >= sprout::tuples::tuple<long, float>(1l, -1.0f)));
			TESTSPR_BOTH_ASSERT((tup1 >= sprout::tuples::tuple<long, float>(1l, 1.0f)));
			TESTSPR_BOTH_ASSERT((!(tup1 >= sprout::tuples::tuple<long, float>(1l, 2.0f))));

			// get
			TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup1) == 1);
			TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup1) == 1.0);
			{
				auto tup3 = tup1;
				TESTSPR_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
			}

			// tuple_size
			TESTSPR_BOTH_ASSERT(sprout::tuples::tuple_size<decltype(tup1)>::value == 2);

			// tuple_element
			TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<0, decltype(tup1)>::type, int const>::value));
			TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<1, decltype(tup1)>::type, double const>::value));

			// make_tuple
			TESTSPR_BOTH_ASSERT(sprout::tuples::make_tuple(1, 1.0) == tup1);

			// forward_as_tuple
			TESTSPR_BOTH_ASSERT(sprout::tuples::forward_as_tuple(1, 1.0) == tup1);

			// tie
			{
				auto v1 = 0;
				auto v2 = 0.0;
				TESTSPR_ASSERT(sprout::tuples::tie(v1, v2) == tup2);

				sprout::tuples::tie(v1, v2) = tup1;
				TESTSPR_ASSERT(v1 == 1);
				TESTSPR_ASSERT(v2 == 1.0);
			}

			// tuple_cat
			{
				typedef sprout::tuples::result_of::tuple_cat<decltype(tup1), decltype(tup2)>::type concatenated_type;
				TESTSPR_BOTH_ASSERT(sprout::tuples::tuple_size<concatenated_type>::value == 4);
				TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<0, concatenated_type>::type, int>::value));
				TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<1, concatenated_type>::type, double>::value));
				TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<2, concatenated_type>::type, int>::value));
				TESTSPR_BOTH_ASSERT((std::is_same<sprout::tuples::tuple_element<3, concatenated_type>::type, double>::value));
			}

			{
				SPROUT_STATIC_CONSTEXPR auto tup3 = sprout::tuples::tuple_cat(tup1, tup2);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<0>(tup3) == 1);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<1>(tup3) == 1.0);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<2>(tup3) == 0);
				TESTSPR_BOTH_ASSERT(sprout::tuples::get<3>(tup3) == 0.0);
			}

			// is_tuple
			TESTSPR_BOTH_ASSERT(sprout::tuples::is_tuple<decltype(tup1)>::value);
			TESTSPR_BOTH_ASSERT(!sprout::tuples::is_tuple<int>::value);

			// hash_value
			TESTSPR_BOTH_ASSERT((hash_value(sprout::tuples::tuple<int, int>(1, 2)) != 0));
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::tuple_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_TUPLE_TEST_TUPLE_CPP
