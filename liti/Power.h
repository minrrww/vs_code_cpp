template<unsigned N>
struct Power{
    template<class T>
    static T value(T x){
        return x * Power<N - 1>::value(x);
    }
};
template <>
struct Power<1>
{
    template<class T>
    static T value(T x){
        return x;
    }
};
template<unsigned N,class T>
T power(T v){
    return Power<N>::value(v);
}
