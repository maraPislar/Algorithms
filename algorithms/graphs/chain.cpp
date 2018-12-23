#include <iostream>
#include <fstream>

using namespace std;
ifstream f("date.in");

int a[100][100], s[100], n, ok = 0, b[100][100], m = -1;

void citire()
{
    int i, j;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>i>>j;
        a[i][j] = 1 ;
    }
}

void init(int k)
{
    s[k] = 0 ;
}

int succesor(int k)
{
    if( s[k] < n )
    {
        s[k] ++ ;
        return 1;
    }
    else return 0;
}

int valid(int k)
{
    if(k>1)
        if( a[s[k]][s[k-1]] == 0 )
            return 0;

    for(int i=1;i<k;i++)
        if(s[k] == s[i])
        return 0;

    return 1;
}

int solutie(int k)
{
    if( k > 1 && a[s[k]][s[1]] == 1)
        {
            s[ k + 1 ] = s[ 1 ] ;
            return 1 ;
        }
    else
        return 0 ;
}

void tipar(int k)
{
    for( int i = 1; i <= k + 1; i ++ )
        cout<<s[i]<<" ";
        cout<<endl;
}

void bkt(int k)
{
    init(k);
    while(succesor(k) && ok == 0)
        if(valid(k))
            if(solutie(k))
                tipar(k) ;
            else
                bkt(k+1);
}

int main()
{
    citire();
    bkt(1);
}
