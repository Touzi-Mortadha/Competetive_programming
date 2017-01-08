#include <bits/stdc++.h>

using namespace std;


int main()
{
    //freopen("i","r",stdin);
    //freopen("w","w",stdout);
    ios_base::sync_with_stdio(false);
    int R,C,N;
    char mat[102][102];
    while(cin>>R>>C>>N && R && C && N)
    {
        int conteur=0;
        int l,k;
        char next,current;
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='N' || mat[i][j]=='S' || mat[i][j]=='L' || mat[i][j]=='O')
                {
                    l=i;
                    k=j;
                }
            }
        current=mat[l][k];
        //cout<<l<<" "<<k<<endl;
        for(int i=0; i<N; i++)
        {
            cin>>next;
           // cout<<next<<" "<<current<<endl;

            if(current=='N')
            {
                if(next=='D')
                {
                    current='L';
                    //cout<<"yes"<<current<<endl;
                }
                else if(next=='E')
                {
                    current='O';
                }
                else if(next=='F')
                {
                    if(l-1>=0 && mat[l-1][k]!='#')
                        l-=1;
                }
            }
            else if(current=='L')
            {
                if(next=='D')
                {
                    current='S';
                }
                else if(next=='E')
                {
                    current='N';
                }
                else if(next=='F')
                {
                    if(k+1<C && mat[l][k+1]!='#')
                        k+=1;
                }
            }
            else if(current=='S')
            {
                if(next=='D')
                {
                    current='O';
                }
                else if(next=='E')
                {
                    current='L';
                }
                else if(next=='F')
                {
                    if(l+1<R && mat[l+1][k]!='#')
                        l+=1;
                }
            }

            else if(current=='O')
            {
                if(next=='D')
                {
                    current='N';
                }
                else if(next=='E')
                {
                    current='S';
                }
                else if(next=='F')
                {
                    if(k-1>=0 && mat[l][k-1]!='#')
                        k-=1;
                }
            }
            if(mat[l][k]=='*')
                {
                    conteur++;
                    mat[l][k]='.';
                }
          //  cout<<l<<" "<<k<<endl;
        }
            cout<<conteur<<endl;
    }
    return 0;
}
