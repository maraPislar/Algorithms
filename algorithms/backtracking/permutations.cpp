#include <iostream>

using namespace std;

int n, s[100] ;

void first(int k)
{
    s[k] = 0 ;
}

int next( int k )
{
    if( s[k] < n )
    {
        s[k] ++ ;
        return 1 ;
    }
    else
    return 0 ;
}

int valid( int k )
{
    for( int i = 1; i < k; i ++ )
    if( s[k] == s[i] )
    return 0 ;
    return 1 ;
}

int is_solution( int k )
{
    if( k == n )
    return 1 ;
    else
    return 0 ;
}

void out()
{
    for( int i = 1; i <= n; i ++ )
    cout<<s[i]<<" " ;
    cout<<endl ;
}

void backtracking( int k )
{
    first(k);
    while(next(k))
    {
        if(valid(k))
        if(is_solution(k))
        out();
        else
        backtracking(k+1);
    }
}

// Backtracking Problem - Permutations of n

int main()
{
    cin>>n ;
    backtracking(1) ;
}
