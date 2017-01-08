#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> AdjList;

int main()
{
    int V,E, v1, v2, weight=6;
    int T;
    cin>>T;
    while(T--)
    {
        int s;
        cin>>V;
        cin>>E;
        AdjList(V+1);
        for (int i = 1; i <= E; ++i)
        {
            cin>>v1>>v2;
            AdjList[v1].push_back(make_pair(v2, weight));
        }
        cin>>s;

    ////////////////BFS/////////////////////////
        vi d(V+1,-1); d[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                if (d[v.first] == -1)
                {
                    d[v.first] = d[u] + 6;
                    q.push(v.first);
                }
            }
        }

        for(int i=1;i<d.size();i++)
            if(d[i]!=0)
                cout<<d[i]<<" ";
        cout<<endl;
    }

    return 0;
}

