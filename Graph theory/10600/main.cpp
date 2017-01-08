#include <bits/stdc++.h>

using namespace std;

class UnionFind                                                // OOP style
{
private:
    vector<long> p, rank, setSize;                       // remember: vi is vector<int>
    int numSets;
public:
    UnionFind(int N)
    {
        setSize.assign(N, 1);
        numSets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++) p[i] = i;
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            numSets--;
            int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y])
            {
                p[y] = x;
                setSize[x] += setSize[y];
            }
            else
            {
                p[x] = y;
                setSize[y] += setSize[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
    int numDisjointSets()
    {
        return numSets;
    }
    int sizeOfSet(int i)
    {
        return setSize[findSet(i)];
    }
};
bool operateur(int x,int y)
{return x<=y;}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int E,V,e1,e2,c;
        cin>>V>>E;
        vector<pair<int,pair<int,int> > >  Edge;
        for(int i =0; i<E; i++)
        {
            cin>>e1>>e2>>c;
            Edge.push_back(make_pair(c,make_pair(e1,e2)));
        }
        sort(Edge.begin(),Edge.end());
        vector<int> vv;
        long cost=0,cost2=0,mini=1000000;
        UnionFind A(E+1);
        for(int i=0; i<E; i++)
        {
            if(!A.isSameSet(Edge[i].second.first,Edge[i].second.second))
            {
                cost+=Edge[i].first;
                A.unionSet(Edge[i].second.first,Edge[i].second.second);
                vv.push_back(i);
            }
        }
        cout<<cost<<" ";
        for(int j=0; j<vv.size(); j++)
        {
            UnionFind B(E+1);
            cost2=0;
            for(int i=0; i<E; i++)
            {
                if(i!=vv[j])
                {
                if(!B.isSameSet(Edge[i].second.first,Edge[i].second.second))
                {
                    cost2+=Edge[i].first;
                    B.unionSet(Edge[i].second.first,Edge[i].second.second);
                }
                }

            }
            if(cost2>=cost && cost2<mini)
                mini=cost2;
        }
        cout<<mini<<endl;
    }
    return 0;
}
