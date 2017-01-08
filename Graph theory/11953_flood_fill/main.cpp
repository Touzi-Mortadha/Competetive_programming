#include <bits/stdc++.h>

using namespace std;
int t,n,appear;
char x ;
int dr[] = {1,-1,0,0,};
int dc[] = {0,0,1,-1,};
vector<vector<char> > grid;

int floodfill(int r,int c,int ff)
{
if(r>=n || r<0 || c>=n || c<0)
    return 0;
if(grid[r][c]!='x' && grid[r][c]!='@')
    return 0;
if(grid[r][c]=='x')
    appear=1;
if(appear==0)
    return 0;
int ans =1;
grid[r][c]='.';
int v=0;
for(int i = 0;i<8;i++)
    {
        ans+=floodfill(r+dr[i],c+dc[i],appear);
    }
return ans;
}

int main()
{
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        int count= 0;
        cin>>n;
        grid.resize(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                grid[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    {
                      appear=0;
                      if(floodfill(i,j,appear))
                        count+=1;
                    }
        cout<<"Case "<<k<<": "<<count<<endl;
        grid.clear();
    }
    return 0;
}
