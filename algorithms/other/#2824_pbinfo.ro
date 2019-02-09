#include <iostream>
#include <fstream>

using namespace std;
ifstream in("numere25.in");
ofstream out("numere25.out");

int main()
{
    int n, i, x, a, ok = 0;
    in>>n;
    a = 0;
    while(in>>x)
    {
        for( i = a + 1; i < x; i ++ )
        {
            out<<i<<" ";
            ok = 1 ;
        }
        a = x ;
    }
    for(i=a+1;i<=n;i++)
    {
        out<<i<<" ";
        ok = 1 ;
    }
    if(ok == 0)
        out<<"Nu exista";
}
