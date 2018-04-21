#pragma once

#include "stdafx.h"
#include <numeric>
#include <type_traits>
#include <list>
#include <vector>
#include <deque>
#include <array>


// IS container

#define IS_CONTAINER_IMPL(T) template <typename... Args> struct is_container_impl<T<Args...>>: true_type{};

template <typename T>
struct is_container_impl:  false_type{};

IS_CONTAINER_IMPL(vector)
IS_CONTAINER_IMPL(list)
IS_CONTAINER_IMPL(deque)
IS_CONTAINER_IMPL(array)

template <typename T> struct is_container {
    static constexpr bool const value = is_container_impl<typename decay<T>::type>::value;
};

template <typename T>
inline constexpr bool is_container_v = is_container<T>::value;


// tuple to vector
template <typename T, size_t N, typename Tuple, size_t... Id>
constexpr decltype(auto) to_vector_impl(const Tuple& in, index_sequence<Id...>){
    return vector<T>{get<Id>(in)...};
};

template<typename T, typename... TT>
constexpr vector<T> to_vector(const tuple<T, TT...>& in)
{
    using Tuple = tuple<T, TT...>;
    constexpr auto N = tuple_size<Tuple>::value;
    return to_vector_impl<T, N, Tuple>(in, make_index_sequence<N>());
}


//to_ip_string
string to_ip_string(string in){
    return in;
}

template <typename T>
typename enable_if<is_integral<T>::value, string>::type
to_ip_string(const T& in)   {
    string out = to_string (in & 0xff);

    for (size_t i = 1; i < sizeof(in); i++){
        out = to_string((in >> i*8) & 0xff) + "." + out;
    }
    return out;
}

template <typename T>
typename enable_if<is_container_v<T>, string>::type
to_ip_string(const T& in)   {
    if (in.size() == 0)
        return "";

    return accumulate(next(in.begin()), in.end(),
                      to_string(*(in.begin())),
                      [](string out, auto a) { return out + ".." + to_string(a); });
};



template <typename... T>
string to_ip_string(const tuple<T...>& in){
    return to_ip_string( to_vector(in) );
}