#include <bits/stdc++.h>
#define INF 10000
using namespace std;

vector<vector<int> > adjlist;
vector<int> visited;

void bfs(int u)
{
    if(adjlist[u].size()==0)
        cout<<"0"<<endl;
    else
    {
        int max_daily_boom=-10000,first_boom_day=0;
        first_boom_day=adjlist[u].size();
        visited[u]=0;
        queue<int> q;
        map<int,int> m;
        q.push(u);
        while(!q.empty())
        {
            int v=q.front();
            q.pop();
            for(int i=0; i<adjlist[v].size(); i++)
            {
                if(visited[adjlist[v][i]]==INF)
                {
                    visited[adjlist[v][i]]=visited[v]+1;
                    m[visited[v]+1]++;
                    q.push(adjlist[v][i]);
                }
            }
        }
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();++it)
            if(it->second>max_daily_boom)
                {
                    max_daily_boom=it->second;
                    first_boom_day=it->first;
                }
        cout<<max_daily_boom<<" "<<first_boom_day<<endl;
    }
}


int main()
{
    //freopen("i","r",stdin);
    //freopen("w","w",stdout);
    int n;
    cin>>n;
    adjlist.resize(n);
    for(int j=0; j<n; j++)
    {
        int frien,x;
        cin>>frien;
        for(int i=0; i<frien; i++)
        {
            cin>>x;
            adjlist[j].push_back(x);
        }
    }
    /*
    for(int i=0; i<n; i++)
    {
        cout<<i<<" --> ";
        for(int j=0; j<adjlist[i].size(); j++)
            cout<<adjlist[i][j]<<" ";
        cout<<endl;
    }
    cout<<"********"<<endl;
    */
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        visited.clear();
        visited.assign(n,INF);
        int queries;
        cin>>queries;
        bfs(queries);

    }
    return 0;
}
