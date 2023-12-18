#ifndef ITER_H
# define ITER_H

# include <iostream>

template< typename T, typename U >
void    iter( T * address, int size, void (*f)(U))
{
    for (int i = 0; i < size; i++)
        f(address[i]);
}

template< typename T, typename U >
void    iter( T * address, int size, T (*f)(U))
{
    for (int i = 0; i < size; i++)
        address[i] = f(address[i]);
}

template< typename T >
void    print_template( T const & i )
{
    std::cout << i << ", ";
}

template< typename T >
T       change_value( T i )
{
    return i + 10;
}

#endif