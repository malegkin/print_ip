#include "../include/stdafx.h"

#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include "to_ip_string.h"
    
#define LOG_LEVEL all

BOOST_AUTO_TEST_SUITE( test_suite_main )

BOOST_AUTO_TEST_CASE( test_to_vector__convert_empty_tuple ) {
        auto v0 = to_vector(std::make_tuple());
        BOOST_REQUIRE(v0.size() == 0);
}

BOOST_AUTO_TEST_CASE( test_to_vector__convert_tuple_of_int ) {
    auto v1 = to_vector(std::make_tuple(1, 2, 3));
    BOOST_REQUIRE( v1.size() == 3 );
    BOOST_REQUIRE( v1[0] == "1" );
    BOOST_REQUIRE( v1[1] == "2" );
    BOOST_REQUIRE( v1[2] == "3" );
}

BOOST_AUTO_TEST_CASE( test_to_vector__convert_tuple_of_diff_types ) {
    auto v1 = to_vector(std::make_tuple(1, "s2", std::vector<std::string>({"s3", "s4"})));
    BOOST_REQUIRE( v1.size() == 3 );
    BOOST_REQUIRE( v1[0] == "1" );
    BOOST_REQUIRE( v1[1] == "s2" );
    BOOST_REQUIRE( v1[2] == "[s3.s4]" );
}

BOOST_AUTO_TEST_SUITE_END()
