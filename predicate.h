#ifndef guard_928685e2d03a51e7ad2086efab50cad3
#define guard_928685e2d03a51e7ad2086efab50cad3
#include <tuple>
#include <type_traits>
#ifndef NDEBUG
#include <array>
#endif

template <class T>
struct is_tuple : std::false_type {};

template <class... T>
struct is_tuple<std::tuple<T...>> : std::true_type {};

template <class... T>
struct is_tuple<const std::tuple<T...>> : std::true_type {};

template <class V>
constexpr bool is_tuple_v = is_tuple<V>::value;

#ifndef NDEBUG
// Simple test case
static_assert(is_tuple<std::tuple<int>>::value == true && is_tuple_v<std::array<int, 3>> == false,
              "is_tuple is a metafunction that determines if a type is a tuple.");
#endif

#endif
