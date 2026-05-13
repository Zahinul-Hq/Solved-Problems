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

int arr[N], n;
ll mx[N];
ll dp[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {

        cin >> n;

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];

        	mx[i] = low;
        	dp[i] = 0;
        }

        dp[0] = 0;
        for(int i = 1; i <= n; i++){
        	dp[i] = max(dp[i - 1], i + mx[arr[i]]);
        	mx[arr[i]] = max(mx[arr[i]], dp[i - 1] - i + 1);
        	
        }

        ll ans = dp[n] ;
        cout << ans << endl;



    }
    return 0 ;
}
