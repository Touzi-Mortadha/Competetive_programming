#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector<vii> AdjList;

int main()
{
    int V,E, v1, v2, weight;
    cout<< "Enter the Number of Vertices"<<endl;
    cin>>V;
    vector<vii> AdjList(V+1);
    cout<<"Enter the Number of Edges"<<endl;
    cin>>E;

    cout<<"Enter the Edges V1 -> V2, of weight W"<<endl;

    for (int i = 1; i <= E; ++i)
    {
        cin>>v1>>v2>>weight;
        AdjList[v1].push_back(make_pair(v2, weight));
    }
////////////////BFS/////////////////////////
/*
    vi d(V,-1); d[s] = 0;
    queue<int> q; q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ii v = AdjList[u][j];
            if (d[v.first] == INF)
            {
                d[v.first] = d[u] + 1;
                q.push(v.first);
            }
        }
    }
*/

    cout<<"\nThe Adjacency List"<<endl;

    for (int i = 1; i < AdjList.size(); ++i)
    {
        printf("adjacencyList[%d] ", i);

        vii::iterator itr = AdjList[i].begin();

        while (itr != AdjList[i].end()) {
            printf(" -> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }

    return 0;
}

