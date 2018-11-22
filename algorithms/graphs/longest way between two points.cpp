#include <iostream>
#include <fstream>

using namespace std;
ifstream in("data.in");

int a[100][100], n, m, c, b, z, ok = 1, s[100];

void read()
{
    int i, x, y;
    in>>n>>m>>c>>b;
    for(i=1;i<=m;i++)
    {
        in>>x>>y;
        a[x][y] = 1;
    }
}

void first(int k)
{
    s[k] = 0;
}

int next(int k)
{
    if(s[k] < n)
    {
        s[k] ++ ;
        return 1;
    }
    else return 0;
}

int valid(int k)
{
    if( s[1] == c )
    {
        if( k > 1 )
            if( a[s[k-1]][s[k]] == 0 )
            return 0 ;
        for( int i = 1; i < k; i ++ )
            if( s[k] == s[i] )
            return 0 ;
        return 1 ;
    }
    else return 0 ;
}

int is_solution(int k)
{
    if(k == z && s[k] == b && a[s[1]][s[2]] == 1)
        return 1;
    else return 0;
}

void out(int k)
{
    int i;
    for(i=1;i<=k;i++)
    {
        cout<<s[i]<<" ";
        ok = 0;
    }
}

void backtracking(int k)
{
    first(k);
    while(next(k))
        if(valid(k))
        if(is_solution(k))
        out(k);
    else backtracking(k+1);
}

int main()
{
    read();
    z = n;
    while(ok)
        {
            backtracking(1);
            z = z - 1;
        }
}
