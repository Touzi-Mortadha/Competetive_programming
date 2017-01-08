#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
//#include<bits/stdc++.h>
//////////////////////////////problem UVA 469///////////////////////
using namespace std;
typedef unsigned long long ull;


int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
vector<vector<char> > grid;

int floodfill(int r, int c, char c1, char c2 , int R,int C)
{
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 8 ; d++)
    ans += floodfill(r + dr[d], c + dc[d], c1, c2,R,C);
    return ans;
}




int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    char c;
    string s,m;
    cin>>T;
    getline(cin,s);
    getline(cin,s);
    while(T--)
    {
        vector<vector<char> > mat;
        int k=0,r,col,e;
        vector<char> row;
        getline(cin,s);
        do
        {
            for(int i=0;i<s.length();i++)
                row.push_back(s[i]);
            mat.push_back(row);
            row.clear();
            k++;
            s.clear();
            getline(cin,s);
        }while(s[0]=='L' || s[0]=='W');

        c='a';
        while(s[0]-'0'>=0 && s[0]-'0'<10)
        {
        grid=mat;
        istringstream iss (s);
        iss>>r;
        iss>>col;

        /*r=s[0]-'0';
        int f=1;
        while(s[f]!=' '){r=r*10+s[f++]-'0';}
        f++;
        col=s[f++]-'0';
        while(f<s.length()){col=col*10+s[f++]-'0';}*/
        cout<<floodfill(r-1,col-1,'W','.',k,mat[0].size())<<endl;
        /*for(int i=0;i<k;i++)
        {
            for(int j=0;j<mat[0].size();j++)
                cout<<grid[i][j];
            cout<<endl;
        }*/

        getline(cin,s);
        }
        for(int i=0;i<k;i++)
            {
                mat[i].clear();
                grid[i].clear();
            }
        if(T>0)
            cout<<endl;
        mat.clear();
        grid.clear();
    }
    return 0;
}
