#include <bits/stdc++.h>
#define EPS 1e-11
using namespace std;
int number_count;
class UnionFind
{
private:
    vector<int> p,rank;
public:
    UnionFind(int v)
    {
        number_count=v;
        rank.assign(v,0);
        p.assign(v,0);
        for(int i=0; i<v; i++)p[i]=i;
    }
    int findset(int i)
    {
        return (p[i]==i)?i:p[i]=findset(p[i]);
    }
    bool issameset(int i,int j)
    {
        return findset(i)==findset(j);
    }
    void UnionSet(int i,int j)
    {
        if(!issameset(i,j))
        {
            number_count--;
            int x=findset(i),y=findset(j);
            if(rank[x]>rank[y])
                p[y]=x;
            else
            {
                p[x]=y;
                if(rank[y]==rank[x])
                    rank[x]++;
            }
        }
    }

};

double dist(int x1 ,int y1,int x2,int y2 )
{
    return sqrt(fabs(x2-x1)*fabs(x2-x1)+fabs(y2-y1)*fabs(y2-y1));
}

int main()
{
    freopen("input.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > liste ;
        int s,p,x,y;
        cin>>s>>p;
        for(int i =0; i<p; i++)
        {
            cin>>x>>y;
            liste.push_back(make_pair(x,y));
        }
        vector<pair<double,pair<int,int> > > EdgeList;
        for(int i=0; i<p; i++)
        {
            int a=liste[i].first,b=liste[i].second;
            for(int j=i+1; j<p; j++)
            {
                EdgeList.push_back(make_pair(dist(a,b,liste[j].first,liste[j].second),make_pair(i,j)));
            }
        }
        sort(EdgeList.begin(),EdgeList.end());
        UnionFind A(p);
        double ans=0.0;
        for(int i=0; i<EdgeList.size(); i++)
        {
            if(number_count==s)break;
            if(!A.issameset(EdgeList[i].second.first,EdgeList[i].second.second))
            {
                A.UnionSet(EdgeList[i].second.first,EdgeList[i].second.second);
                ans=EdgeList[i].first;
            }
        }
        printf("%.2lf\n", ans);


    }


    return 0;
}
