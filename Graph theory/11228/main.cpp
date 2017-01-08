#include<bits/stdc++.h>
#define EPS 1e-10
using namespace std;

class UnionFind
{
    vector<int> p,rank;
public:
    UnionFind(int v)
    {
        rank.assign(v,0);
        p.assign(v,0);
        for(int i =0; i<v; i++)
            p[i]=i;
    }
    int findSet(int i)
    {
        return (p[i]==i)? i: p[i]=findSet(p[i]);
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

double dist(pair<int,int> p1,pair<int,int> p2)
{
    return sqrt(pow(fabs(p2.first-p1.first),2)+pow(fabs(p2.second-p1.second),2) );
}

int main()
{
    freopen("i","r",stdin);
    freopen("w","w",stdout);
    //ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    pair<int,int> points_cord[100000];
    for(int i=1; i<=t; i++)
    {
        int v,r,x,y;
        pair<int,int> point;
        vector<pair<double,pair<int,int> > > edgeList;
        //cin>>v>>r;
        scanf("%d %d",&v,&r);
        for(int j=0;j<v;j++)
        {
            scanf("%d %d",&points_cord[j].first,&points_cord[j].second);
            //cin>>points_cord[j].first>>points_cord[j].second;
            for(int k=0;k<j;k++)
            {
                double dis=dist(points_cord[j],points_cord[k]);
                edgeList.push_back(make_pair(dis,make_pair(j,k)));
            }
        }
        sort(edgeList.begin(),edgeList.end());
        int E=edgeList.size();
        int state=v;
        double rail=0,road=0;
        UnionFind UF(v);
        for(int k=0;k<E;k++)
        {
            pair<double,pair<int,int> > fron = edgeList[k];
            if(!UF.isSameSet(fron.second.first,fron.second.second))
            {
                if(fron.first<=r)
                    {
                        road+=fron.first;
                        state--;
                    }
                else
                    rail+=fron.first;
                UF.UnionSet(fron.second.first,fron.second.second);
            }
        }
        printf("Case #%d: %d %d %d\n",i,state,(int)round(road),(int)round(rail));
        //cout<<"Case #"<<i<<": "<<state<<" "<<(int)round(road)<<" "<<(int)round(rail)<<endl;
    }
    return 0;
}
