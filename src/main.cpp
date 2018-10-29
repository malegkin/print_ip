#include "stdafx.h"
#include "to_ip_string.h"


template <typename T>
void dump(const T& in, std::ostream& os = std::cout){
    std::cout << to_ip_string( in ) << std::endl;
}

int main()
{
    try {
        dump( char(-1) );
        dump( short(0) );
        dump( int(2130706433) );
        dump( long(8875824491850138409) );
        dump( std::string("8.8.8.8") );
        dump( std::vector<uint32_t>({1, 2, 3}) );
        dump( std::list<uint32_t>({1, 2, 3, 4}) );
        dump( std::make_tuple(1, 2, 3, 4, 5) );
        dump( std::make_tuple(1, 2, std::list<uint32_t>({1,2,3}), 4, 5) );


        dump( std::vector<std::list<uint32_t>>({{1,2},{3,4},{5,6}}) );
        auto v1 = std::vector<uint32_t>({1,2});
        auto v2 = std::vector<uint32_t>({3,4});
        auto v3 = std::vector<uint32_t>({5,6});


        dump( std::make_tuple(v1, v2, v3 ));

    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    catch (...) {
        std::cerr << "Caught unknown exception." << std::endl;
        return -1;
    }

    return 0;
}
