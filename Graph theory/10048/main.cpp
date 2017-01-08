#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int,int> > > adjList;

class UnionFind
{
    vector<int> p,rank;
public:
    UnionFind(int v)
    {
        rank.assign(v,0);
        p.assign(v,0);
        for(int i=0; i<v; i++)p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i]==i)?i:p[i]=findSet(p[i]);
    }
    bool isSameSet(int i,int j)
    {
        return findSet(i)==findSet(j);
    }
    void UnionSet(int i,int j)
    {
        if(!isSameSet(i,j))
        {
            int x=findSet(i),y=findSet(j);
            if(rank[x]>rank[y])
                p[y]=x;
            else
            {
                p[x]=y;
                if(rank[x]==rank[y])
                    rank[y]++;
            }

        }
    }
};

int max1=-1;
int ok=0;
int dfs_num[101];
void dfs(int u,int arrive, int m)
{
    int maxi=-1;
    dfs_num[u]=1;
    for(int i=0; i<adjList[u].size(); i++)
    {
        pair<int,int> v=adjList[u][i];
        if(!dfs_num[v.first])
        {
            maxi=max(m,v.second);
            if(v.first==arrive)
            {
                max1=max(max1,maxi);
                ok=1;
                break;
            }
            if(ok)
                break;
            dfs(v.first,arrive,maxi);
        }
    }
}

int main()
{
    freopen("i","r",stdin);
    freopen("w","w",stdout);
    //ios_base::sync_with_stdio(false);
    int v,e,q;
    int m=0;
    while(scanf("%d %d %d",&v,&e,&q) && v && e && q)
    {
        adjList.clear();
        if(m)
            printf("\n");
        m++;
        int a,b,w;
        vector<pair<int,pair<int,int> > > edgeList;
        adjList.resize(v+1);
        for(int i=0; i<e; i++)
        {
            scanf("%d %d %d",&a,&b,&w);
            edgeList.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(edgeList.begin(),edgeList.end());
        UnionFind Uf(v+1);
        for(int i=0; i<e; i++)
        {
            pair<int,pair<int,int> > fron=edgeList[i];
            if(!Uf.isSameSet(fron.second.first,fron.second.second))
            {
                adjList[fron.second.first].push_back(make_pair(fron.second.second,fron.first));
                adjList[fron.second.second].push_back(make_pair(fron.second.first,fron.first));
                Uf.UnionSet(fron.second.first,fron.second.second);
            }
        }

        /*
                for(int i=1;i<=v;i++)
        	    {
        		cout<<i<<" -->  ";
        		for(int j=0;j<adjList[i].size();j++)
        		    cout<<adjList[i][j].first<<" "<<adjList[i][j].second<<"   ----   ";
        		cout<<endl;
        	    }
        	    cout<<endl;
        */
        max1=-1;
        int u,v;
        printf("Case #%d\n",m);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&u,&v);
            max1=-1;
            ok=0;
            memset(dfs_num,0,sizeof dfs_num);
            dfs(u,v,-1);
            if(max1 !=-1)
                printf("%d\n",max1);
            else
                printf("no path\n");
        }
    }
    return 0;
}
