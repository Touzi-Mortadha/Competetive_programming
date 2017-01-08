#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adjList;
int v,e,v1,v2;

void priint()
{
for(int i=0;i<v;i++)
    {
    cout<<i<<"-->  ";
    for(int j=0;j<adjList[i].size();j++)
        cout<<" "<<adjList[i][j];
    cout<<endl;
    }

}


int main()
{
    freopen("input","r",stdin);
    freopen("w","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        int n=1;
        int paire=1,impair=0;
        cin>>v;
        cin>>e;
        adjList.resize(v);
        for(int i=0;i<e;i++)
        {
            cin>>v1>>v2;
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1);
        }
        //priint();
        queue<int> q;
        q.push(0);
        int all=0;
        vector<int> color(v,-10000);
        color[0]=0;
        while(n>=1 && (!q.empty() || n < v ))
        {
            if(q.empty())
                {
                    int a=-1;
                    for(int i=0;i<v;i++)
                        if(color[i]==-10000)
                            {(impair!=0) ? all+=min(paire,impair) : all+=paire;a=i;q.push(a);paire=1;impair=0;color[a]=0;break;}
                    if(a==-1)
                        break;
                }
            int v=q.front();q.pop();
            for(int i=0;i<adjList[v].size();i++)
            {
                if(color[adjList[v][i]]==-10000)
                    {
                        n++;
                        color[adjList[v][i]]=1-color[v];
                        q.push(adjList[v][i]);
                        if((1-color[v])%2==0)
                            paire+=1;
                        else
                            impair+=1;
                    }
                else if(color[adjList[v][i]]==color[v])
                    {
                        n=-1;
                        break;
                    }
            }
        }
        (impair!=0) ? all+=min(paire,impair) : all+=paire;
        if(n!=-1)
            {
            cout<<all<<endl;
            }
        else
            cout<<-1<<endl;
        adjList.clear();
    }
    return 0;
}
