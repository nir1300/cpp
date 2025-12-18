#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    // test main
    std::cout << "0. Test main from subject" << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    
    // test main from subject end

    Fixed c(1.5f);
    Fixed d(2.25f);

    // comparison operators
    std::cout << "\n\n1. Comparison operators" << std::endl;

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << std::boolalpha;
    std::cout << "\nc > d = " << c.operator>(d) << std::endl;
    std::cout << "c < d = " << c.operator<(d) << std::endl;
    std::cout << "c >= d = " << c.operator>=(d) << std::endl;
    std::cout << "c <= d = " << c.operator<=(d) << std::endl;
    std::cout << "c == d = " << c.operator==(d) << std::endl;
    std::cout << "c != d = " << c.operator!=(d) << std::endl;

    // Arithmetic operators

    std::cout << "\n\n2. Arithmetic operators" << std::endl;

    Fixed e = c + d;
    Fixed f = c - d;
    Fixed g = c * d;
    Fixed h = c / d;

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\nc + d = " << e << std::endl;
    std::cout << "c - d = " << f << std::endl;
    std::cout << "c * d = " << g << std::endl;
    std::cout << "c / d = " << h << std::endl;

    // in-/decrement operators

    std::cout << "\n\n3. In-/decrement operators" << std::endl;

    std::cout << "c = " << c << std::endl;

    std::cout << "[++c] pre-increment: " << ++c << ", post-increment:" << c << std::endl;
    std::cout << "[c++] pre-increment: " << c++ << ", post-increment:" << c << std::endl;

    std::cout << "[--c] pre-decrement: " << --c << ", post-decrement:" << c << std::endl;
    std::cout << "[c--] pre-decrement: " << c-- << ", post-decrement:" << c << std::endl;
    
    // min/max -> 2 functions for min/max each, both do the same, but one has *const* params, other doesnt

    std::cout << "\n\n4. Min/max functions" << std::endl;

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;

    std::cout << "\n[non-const] min(c, d) = " << Fixed::min(c, d) << std::endl;
    std::cout << "[non-const] max(c, d) = " << Fixed::max(c, d) << std::endl;

    const Fixed i(1.5f);
    const Fixed j(2.25f);

    std::cout << "[const] min(c, d) = " << Fixed::min(i, j) << std::endl;
    std::cout << "[const] max(c, d) = " << Fixed::max(i, j) << std::endl;

    return 0;
}
