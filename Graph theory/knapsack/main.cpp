#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii> > vvii;
typedef vector<vector<int> > vvi;
typedef vector<ii> vii;
typedef long long ll;

const int oo = (int)1e9;

int n;
const int MAX = 1001;
int arr[MAX];
int dp[MAX][MAX];

int M[MAX];
int ind[MAX];
int Prev[MAX];

int lisnlogn(){//BETTER
    int L = 0;
    for(int i=1;i<=n;i++)
    {
        int idx = lower_bound(M,M+L,arr[i])-M;
        if(idx == L)
            L++;
        ind[idx] = i;
        M[idx] = arr[i];
        if(idx > 0)
            Prev[i] = ind[idx-1];
        else
            Prev[i] = -1;
    }
    cout << "elements: ";
    int At = ind[L-1];
    while(~At){
        cout << arr[At] << " ";
    cout << endl;
        At = Prev[At];
    }
    return L;
}

int LIS(int i,int j)
{
    if(i>n)
        return 0;
    int& r = dp[i][j];
    if(r!=-1)
        return r;
    r = LIS(i+1,j);
    if(arr[i]> arr[j])
        r = max(r,1+LIS(i+1,i));
    return r;
}

int main()
{
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> arr[i];
    arr[0]=-1;
    memset(dp,-1,sizeof dp);
    cout << LIS(1,0) << endl;
    cout << lisnlogn() << endl;
    return 0;
}
