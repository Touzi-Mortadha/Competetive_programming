#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vector<int> > AdjList;
int dfs_low,dfs_num;
void articulationPointAndBridge(int u)
{
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
        {
            dfs_parent[v.first] = u;
            if (u == dfsRoot) rootChildren++;
            articulationPointAndBridge(v.first);
            if (dfs_low[v.first] >= dfs_num[u])
            articulation_vertex[u] = true;
            if (dfs_low[v.first] > dfs_num[u])
            printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }
        else if (v.first != dfs_parent[u])
        dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
}



int main()
{
    int V,E, v1, v2;
    cin>>V;
    AdjList.resize(v+1);
    cin>>E;
    for (int i = 1; i <= E; ++i)
    {
        cin>>v1>>v2;
        AdjList[v1].push_back(v2);
    }

    dfsNumberCounter = 0; dfs_num.assign(V, UNVISITED);
    dfs_low.assign(V, 0);
    dfs_parent.assign(V, 0);
    articulation_vertex.assign(V, 0);
    for (int i = 0; i < V; i++)
        if (dfs_num[i] == UNVISITED)
        {
        dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
        articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    printf("Articulation Points:\n");
    for (int i = 0; i < V; i++)
    if (articulation_vertex[i])
    printf(" Vertex %d\n", i);
    return 0;
}
