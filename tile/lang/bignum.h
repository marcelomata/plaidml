#pragma once

#include <boost/multiprecision/cpp_int.hpp>
#include <string>

namespace vertexai {
namespace tile {
namespace lang {

typedef boost::multiprecision::cpp_int_backend<> IntegerBackend;  // TODO(T1146): Consider setting min to 128
typedef boost::multiprecision::rational_adaptor<IntegerBackend> RationalBackend;
typedef boost::multiprecision::number<IntegerBackend, boost::multiprecision::et_off> Integer;
typedef boost::multiprecision::number<RationalBackend, boost::multiprecision::et_off> Rational;

inline std::string to_string(const Integer& x) { return x.str(); }
inline std::string to_string(const Rational& x) { return x.str(); }

// Finds greatest int that is <= x
Integer Floor(const Rational& x);
// Finds smallest int that is >= x
Integer Ceil(const Rational& x);
// Compute the absolute value
Integer Abs(const Integer& x);
// Compute the absolute value
Rational Abs(const Rational& x);
// Modulo like reduction, that is, find r, 0 <= v < m, such that r = k*m + v for some integer k
Rational Reduce(const Rational& v, const Rational& m);  // NOLINT(runtime/references)
// Compute the extended common denominator over rational.  That is, find a return value r,
// such that a / r is an integer, and b / r is an integer, and r = x*a + y*b
Rational XGCD(const Rational& a, const Rational& b, Integer& x, Integer& y);  // NOLINT(runtime/references)
// Same as above, but for a and b both integers
Integer XGCD(const Integer& a, const Integer& b, Integer& x, Integer& y);  // NOLINT(runtime/references)
// Same as above, but don't bother computing x + y
Rational GCD(const Rational& a, const Rational& b);
// Same as above, but for integers
Integer GCD(const Integer& a, const Integer& b);
// Least common multiple for integers
Integer LCM(const Integer& a, const Integer& b);
// Least of 2 Integers
Integer Min(const Integer& a, const Integer& b);
// Returns the integer quotient of dividing a by b, w/ rational remainder 0 <= r < b
Integer RatDiv(const Rational& a, const Rational& b, Rational& r);  // NOLINT(runtime/references)

}  // namespace lang
}  // namespace tile
}  // namespace vertexai
