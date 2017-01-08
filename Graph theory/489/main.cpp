#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r;
    string solution,guess;
    freopen("input","r",stdin);
    freopen("w","w",stdout);
    int c=1;
    while(scanf("%d",&r) && r!=-1)
    {
            map<char,int> ms,mg;
            int stroke=0,found=0;
            int x=0;
        getline(cin,solution);
        getline(cin,solution);
        for(int i=0;i<solution.length();i++)
        ms[solution[i]]=1;
        getline(cin,guess);
        for(int i=0;i<guess.length();i++)
        mg[guess[i]]=1;
        for(int i=0;i<guess.length();i++)
        { if(ms[guess[i]]==0)
            {x++;
            ms[guess[i]]=2;
            }

        if(ms[guess[i]]==1 && mg[guess[i]]==1)
        {found++;
        ms[guess[i]]=2;
        mg[guess[i]]=2;
        if(found==(ms.size()-x))
        break;
        }
        else if(ms[guess[i]]==2 && mg[guess[i]]==1)
        {stroke++;
        mg[guess[i]]=2;
        if (stroke==7)
        break;}
        }
         if(stroke<7 && (found==(ms.size()-x)))
         printf("Round %d\nYou win.\n",c++);

        else if(stroke>=7 && found<ms.size())
         printf("Round %d\nYou lose.\n",c++);
        else if(stroke <7 && found<ms.size())
            printf("Round %d\nYou chickened out.\n",c++);
      }
    return 0;
}
