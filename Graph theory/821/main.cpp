#include <bits/stdc++.h>
#define Max 101
using namespace std;

signed int matlist[Max][Max];

int binomialCoeff(int n, int k)
{
  if (k==0 || k==n)
    return 1;
  return  binomialCoeff(n-1, k-1) + binomialCoeff(n-1, k);
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("i","r",stdin);
    freopen("o","w",stdout);
    int a,b,cas=1;
    while(cin>>a>>b && (a!=0 || b !=0) )
    {
        int c,d,maxi=0;
        for(int i=0;i<Max;i++)
                for(int j=0;j<Max;j++)
                    matlist[i][j]=100000;
        matlist[a][b]=1;
        maxi=max(a,b);
        while(cin>>c>>d && (c!=0 || d !=0) )
        {
            matlist[c][d]=1;
            maxi=max(maxi,max(c,d));
        }
        for(int k=1;k<=maxi;k++)
            for(int i=1;i<=maxi;i++)
                for(int j=1;j<=maxi;j++)
                    {
                        matlist[i][j]=min(matlist[i][j],matlist[i][k]+matlist[k][j]);
                    }
        double somme=0,s=0;
        for(int i=1;i<=maxi;i++)
                for(int j=1;j<=maxi;j++)
                    {
                        if(i!=j &&  matlist[i][j] != 100000)
                            {s++;somme+=matlist[i][j];}
                    }
        printf("Case %d: average length between pages = %.3f clicks\n",cas++,(double)somme/s);

    }
    return 0;
}
