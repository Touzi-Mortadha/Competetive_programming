#include <bits/stdc++.h>

using namespace std;

map<string,vector<string> > adjlist;
map<string,int> visited;



int bfs(string start,string to)
{
    queue<string> s;
    s.push(start);
    visited[start]=0;
    while(!s.empty())
    {
        start=s.front();
        s.pop();
        if(start==to)
            return visited[start];
        for(int i=0;i<adjlist[start].size();i++)
        {
            string u = adjlist[start][i];
            if(!visited.count(u))
            {
                visited[u]=visited[start]+1;
                s.push(u);
            }
        }
    }
}

int main()
{
   // freopen("i","r",stdin);
   // freopen("w","w",stdout);
   // ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s ,compare_strin;
    while(n--)
    {
        adjlist.clear();
        visited.clear();
        map<string,vector<string> >::iterator it ;
        while(cin>>s && s[0]!='*')
        {
            adjlist[s];
            int dif=0;
            for(it=adjlist.begin(); it!=adjlist.end(); ++it)
            {
                compare_strin=(*it).first;
                if(compare_strin.size()==s.size())
                {
                    int dif=0;
                    for(int i=0; i<s.size(); i++)
                    {
                        if(compare_strin[i]!=s[i])
                        {
                            dif++;
                            if(dif>1)
                            break;
                        }
                    }
                    if(dif==1)
                        {
                            adjlist[s].push_back(it->first);
                            adjlist[it->first].push_back(s);
                        }
                }
            }
        }
        string line;
        getline(cin,line);
        while(getline(cin,line) && line !="")
        {
            istringstream iss(line);
            string start, to;
            iss>>start>>to;
            cout<<start<<" "<<to<<" "<<bfs(start,to)<<endl;
        }
        if(n)cout<<endl;
    }
    return 0;
}
