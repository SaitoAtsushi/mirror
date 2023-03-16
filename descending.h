#ifndef guard_d91004790e99d6ebbc9f31ef38a89832
#define guard_d91004790e99d6ebbc9f31ef38a89832
#include <cstddef>
#include <utility>
#ifndef NDEBUG
#include <type_traits>
#endif

namespace detail {
template <class T, T L>
class integer_descending {
  private:
    template <T N, T Limit>
    struct helper {
        template <T... Seq>
        static auto foo(std::integer_sequence<T, Seq...> x)
            -> decltype(helper<N + 1, L>::foo(std::integer_sequence<T, N, Seq...>()));
    };

    template <T N>
    struct helper<N, N> {
        template <T... Seq>
        static auto foo(std::integer_sequence<T, Seq...> x) -> decltype(x);
    };

  public:
    using type = decltype(helper<0, L>::foo(std::integer_sequence<T>()));
};
}  // namespace detail

template <class T, T N>
using make_integer_descending = typename detail::integer_descending<T, N>::type;

template <std::size_t N>
using index_descending = make_integer_descending<std::size_t, N>;

#ifndef NDEBUG
// Simple test case
static_assert(std::is_same<index_descending<5>, std::integer_sequence<std::size_t, 4, 3, 2, 1, 0>>::value,
              "index_descending make integer_sequence of descending order.");
#endif

#endif
