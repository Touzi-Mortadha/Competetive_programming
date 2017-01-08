#include <bits/stdc++.h>

using namespace std;

class UnionFind
{
private:
    vector<int> p,rank;
    int v;
public:
    UnionFind(int V)
    {
        p.assign(v,0);
        rank.assign(v,0);
        for(int i=0; i<v; i++)
        {
            p[i]=i;
        }
    }
    int findSet(int i) { return (p[i]==i)?i:p[i]=findSet(p[i]);}
    int isSameSet(int i,int j ){return findSet(i)==findSet(j);}
    void unionSet(int i,int j)
    {
        if(isSameSet(i,j))
            return;
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


};

int main()
{
  //  freopen("i","r",stdin);
   // freopen("w","w",stdout);
    ios_base::sync_with_stdio(false);
    int e,v;
    while(cin>>v>>e && e && v)
    {
        int w,a,b;
        vector< pair<int , pair<int,int>  > > edgeList;
        for(int i=0; i<e; i++)
        {
            cin>>a>>b>>w;
            edgeList.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(edgeList.begin(),edgeList.end());
        UnionFind UF(v);
        int cost=0;
        for(int i=0; i<e; i++)
        {
            pair<int,pair<int,int> > fron = edgeList[i];
            if(!UF.isSameSet(fron.second.first,fron.second.second))
            {
                UF.unionSet(fron.second.first,fron.second.second);
            }
            else
                cost+=fron.first;
        }
        cout<<cost<<endl;
    }
    return 0;
}
