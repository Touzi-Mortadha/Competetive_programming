#include<bits/stdc++.h>

using namespace std;
vector<vector<int> > adjList,sorti;
map<int,string> mm;
map<string,int> mm1;
string v1,v2;
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
        int a=S.back();
        S.pop_back();visited[a]=0;
        cout<<mm[a];
        if(u==a){n++;cout<<endl;return;}
        while(1)
        {
            int a=S.back();
            S.pop_back();visited[a]=0;
            cout<<", "<<mm[a];
            if(u==a) break;
        }
        cout<<endl;
        n++;
    }
}

int main()
{
    freopen("in","r",stdin);
    ios_base::sync_with_stdio(false);
    int conter=1;
    while(cin>>v>>e && v!=0)
    {
    if(conter>1)
    cout<<endl;
    cout<<"Calling circles for data set "<<conter++<<":"<<endl;
    int c=1;
        n=0,dfsNumber=0;;
        dfs_low.assign(v+1,0);
        dfs_num.assign(v+1,-1);
        visited.assign(v+1,0);
        adjList.resize(v+1);
        for(int i=0;i<e;i++)
        {
            cin>>v1>>v2;
            if(mm1.count(v1)==0)
                {mm[c]=v1;mm1[v1]=c++;}
            if(mm1.count(v2)==0)
                {mm[c]=v2;mm1[v2]=c++;}
            adjList[mm1[v1]].push_back(mm1[v2]);
        }
        for(int i=1;i<=v;i++)
            if(dfs_num[i]==-1)
                tarjanSCC(i);
        mm.clear();
        mm1.clear();
        adjList.clear();
        S.clear();

    }
    return 0;
}
