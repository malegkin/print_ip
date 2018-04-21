#include "stdafx.h"
#include "foo.h"

int main()
{
    cout << to_ip_string( char(-1)) << endl;
    cout << to_ip_string( short(0)) << endl;
    cout << to_ip_string( int(2130706433)) << endl;
    cout << to_ip_string( long(8875824491850138409)) << endl;
    cout << to_ip_string( string("8.8.8.8")) << endl;
    cout << to_ip_string( vector<int>({1, 2, 3})) << endl;
    cout << to_ip_string( list<int>({1, 2, 3, 4})) << endl;
    cout << to_ip_string( make_tuple(1 , 2, 3, 4, 5 )) << endl;

    return 0;
}
