#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

vector<vi> adjList;
vi ts;
int dfs_num[10000];

int dfs(int u)
{
dfs_num[u]=0;
for(int i=0;i<adjList[u].size();i++)
{
    int v =adjList[u][i];
    if(dfs_num[v]==-1)
        dfs(v);
}
ts.push_back(u);
}

int main()
{
    freopen("file","r",stdin);
    int v,e,v1,v2;
    cin>>v>>e;
    while(v&&e)
    {
        adjList.resize(v+1);
        memset(dfs_num,-1,sizeof dfs_num);
        for(int i=0;i<e;i++)
        {
            cin>>v1>>v2;
            adjList[v1].push_back(v2);
        }

        for(int i=1;i<=v;i++)
            if(dfs_num[i]==-1)
                dfs(i);
        for(int i=v-1;i>=0;i--)
            cout<<ts[i]<<" ";
        cout<<endl;
        cin>>v>>e;
        adjList.clear();
        ts.clear();
    }
    return 0;
}
