#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("output.txt","w",stdout);
    cout<<"100"<<endl;
    srand(time(0));
    for(int i =0;i<100;i++)
    {
        int s=rand()%100,p=rand()%(100-s+1)+s+1;
        cout<<s<<" "<<p<<endl;
        for(int j=0;j<p;j++)
            cout<<rand()%10000<<" "<<rand()%10000<<endl;
    }
    return 0;
}
