#include <bits/stdc++.h>

using namespace std;
vector<vector<int> > adjlist,affich;
int n,a;
int dfs_num[10000];
vector<pair<int,int> > ts;
map<int,int> mmm;

bool sorted(pair<int,int> a,pair<int,int> b)
{
if(a.first<b.first)
    return true;
else if (a.first>b.first);
    return false;
return a.second < b.second;

}

void prinnt()
{
for(int i=1;i<=n;i++)
    {
        cout<<i<<"-->  ";
        for(int j=0;j<adjlist[i].size();j++)
            cout<<adjlist[i][j]<<" ";
        cout<<endl;
    }

}

void prinnt_ts()
{
for(int i=ts.size()-1;i>=0;i--)
    cout<<ts[i].second<<" ";
cout<<endl;
}

int dfs(int u)
{
int s=a;
dfs_num[u]=0;
for(int i=0;i<adjlist[u].size();i++)
{
    int v =adjlist[u][i];
    if(dfs_num[v]==-1)
        dfs(v);
    else
        a+=mmm[adjlist[u][i]];

}
a++;
cout<<a<<"   "<<u<<endl;
ts.push_back(make_pair(a,u));
affich[s].push_back(u);
mmm[u]=a;
}

int main()
{
    freopen("file","r",stdin);
    string s,v1,v2;
    vector<string> ss;
    map<string,int> mm;
    map<int,string> mm2;
    int co=1;
    while(cin>>n)
        {
            adjlist.resize(n+1);
            affich.resize(n);
            ts.clear();
            for(int i=1;i<=n;i++)
                {cin>>s;mm[s]=i;mm2[i]=s;}
            int m;
            cin>>m;
            memset(dfs_num,-1,sizeof dfs_num);
            for(int j=0;j<m;j++)
            {
                cin>>v1;
                cin>>v2;
                adjlist[mm[v1]].push_back(mm[v2]);
            }
            prinnt();
            for(int i=1;i<=n;i++)
                if(dfs_num[i]==-1)
                    {
                        a=0;dfs(i);
                    }
           // sort(ts.begin(),ts.end(),sorted);
            cout<<"Case #"<<co<<": Dilbert should drink beverages in this order: ";
            for(int i=ts.size()-1;i>=0;i--)
                cout<<mm2[ts[i].second]<<" ";
            cout<<endl;

/*
            for(int i=0;i<n;i++)
            {
                cout<<i<<"-->  ";
                for(int j=0;j<affich[i].size();j++)
                    cout<<affich[i][j]<<" ";
                cout<<endl;
            }
            */
            co++;
            adjlist.clear();
            affich.clear();
        }
    return 0;
}
