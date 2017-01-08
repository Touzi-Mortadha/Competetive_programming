#include <bits/stdc++.h>

using namespace std;
#define Unvisited 1000000

vector<char> elements;
vector<char>  output;
vector<vector<char> > adjlist;
int ok;
int dfs_num[256];


void prinnt()
{
    cout<<output[0];
    for(int i=1; i<output.size(); i++)
        cout<<" "<<output[i];
    cout<<endl;
    ok=0;
}


void dfs(char u)
{
    dfs_num[(int)u]=0;
    output.push_back(u);
    if(output.size()==elements.size())
        prinnt();
    for(int j=0; j<elements.size(); j++)
    {
        if(dfs_num[elements[j]])
        {
            for(int i=0; i<adjlist[elements[j]].size(); i++)
            {
                if(!dfs_num[adjlist[elements[j]][i]])
                {
                    output.pop_back();
                    return;
                }
            }
            dfs(elements[j]);
            dfs_num[elements[j]]=1;
        }
    }
    output.pop_back();
    dfs_num[u]=1;
}

int main()
{
    freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    string s1,s2;
    getline(cin,s1);
    while(t--)
    {
        char c,a,b ;
        elements.clear();
        adjlist.clear();
        getline(cin,s1);
        adjlist.resize(256);
        getline(cin,s1);
        istringstream iss(s1);
        while(iss>>c)
            elements.push_back(c);
        sort(elements.begin(),elements.end());
        getline(cin,s2);
        istringstream iss1(s2);
        while(iss1>>a>>b>>c)
        {
            adjlist[a].push_back(c);
        }
        ok=1;
        for(int i=0; i<elements.size(); i++)
        {
            output.clear();
            for(int j=0; j<256; j++)
                dfs_num[j]=1;
            dfs(elements[i]);
        }
        if(ok)
            cout<<"NO"<<endl;
        if(t)
            cout<<endl;
    }
    return 0;
}



