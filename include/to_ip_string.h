#pragma once

#include "stdafx.h"
#include "traits.h"
#include <utility>
#include <numeric>


template<typename T, typename... TT>
auto to_vector(const std::tuple<T, TT...>& in);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//HL to_ip_string
auto to_ip_string(const std::string in, bool is_top = true){
    return in;
}

template <typename T>
typename std::enable_if_t< is_container_v<T> && std::is_same_v<typename T::value_type, std::string>, std::string >
to_ip_string( const T& in, bool is_top = true)
{
    if (in.size() == 0)
        return "";

    std::string acc = accumulate(next(begin(in)), end(in),
                      (*(begin(in))),
                      [](std::string out, auto a) { return out + "." + to_ip_string(a); });

    return is_top ? acc: "["+acc+"]" ;
};




template <typename T>
typename std::enable_if_t<std::is_integral_v<T>, std::string >
to_ip_string( const T& in, bool is_top = true)
{
    if (!is_top)
        return std::to_string(in);

    std::vector<std::string> vsin;

    for (size_t i = sizeof(in); i--; ){
        vsin.push_back( std::to_string((in >> i*8) & 0xff) );
    }

    return to_ip_string( vsin, true );
}


template <typename T>
typename std::enable_if_t<is_container_v<T> && !std::is_same_v<typename T::value_type, std::string>, std::string >
to_ip_string( const T& in, bool is_top = true)
{
    std::vector<std::string> vsin;
    for(auto a: in){
        vsin.push_back( to_ip_string(a, false) );
    }

    return to_ip_string( vsin, is_top );
};

template <typename... T>
std::string to_ip_string(const std::tuple<T...>& in, bool is_top = true){
    return to_ip_string( to_vector(in), is_top );
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//to_vector
template <typename T, typename Tuple, size_t... Id>
auto to_vector_impl(const Tuple& in, std::index_sequence<Id...>)
{
    return std::vector<std::string>{ to_ip_string(std::get<Id>(in), false)...};
};

template<typename T, typename... TT>
auto to_vector(const std::tuple<T, TT...>& in)
{
    using Tuple = std::tuple<T, TT...>;
    constexpr auto N = std::tuple_size_v<Tuple>;
    return to_vector_impl<T, Tuple>(in, std::make_index_sequence<N>());
}

std::vector<std::string> to_vector(const std::tuple<>& in){
    return std::vector<std::string>();
}



/*
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//to_ip_string
std::string to_ip_string(const std::string in){
    return in;
}

template <typename T>
typename std::enable_if_t< std::is_integral_v< T >, std::string >
to_ip_string( const T& in )   {
    std::string out = std::to_string (in & 0xff);

    for (size_t i = 1; i < sizeof(in); i++){
        out = std::to_string((in >> i*8) & 0xff) + "." + out;
    }
    return out;
};

template <typename T>
typename std::enable_if_t< is_container_v<T>, std::string >
to_ip_string( const T& in)   {
    if (in.size() == 0)
        return "";

    return accumulate(next(begin(in)), end(in),
                      to_string(*(begin(in))),
                      [](std::string out, auto a) { return out + "." + to_string(a); });
};

template <typename... T>
std::string to_ip_string(const std::tuple<T...>& in){
    return to_ip_string( to_vector(in) );
}
*/

