#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("i","r",stdin);
    int R,C,bombs,l,c,n,k;
    vector<vector<int> > adjlist;
    cin>>R>>C;
    cin>>bombs;
    adjlist.resize(R+1);

    for(int i=0; i<R; i++)
        {
            adjlist[i].push_back(0);
            for(int j=1; j<=C; j++)
                adjlist[i].push_back(j-1);
        }

    for(int i=0; i<R; i++)
    {
        cout<<i<<"  --> ";
        for(int j=0;j<adjlist[i].size();j++)
            cout<<adjlist[i][j+1]<<" ";
        cout<<endl;
    }
    cout<<" ------------------------------------------ "<<endl;
    for(int i=0; i<bombs; i++)
    {
        cin>>l>>n;
        for(int j=0; j<n; j++)
        {
            cin>>c;
            adjlist[l].erase(adjlist[l].begin()+c+1-adjlist[l][0]);
            adjlist[l][0]+=1;
        }
    }


    for(int i=0; i<R; i++)
    {
        cout<<i<<"  --> ";
        for(int j=0;j<adjlist[i].size();j++)
            cout<<adjlist[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
