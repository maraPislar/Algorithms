#include <iostream>
#include <fstream>

using namespace std;
ifstream in("date.in");

int main()
{
    int a = -1, b = 1000000001, ok = 1, x;
    while(in>>x)
    {
        if( x % 2 == 0 )
        {
            if( x >= a )
            a = x;
            else
            {
                ok = 0;
                break;
            }
        }
        else
        {
            if( x <= b )
            b = x ;
            else
            {
                ok = 0;
                break;
            }
        }
    }
    if(ok)
        cout<<"DA";
    else
        cout<<"NU";
}
