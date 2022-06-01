template<unsigned N>
struct Factorial
{
    enum
    {
        VALUE = N * Factorial<N - 1>::VALUE
    };
};
template<>
struct Factorial<0>
{
    enum
    {
        VALUE = 1
    };
};

