#include "stdafx.h"

#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include "foo.h"
    
#define LOG_LEVEL all

BOOST_AUTO_TEST_SUITE( test_suite_main )

BOOST_AUTO_TEST_CASE( test_block_allocator )
{
    BOOST_REQUIRE( to_ip_string( char(-1)) == "255" );
    BOOST_REQUIRE( to_ip_string( short(0)) == "0.0" );
    BOOST_REQUIRE( to_ip_string( int(2130706433)) == "127.0.0.1" );
    BOOST_REQUIRE( to_ip_string( long(8875824491850138409)) == "123.45.67.89.101.112.131.41" );
    BOOST_REQUIRE( to_ip_string( "8.8.8.8") == "8.8.8.8" );
    BOOST_REQUIRE( to_ip_string( vector<int>({1, 2, 3})) == "1..2..3" );
    BOOST_REQUIRE( to_ip_string( list<int>({1, 2, 3, 4})) == "1..2..3..4" );
    BOOST_REQUIRE( to_ip_string( make_tuple(1 , 2, 3, 4, 5 )) == "1..2..3..4..5" );
}


BOOST_AUTO_TEST_SUITE_END()
