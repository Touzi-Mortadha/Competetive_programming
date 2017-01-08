#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("output.txt","w",stdout);
    srand(time(0));
    cout<<rand()%10000<<" "<<rand()%10000<<endl;
    cout<<"30"<<endl;
    for(int i =0;i<30;i++)
    {
        cout<<rand()%10000<<" "<<rand()%10000<<endl;
    }
    return 0;
}
