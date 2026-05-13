#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{    
    #ifndef ONLINE_JUDGE
        freopen("input.txt" ,"r" , stdin);
        freopen("output.txt" , "w" ,stdout);
        cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
    #endif
}

const int N = 2e5 + 7;
map<array<int, 3>, ll>dp;
int n , m;
int a[N], b[N];

ll rec(int i, int prog, int test){

    if(i == n + m + 1) return 0;

    if(dp.count({i, prog, test}) )
        return dp[{i, prog, test}];


    if(((a[i] > b[i]) && prog) || test == 0){
        return dp[{i, prog, test}] = a[i] + rec(i + 1, prog - 1, test);
    }else{
        return dp[{i, prog, test}] = b[i] + rec(i + 1, prog, test - 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        cin >> n >> m;

        dp.clear();

        for(int i = 0; i < m + n + 1; i++){
            cin >> a[i] ;
        } 
        for(int i = 0; i < m + n + 1; i++){
            cin >> b[i] ;
        }

        ll ans = 0, prog = n, test = m;

        for(int i = 0; i < n + m + 1; i++){

            cout << ans + rec(i + 1, prog , test) << " ";

            if((a[i] > b[i] && prog) || test == 0){
                ans += a[i];
                prog--;
            }else{
                ans += b[i];
                test--;
            }

        }

        cout << endl;
    }
    return 0 ;
}
