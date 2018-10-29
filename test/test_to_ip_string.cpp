#include "../include/stdafx.h"

#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include "to_ip_string.h"
    
#define LOG_LEVEL all

BOOST_AUTO_TEST_SUITE( test_suite_main )


BOOST_AUTO_TEST_CASE( test_to_ip_string__base_hw_conversions )
{
    BOOST_REQUIRE( to_ip_string( char(-1)) == "255" );
    BOOST_REQUIRE( to_ip_string( short(0)) == "0.0" );
    BOOST_REQUIRE( to_ip_string( int(2130706433)) == "127.0.0.1" );
    BOOST_REQUIRE( to_ip_string( long(8875824491850138409)) == "123.45.67.89.101.112.131.41" );
    BOOST_REQUIRE( to_ip_string( "8.8.8.8") == "8.8.8.8" );
    BOOST_REQUIRE( to_ip_string( std::vector<uint8_t>({1, 2, 3})) == "1.2.3" );
    BOOST_REQUIRE( to_ip_string( std::list<uint8_t>({1, 2, 3})) == "1.2.3" );
    BOOST_REQUIRE( to_ip_string( std::make_tuple(1 , 2, 3, 4, 5 )) == "1.2.3.4.5" );
}


BOOST_AUTO_TEST_CASE( test_to_ip_string__vector_of_list_of_numbers )
{
    BOOST_REQUIRE( to_ip_string( std::vector<std::list<uint8_t>>({{1,2},{3,4},{5,6}})) == "[1.2].[3.4].[5.6]");
}

BOOST_AUTO_TEST_CASE( test_to_ip_string__list_of_vector_of_numbers )
{
    BOOST_REQUIRE( to_ip_string( std::list<std::vector<uint8_t>>({{1,2},{3,4},{5,6}})) == "[1.2].[3.4].[5.6]");
}

BOOST_AUTO_TEST_CASE( test_to_ip_string__list_of_strings )
{
    BOOST_REQUIRE( to_ip_string( std::list<std::string>({"s1", "s2", "s3"})) == "s1.s2.s3");
}

BOOST_AUTO_TEST_CASE( test_to_ip_string__vector_of_strings )
{
    BOOST_REQUIRE( to_ip_string( std::vector<std::string>({"s1", "s2", "s3"})) == "s1.s2.s3");
}

BOOST_AUTO_TEST_CASE( test_to_ip_string__tuple_of_vector_of_uint8 )
{
    auto v1 = std::vector<uint32_t>({1, 2});
    auto v2 = std::vector<uint32_t>({3, 4});
    auto v3 = std::vector<uint32_t>({5, 6});
    BOOST_REQUIRE( to_ip_string(std::make_tuple(v1, v2, v3)) == "[1.2].[3.4].[5.6]");
}

BOOST_AUTO_TEST_CASE( test_to_ip_string__tuple_of_diff_types )
{
    auto t = std::make_tuple(1, "s2", std::vector<std::string>({"s3", "s4"}));

    BOOST_REQUIRE( to_ip_string(t) == "1.s2.[s3.s4]");
}


BOOST_AUTO_TEST_SUITE_END()
