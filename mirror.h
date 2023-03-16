#ifndef guard_71211b8b13967d2a6bd02fa06f2d52f0
#define guard_71211b8b13967d2a6bd02fa06f2d52f0
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

#include "descending.h"
#include "predicate.h"

namespace detail {
template <class T, std::size_t... N>
auto mirror_helper(T&& t, std::integer_sequence<std::size_t, N...>) {
    return std::tuple<std::tuple_element_t<N, std::remove_reference_t<T>>...>(std::get<N>(std::forward<T>(t))...);
}
}  // namespace detail

template <class T, std::enable_if_t<is_tuple_v<std::remove_reference_t<T>>, void*> = nullptr>
auto mirror(T&& x) {
    return detail::mirror_helper(std::forward<T>(x),
                                 index_descending<std::tuple_size<std::remove_reference_t<T>>::value>());
}

#endif
