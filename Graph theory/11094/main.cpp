#include<bits/stdc++.h>

using namespace std;
int dr[] = {1,-1,0,0,};
int dc[] = {0,0,1,-1,};
const int Max=30;
int dp[Max][Max],grid[Max][Max];
int r,c,m,n;
char car,x;

void prinnt()
{
for(int i=0;i<m;i++)
    {
    for(int j=0;j<n;j++)
        cout<<grid[i][j];
    cout<<endl;
    }
cout<<endl;
cout<<endl;
}


int floodfill(int r,int c)
{
if(c==-1)
    c=n-1;
c=c%(n);
if (r<0 || r>=m || dp[r][c]==0)
    return 0;
if(grid[r][c]!=car)
    return 0;
grid[r][c]='.';
dp[r][c]=0;
int ans=1;
for(int i=0;i<4;i++)
    ans+=floodfill(r+dr[i],c+dc[i]);
return ans;
}

int main()
{
    freopen("file","r",stdin);
    string s;
    getline(cin,s);
    while(s!="")
    {
        int maxi=0;
        memset(dp,-1,sizeof dp);
        istringstream iss (s);
        iss>>m;
        iss>>n;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    cin>>x;
                    grid[i][j]=x;
                }
        cin>>r;
        cin>>c;
        car=grid[r][c];
        floodfill(r,c);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                {
                    maxi=max(floodfill(i,j),maxi);
                }
        cout<<maxi<<endl;
        getline(cin,s);
        getline(cin,s);
        getline(cin,s);
    }
    return 0;
}
