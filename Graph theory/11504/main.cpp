#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > adjList,sorti;
int e,v,dfsNumber,n;
vector<int> dfs_num,dfs_low,visited,S;

void tarjanSCC(int u)
{
    dfs_low[u]=dfs_num[u]=dfsNumber++;
    S.push_back(u);
    visited[u]=1;
    for(int i=0;i<adjList[u].size();i++)
    {
        int a=adjList[u][i];
        if(dfs_num[a]==-1)
            tarjanSCC(a);
        if(visited[a]==1)
            dfs_low[u]=min(dfs_low[u],dfs_low[a]);
    }
    if(dfs_low[u]==dfs_num[u])
    {
        while(1)
        {
            int a=S.back();
            S.pop_back();visited[a]=0;
            if(u==a) break;
        }
        n++;
        cout<<u<<endl;
    }
}

int main()
{
    freopen("in","r",stdin);
    ios_base::sync_with_stdio(false);
    int T=0,v1,v2;
    cin>>T;
    while(T--)
    {
        n=0;
        cin>>v>>e;
        dfs_low.assign(v+1,0);
        dfs_num.assign(v+1,-1);
        visited.assign(v+1,0);
        adjList.resize(v+1);
        for(int i=0;i<e;i++)
        {
            cin>>v1>>v2;
            adjList[v1].push_back(v2);
        }
        for(int i=1;i<=v;i++)
        {
        cout<<i<<"--> ";
        for(int j=0;j<adjList[i].size();j++)
            cout<<adjList[i][j]<<"  ";
        cout<<endl;
        }

        cout<<"yew"<<endl;
        for(int i=1;i<=v;i++)
            if(dfs_num[i]==-1)
                tarjanSCC(i);
        cout<<n<<endl;
        adjList.clear();
        S.clear();

    }
    return 0;
}
