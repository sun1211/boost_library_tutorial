#include <boost/hana/traits.hpp>

//create an is_arithmetic_ functional object
constexpr auto is_arithmetic_ = [](const auto& v) {
    auto type = boost::hana::typeid_(v);
    return boost::hana::traits::is_arithmetic(type);
};

//we implement the get_nonarithmetics function
#include <boost/hana/remove_if.hpp>

template <class Sequence>
auto get_nonarithmetics(const Sequence& seq)  {
    return boost::hana::remove_if(seq, [](const auto& v) {
        return is_arithmetic_(v);
    });
}

//define get_arithmetics the other way around
#include <boost/hana/filter.hpp>

constexpr auto get_arithmetics = [](const auto& seq) {
    return boost::hana::filter(seq, is_arithmetic_);
};

#include <boost/hana/tuple.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/equal.hpp>
#include <cassert>

struct foo {
    bool operator==(const foo&) const { return true; }
    bool operator!=(const foo&) const { return false; }
};

int main() {
    const auto tup1
        = boost::hana::make_tuple(8, foo{}, foo{}, 0.0);

    const auto res_na = get_nonarithmetics(tup1);
    const auto res_a = get_arithmetics(tup1);

    using boost::hana::literals::operator ""_c;
    assert(res_a[0_c] == 8);

    const auto res_na_expected = boost::hana::make_tuple(foo(), foo());
    assert(res_na == res_na_expected);
}