#include <cassert>
#include <iostream>
#include <memory>
#include <string>
#include <tuple>

#include "mirror.h"

int main(void) {
    // function `mirror` reverse the order of tuples.
    assert(mirror(std::tuple(1, 2, 3)) == std::make_tuple(3, 2, 1));
    {
        // function `mirror` support forwarding.
        auto foo = std::make_tuple(std::make_unique<std::string>("abc"));
        auto bar = mirror(std::move(foo));
        assert(std::get<0>(foo) == nullptr);
        assert(*std::get<0>(bar) == "abc");
    }
    {
        // function `mirror` support tuple of reference.
        int one, two;
        std::string three;
        auto foo = std::tie(one, two, three);
        auto bar = mirror(foo);
        assert(&std::get<0>(foo) == &std::get<2>(bar));
        assert(&std::get<1>(foo) == &std::get<1>(bar));
        assert(&std::get<2>(foo) == &std::get<0>(bar));
    }
}
