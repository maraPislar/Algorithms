#include <iostream>

using namespace std;

int main()
{
    int n, a[100], nr, i, j, max=0, x, b[100], c[100];

    cin>>n;
    for(i=1;i<=n;i++)
    cin>>a[i];

    for(i=1;i<n;i++)
    {
        x=a[i];
        nr=1;
        for(j=i+1;j<=n;j++)
        if(x<=a[j])
        {
            x=a[j];
            nr=nr+1;
            b[nr]=x;
        }

    if(nr>max)
    {
        b[1]=a[i];
        for(i=1;i<=nr;i++)
        c[i]=b[i];
        max=nr;
    }

    }

    for(i=1;i<=max;i++)
    cout<<c[i]<<" ";
}
