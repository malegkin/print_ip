#include "stdafx.h"

#define BOOST_TEST_MODULE test_foo
#include <boost/test/unit_test.hpp>
#include "foo.h"
    
#define LOG_LEVEL all

BOOST_AUTO_TEST_SUITE( test_suite_main )

BOOST_AUTO_TEST_CASE( test_block_allocator )
{
//      BOOST_REQUIRE( pair.first  == pair.second);        
}


BOOST_AUTO_TEST_SUITE_END()
