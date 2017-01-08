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

int main()
{
    int V=100, E=100, v1, v2, weight=0;
    int T;
    cin>>T;
    while(T--)
    {
    vector<vii> AdjList(101);
    int N,M,ok=1;
    cin>>N;

    for (v1 = 1; v1 <= E; v1++)
    {
        for (v2 =v1+1 ; v2 <= v1+6; v2++)
        {
            if(v2>100)
                break;
            AdjList[v1].push_back(make_pair(v2, weight));
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        int k=6;
        cin>>v1>>v2;
        AdjList[v1].clear();
        for(int j=v1-7;j<v1;j++)
        {
            if(j>=1)
                AdjList[j][k--]=make_pair(v2, weight);
            else
                k--;
        }
    }

    cin>>M;
    for (int i = 1; i <= M; ++i)
    {
        int k=6;
        cin>>v1>>v2;
        AdjList[v1].clear();
        for(int j=v1-7;j<v1;j++)
        {
            if(j>=1)
                AdjList[j][k--]=make_pair(v2, weight);
            else
                k--;
        }
    }

    for (int i = 1; i < AdjList.size(); ++i)
    {
        printf("AdjList[%d] ", i);

        vii::iterator itr = AdjList[i].begin();

        while (itr != AdjList[i].end())
        {
            printf(" -> %d(%d)", (*itr).first, (*itr).second);
            ++itr;
        }
        printf("\n");
    }


///////////////BFS//////////////
    vi d(V+1,-1); d[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++)
        {
            ii v = AdjList[u][j];
            if (d[v.first] == -1)
            {
                    d[v.first] = d[u] + 1;
                q.push(v.first);
            }
        }
    }
cout<<d[100]<<endl;
}

    return 0;
}

