#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adjList;
vector<int> dfs_low,dfs_num,dfs_parent;
vector<bool> articulation_vertex;
int dfsNumCounter,dfsRoot,RootChildren;

void articulationPoint(int u)
{
    dfs_low[u]=dfs_num[u]=dfsNumCounter++;
    for(int i=0;i<adjList[u].size();i++)
    {
        if(dfs_num[adjList[u][i]]==-10000)
        {
            dfs_parent[adjList[u][i]]=u;
            if(u==dfsRoot) RootChildren++;
            articulationPoint(adjList[u][i]);
            if(dfs_low[adjList[u][i]]>=dfs_num[u])
                articulation_vertex[u]=true;
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
    int v,e,v1,v2;
    string s ;
    while(cin>>v && v!=0)
    {
        int n=0;
        adjList.resize(v+1);
        while(cin>>v1 && v1 !=0)
        {
            getline(cin,s);
            istringstream iss(s);
            while(iss>>v2)
                {adjList[v1].push_back(v2);adjList[v2].push_back(v1);}
        }
        dfsNumCounter=0;dfs_num.assign(v+1,-10000);dfs_low.assign(v+1,0);dfs_parent.assign(v+1,0);
        articulation_vertex.assign(v+1,false);
        for(int i=1;i<=v;i++)
            if(dfs_num[i]==-10000)
                {
                    dfsRoot=i;RootChildren=0;articulationPoint(i);
                    articulation_vertex[i]=(RootChildren> 1);
                }
            for(int i=1;i<v+1;i++)
                if(articulation_vertex[i])
                    n++;
        cout<<n<<endl;
        adjList.clear();
    }

    return 0;
}
