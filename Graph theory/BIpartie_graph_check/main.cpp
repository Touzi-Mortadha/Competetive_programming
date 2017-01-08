#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adjList;
int E,V,v1,v2;

void priint()
{
for(int i=0;i<V;i++)
    {
    cout<<i<<"-->  ";
    for(int j=0;j<adjList[i].size();j++)
        cout<<" "<<adjList[i][j];
    cout<<endl;
    }

}


int main()
{
    //freopen("input","r",stdin);
    //freopen("out","w",stdout);
    while(cin>>V && V!=0)
    {
        cin>>E;
        adjList.resize(V);
        for(int i=0;i<E;i++)
        {
            cin>>v1>>v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        priint();
        queue<int> q;
        vector<int> color(V,-10000);
        q.push(0);
        color[0]=0;
        bool IsBipartie=true;
        while(!q.empty() && IsBipartie)
        {
        int v=q.front();q.pop();
        for(int i=0;i<adjList[v].size();i++)
            if(color[adjList[v][i]]==-10000)
            {
                q.push(adjList[v][i]);
                color[adjList[v][i]]=1-color[v];
            }
            else if (color[adjList[v][i]]==color[v])
            {
                IsBipartie=false;break;
            }
        }
        if(IsBipartie)
            cout<<"BICOLORABLE."<<endl;
        else
            cout<<"NOT BICOLORABLE."<<endl;
        adjList.clear();
    }
    return 0;
}
