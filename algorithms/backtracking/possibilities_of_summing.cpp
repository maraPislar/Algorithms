#include <iostream>

using namespace std;

int n, s[100];

void init(int k)
{
    s[k]=0;
}

int succesor(int k)
{
    if(s[k]<n)
    {
        s[k]++;
        return 1;
    }
    else
    return 0;
}

int valid(int k)
{
    int nr=0;

    for(int i=1;i<=k;i++)
    nr=nr+s[i];

    if(nr>n)
    return 0;

    return 1;
}

int solutie(int k)
{
        int nr=0;
        for(int i=1;i<=k;i++)
        nr=nr+s[i];
        if(nr==n)
        return 1;
        else
        return 0;
}

void tipar(int k)
{
    for(int i=1;i<=k;i++)
    if(i!=k)
    cout<<s[i]<<" + ";
    else cout<<s[i];
    cout<<endl;
}

void bkt(int k)
{
    init(k);

    while(succesor(k))
        if(valid(k))
        if(solutie(k))
        tipar(k);
        else
        bkt(k+1);
}

int main()
{
    cin>>n;
    bkt(1);
}
