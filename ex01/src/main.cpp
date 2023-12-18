#include "iter.hpp"

void    print_int( int i );

int main( void )
{
    int     a[5] = {0,1,2,3,4};
    size_t  size = 5;

    iter(a, size, print_int);
    std::cout << std::endl;
    std::cout << "\n\n";

    iter(a, size, print_template<int>);
    std::cout << std::endl;
    std::cout << "\n\n";

    iter(a, size, change_value<int>);
    iter(a, size, print_template<int>);
    std::cout << std::endl;
    std::cout << "\n\n";

    return 0;
}

void    print_int( int i )
{
    std::cout << i << ", ";
}
