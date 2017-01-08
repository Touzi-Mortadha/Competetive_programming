#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
vector<vii> adjlist;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("i","r",stdin);
    freopen("o","w",stdout);
    int t; cin>>t;
    while(t--)
    {
        int v,m,x,y,t;
        cin>>v>>m;
        adjlist.clear();
        adjlist.resize(v);
        for(int i=0;i<m;i++)
        {
            //adjlist.push_back(vii());
            cin>>x>>y>>t;
            adjlist[x].push_back(make_pair(y,t));
        }
        vi dist(v,-100000);dist[0]=0;
        for(int i=0;i<v-1;i++)
            for(int u=0;u<v;u++)
                for(int j=0;j<adjlist[u].size();j++)
                {
                    ii v = adjlist[u][j];
                    dist[v.first]=min(dist[v.first],dist[u]+v.second);
                }
        bool neg=false;
        for(int u=0;u<v;u++)
            for(int j=0;j<adjlist[u].size();j++)
            {
                ii v = adjlist[u][j];
                if(dist[v.first]>dist[u]+v.second)
                {
                    neg=true;break;
                }
            }
        if(neg)
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;
    }

    return 0;
}
