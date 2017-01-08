#include <bits/stdc++.h>

using namespace std;
vector<vector<pair<int,int> > > adjlist;


int main ()
{
    freopen("input","r+",stdin);
    freopen("out","w",stdout);
    int t; cin>>t;
    while (t--)
    {
        adjlist.clear();
        int n,e,t,m;
        int a,b,w;
        int nb=0;
        cin>>n>>e>>t>>m;
        adjlist.resize(n+1);
        for(int i =0;i<m;i++)
        {
            cin>>a>>b>>w;
            adjlist[a].push_back(make_pair(b,w));
        }
        for(int s=1;s<n+1;s++)
        {
            vector<int> dist(n+1,+100000);
            dist[s]=0;
            priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
            pq.push(make_pair(0,s));
            while(!pq.empty())
            {
                pair<int,int> f =  pq.top();
                pq.pop();
                int d = f.first,u=f.second;
                if(d>dist[u])continue;
                for(int j=0;j< adjlist[u].size();j++)
                {
                    pair<int,int> v =adjlist[u][j];
                    if(dist[u]+v.second < dist[v.first])
                    {
                        dist[v.first]=dist[u]+v.second;
                        pq.push(make_pair(dist[v.first],v.first));
                    }
                }
            }
            if(dist[e]<=t)
                nb++;
        }
        printf("%d\n", nb);

        if(t)printf("\n");

    }
return 0 ;
}
