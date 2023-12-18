#ifndef ARRAY_H
# define ARRAY_H


template< typename T >
class Array
{
    public:
        Array( void ): _array(NULL), _size(0)
            {};
        Array( unsigned int n ): _array(new T[n]), _size(n)
            {   for (unsigned int i = 0; i < _size; i++) _array[i] = T(); };
        Array( Array const & array ): _array(new T[array.size()]), _size(array.size())
            {   for (unsigned int i = 0; i < _size; i++) _array[i] = array._array[i]; };
        ~Array( void )
            {   delete [] _array;};

        Array &         operator=( Array const & array )
            {   if (this != &array)
                {   this->~Array(); _array = new T[array.size()]; _size = array.size();
                    for (unsigned int i = 0; i < _size; i++) _array[i] = array._array[i];}
                return *this; };
        T &             operator[]( unsigned int & index )
            {   if (index >= _size) throw BadIndexException();
                else return _array[index];};
        T &             operator[]( int index )
            {   if (index >= static_cast<int>(_size) || index < 0) throw BadIndexException();
                else return _array[index];};

        unsigned int    size( void ) const
            {   return _size;};

        class BadIndexException: public std::exception
            {   public:
                    virtual const char * what() const throw()
                        {   return "<BadIndexException> Can't acces to index.";}};

    private:
        T *             _array;
        unsigned int    _size;

};

#endif