#include <bits/stdc++.h>

using namespace std;

class unionFind
{
    vector<int> rank,p;
public:
    unionFind(int v)
    {
        rank.assign(v,0);
        p.assign(v,0);
        for(int i=0; i<v; i++)
        {
            p[i]=i;
        }
    }
    int findSet(int i)
    {
        return (p[i]==i)?i:p[i]=findSet(p[i]);
    }
    bool isSameSet(int i,int j)
    {
        return findSet(i)==findSet(j);
    }
    void unionSet(int i,int j)
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




int main()
{
    freopen("i","r",stdin);
    freopen("w","w",stdout);
    int v,e;
    int a,b,w;
    while(cin>>v>>e && v)
    {
        vector<pair<int,pair<int,int> > > edgeList;
        for(int i=0; i<e; i++)
        {
            cin>>a>>b>>w;
            edgeList.push_back(make_pair(w,make_pair(a,b)));
        }
        sort(edgeList.begin(),edgeList.end());
        vector<int> heaviest_edge;
        unionFind UF(v);
        for(int i=0; i<e; i++)
        {
            pair<int,pair<int,int> > front= edgeList[i];
            if(!UF.isSameSet(front.second.first,front.second.second))
            {
                UF.unionSet(front.second.first,front.second.second);
            }
            else
                heaviest_edge.push_back(front.first);
        }
        if(heaviest_edge.size()>0)
        {
            sort(heaviest_edge.begin(),heaviest_edge.end());
            cout<<heaviest_edge[0];
            for(int i=1;i<heaviest_edge.size();i++)
                cout<<" "<<heaviest_edge[i];
            cout<<endl;
        }
        else
        {
            cout<<"forest"<<endl;
        }
    }
    return 0;
}
