#include <bits/stdc++.h>

using namespace std;
int dc[]={1,1,0,-1,-1,-1, 0, 1};
int dr[]={0,1,1, 1, 0,-1,-1,-1};
int R,C;
char grid[1000][1000];

void priint()
{
for(int i=0;i<R;i++)
    {
    for(int j=0;j<C;j++)
        cout<<grid[i][j]<<" ";
    cout<<endl;
    }
}

int flood_fill(int r,int c)
{
if(r>=R || r<0 || c>=C || c<0)
    return 0;
if(grid[r][c]!='@')
    return 0;
grid[r][c]='*';
int ans = 1;
for(int i=0;i<8;i++)
    ans+=flood_fill(dr[i]+r,dc[i]+c);
return ans;



}

int main()
{
    freopen("input","r",stdin);
    freopen("w","w",stdout);
    char x;
    while(cin>>R>>C && R!=0 && C !=0)
    {
        memset(grid,-1,sizeof grid);
        int n=0;
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                {
                    cin>>x;
                    grid[i][j]=x;
                }
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                {
                    if(flood_fill(i,j)!=0)
                        n++;
                }
        cout<<n<<endl;

    }
    return 0;
}
