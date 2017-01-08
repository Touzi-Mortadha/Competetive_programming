#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef unsigned long long ull;
vector<vii> AdjList;

int main()
{
        ull E;
        ull v1;
        cin>>E;
        vector<vii> AdjList(E+1);
        for(int i=0;i<= E-1;i++)
        {
            int n;
            cin>>n;
            for(int j=0;j<n;j++)
                {
                    cin>>v1;
                    AdjList[i].push_back(make_pair(v1,0));
                }
        }
        int t;
        cin>>t;
        while(t--)
        {
            int s;
            cin>>s;
            vi d(E+1,-1); d[s] = 0;
            queue<int> q; q.push(s);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++)
                {
                    ii v = AdjList[u][j];
                    if (d[v.first] == -1)
                    {
                        d[v.first] = d[u] + 1;
                        q.push(v.first);
                    }
                }
            }
            int maxi=d[E-1],maxii;
            int n = 1,nmaxi=1;
            if(maxi != -1 && maxi != 0)
                {
                    for(int i =E-2;i>=0;i--)
                        {
                            if(d[i]==maxi)
                                n++;
                            else if( n> nmaxi)
                                {
                                    nmaxi=n;
                                    maxii=maxi;
                                    maxi=d[i];
                                }
                        }
                    cout<<nmaxi<<" "<<maxii<<endl;
                }
            else
                cout<<0<<endl;
        }
    return 0;
}
