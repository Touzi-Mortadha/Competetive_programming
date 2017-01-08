#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adjlist;

int main()
{
    //ios_base::sync_with_stdio(false);
    freopen("i","r",stdin);
   //freopen("o","w",stdout);
    int n;
    while(cin>>n && n!=-1 && n!= 0)
    {
        int w,j,x;
        adjlist.clear();
        adjlist.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>w>>j;
/*            if(w ==0 && j==0 )
            {
                //cout<<"a a a a a a a a a a a a a a a"<<endl;
                break;
            }*/
            for(int k=0;k<j;k++)
            {
                cin>>x;
                adjlist[i].push_back(make_pair(x,w));
            }

        }

     /*   for(int i=1;i<=n;i++)
        {
            cout<<i<<" −−> ";
            for(int j=0;j<adjlist[i].size();j++)
                cout<<adjlist[i][j].first<<" ";
            cout<<endl;

        }
*/
      vi dist(n+1,-100000);dist[1]=100;
      for(int i=0;i<n-1;i++)
        for(int u=1;u<=n;u++)
            for(int j=0;j<adjlist[u].size();j++)
            {
            ii v = adjlist[u][j];
            if(dist[v.first] < dist[u]+v.second)
                dist[v.first]=dist[u]+v.second;
            }
       int neg=-1;
        for(int u=1;u<=n;u++)
            for(int j=0;j<adjlist[u].size();j++)
            {
                ii v = adjlist[u][j];
                if(dist[v.first]<dist[u]+v.second)
                {
                    neg=u;break;
                }
            }
    //cout<<"neg== "<<neg<<endl;
    /*for(int i=1;i<=n;i++)
        cout<<dist[i]<<endl;*/
    int a=1;
    if(neg!=-1)//cout<<neg<<endl;
       {
       for(int i=neg;i>0;i--)
            if(dist[i]<=0)
                {cout<<"hopeless"<<endl;a=0;break;}
       }
    else
        {
        for(int i=1;i<=n;i++)
            if(dist[i]<=0)
                {cout<<"hopeless"<<endl;a=0;break;}
        }
    if(a==1)
        cout<<"winnable"<<endl;

    }
    return 0;
}
