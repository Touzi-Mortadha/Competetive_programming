#include <bits/stdc++.h>

using namespace std;
class UFDS
{
private:
    vector<int> p,rank;
public:
    UFDS(int N)
    {
        p.assign(N,0);rank.assign(N,0);for(int i=0;i<N;i++)p[i]=i;
    }
    void affiche(int i) {cout<<p[i]<<endl;}
    int FS(int i) {return (p[i]==i)  ? i : p[i]=FS(p[i]);}
    bool isSameSet(int i,int j){return FS(i)== FS(j);}
    void UnionSet(int i, int j)
    {
        if(!isSameSet(i,j))
            {
                int x=FS(i),y=FS(j);
                if(rank[x]>rank[y]) p[y]=x ;
                else
                {
                    p[x]=y;
                    if(rank[x] == rank[y]) rank[y]++;
                }

            }
    }

};

int main()
{
    UFDS U(5);
    U.UnionSet(0,1);
    U.UnionSet(2,3);
    U.UnionSet(4,3);
    U.affiche(0);
    cout<<"  "<<U.FS(4)<<endl;
    U.UnionSet(0,4);
    U.affiche(0);

    return 0;
}
