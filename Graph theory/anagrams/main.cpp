#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <set>
#include <algorithm>

using namespace std;

int ispalindrome(string s)
{
int i=0;
//cout<<s<<endl;
if(s.length()==1)
    return 0;
else if(s.length()==2)
    {
        if(s[0]==s[1]){cout<<s<<endl;return 1;}

        else
            return 0;
    }
else
{
    while(i<s.length()/2)
    {
        if(s[i]!=s[s.length()-1-i])
            return 0;
        i++;
    }
}
cout<<s<<endl;
return 1;
}



int main()
{
int T;
cin>>T;
    while(T--)
    {
        std::set<string> myset;
        std::set<string>::iterator it,it1;
        string s,s1="",chaine1,chaine2;
        cin>>s;
        int x=0;

            bitset<100> a=0;
            for(int i=1;i<(2<<s.length()-1);i++)
                {
                    a=i;
                    cout<<a<<endl;
                    for(int j=0;j<s.length();j++)
                        {
                            if(a[j]==1)
                                s1+=s[j];

                            if (j>0 && a[j] == 0)
                                {if(a[j-1] == 1)
                                    break;}
                        }
                    myset.insert(s1);
                    cout<<s1<<endl;
                    s1.clear();
                }
        it=myset.begin();
        while(it!=myset.end())
        //for (it=myset.begin(); it!=myset.end(); ++it)
        {
            chaine1=*it;
            cout<<chaine1;
            sort(chaine1.begin(),chaine1.end());
            cout<<"    "<<chaine1<<endl;
            ++it;
            for (it1=it; it1!=myset.end(); ++it1)
                {
                    chaine2=*it1;
                    //cout<<chaine1<<"        "<<chaine2<<endl;
                    sort(chaine2.begin(),chaine2.end());
                    if(chaine1==chaine2)
                        x++;
                }


            //cout<<*it<<endl;
        }
        cout<<x<<endl;
    }
}
