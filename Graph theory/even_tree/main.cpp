#include<bits/stdc++.h>
#define VISITED 1
#define UNVISITED 0
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> AdjList;

vi dfs_num;
int k=0;
int dfs(int u)
{
    int i=1;
    dfs_num[u] = VISITED;
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == UNVISITED)
            {i+=dfs(v.first);}
    }
    if(i%2==0 && u!=1)
            {k++;}
    return i;

}



int main()
{
    int V,E, v1, v2;
    cin>>V;
    dfs_num.resize(V+1,0);
    AdjList.resize(V+1);
    cin>>E;
    for (int i = 1; i <= E; ++i)
    {
        cin>>v1>>v2;
        AdjList[v1].push_back(make_pair(v2,1));
        AdjList[v2].push_back(make_pair(v1,1));
    }
    dfs(1);
    cout<<k<<endl;
    return 0;
}
