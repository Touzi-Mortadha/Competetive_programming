#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("i","r",stdin);
    //freopen("o","w",stdout);
    int t;
    while(cin>>t && t)
    {
        string o,d,f,e,word;
        o.reserve(51);
        d.reserve(51);
        f.reserve(51);
        e.reserve(51);
        word.reserve(51);
        int k=0,out=-1;
        cin>>o>>d;
        map<string,int> m;
        vector<vector<pair<int,pair<string,bool> > > > adjlist;
        //adjlist.resize(2001);
        for(int i=0;i<t;i++)
        {
            cin>>f>>e>>word;
            if(m.find(f)==m.end())
            {
                m[f]=k++;
                adjlist.push_back(vector< pair<int, pair<string, bool> > > ());
            }
            if(m.find(e)==m.end())
            {
                m[e]=k++;
                adjlist.push_back(vector< pair<int, pair<string, bool> > > ());
            }
            adjlist[m[f]].push_back(make_pair(m[e],make_pair(word,false)));
            adjlist[m[e]].push_back(make_pair(m[f],make_pair(word,false)));
        }


        if(m.find(d)==m.end() ||  m.find(o)==m.end())
            {
                cout<<"impossivel"<<'\n';
            }
        else
        {
            priority_queue<  pair<pair<int,char>,int> , vector<pair<pair<int,char>,int> > , greater<pair<pair<int,char>,int> > > pq;
            pq.push(make_pair(make_pair(0,'A'),m[o]));
            while(!pq.empty())
            {
                pair<pair<int,char>,int> p=pq.top();pq.pop();
                int w = p.first.first;
                int u = p.second;
               if(u==m[d]) {out=p.first.first;break;}
                for(int i=0;i<adjlist[u].size();i++)
                {
                    pair<int,pair<string,bool> > v= adjlist[u][i];
                    if(v.second.first[0]!= p.first.second && v.second.second==false)
                    {
                        pq.push(make_pair(make_pair(p.first.first+v.second.first.size(),v.second.first[0]),v.first));
                        adjlist[u][i].second.second=true;
                    }
                }
            }
            if(out!=-1)
                cout<<out<<'\n';
            else
                cout<<"impossivel"<<'\n';
        }

    }
    return 0;
}
