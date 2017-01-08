#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adjList,mm;
vector<int> dfs_low,dfs_num,dfs_parent;
vector<bool> articulation_vertex;
int dfsNumCounter,n=0;

void articulationPoint(int u)
{
    dfs_low[u]=dfs_num[u]=dfsNumCounter++;
    for(int i=0;i<adjList[u].size();i++)
    {
        if(dfs_num[adjList[u][i]]==-10000)
        {
            dfs_parent[adjList[u][i]]=u;
            articulationPoint(adjList[u][i]);
            if(dfs_low[adjList[u][i]]>dfs_num[u])
                //printf("Edge (%d, %d) is a bridge\n", u, adjList[u][i]);
                {
                if(u<adjList[u][i])
                    mm[u].push_back(adjList[u][i]);
                else
                    mm[adjList[u][i]].push_back(u);
                n++;
                }
            dfs_low[u]=min(dfs_low[u],dfs_low[adjList[u][i]]);
        }
        else if(adjList[u][i] != dfs_parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[adjList[u][i]]);
    }
}


int main()
{
    freopen("input","r",stdin);
    //freopen("w","w",stdout);
    //ios_base::sync_with_stdio(false);
    int v,e,v1,v2;
    while(cin>>v)
    {
        adjList.resize(v);
        mm.resize(v);
        for(int i=0;i<v;i++)
        {
        scanf("%d (%d)",&v1,&e);
        for(int j=0;j<e;j++)
            {
                cin>>v2;
                adjList[v1].push_back(v2);
            }
        }

        dfsNumCounter=0;dfs_num.assign(v+1,-10000);dfs_low.assign(v+1,0);dfs_parent.assign(v+1,0);
        for(int i=0;i<v;i++)
            if(dfs_num[i]==-10000)
                articulationPoint(i);
        cout<<n<<" critical links"<<endl;
        for(int i=0;i<v;i++)
        {
            sort(mm[i].begin(),mm[i].end());
            for(int j=0;j<mm[i].size();j++)
                cout<<i<<" - "<<mm[i][j]<<endl;
        }
        cout<<endl;
    mm.clear();
    n=0;
    adjList.clear();
    }
    return 0;
}
