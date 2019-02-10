#include <iostream>
#include <fstream>

using namespace std;
ifstream in("puteri6.in");
ofstream out("puteri6.out");

int main()
{
    int x, n, i, p, nr, frecventa[100] = {}, verificare = 0;
    in>>n;
    while(in>>x)
    {
        nr = 0 ;
        while( x != 1 )
        {
            nr = nr + 1;
            x = x / 10;
        }
        frecventa[nr] ++ ;
        verificare = verificare+ 1;
    }
    if( verificare > n )
    {
    nr = 0;
    i = -1;
    while( nr < n )
    {
        i ++ ;
        nr = nr + frecventa[i];
    }
    p = 1 ;
    while( i != 0 )
    {
        p = p * 10 ;
        i -- ;
    }
    cout<<p;
    }
    else 
        cout<<"Nu exista";
}
