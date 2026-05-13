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
const int N  = 2050, mod = 100000007;
int n;
vector<int>arr(N + 1);
map<int,int>val;
ll dp[1002][N];
ll rec(int i, int xor_val){
 
	if(i == n + 1){
		if(val.find(xor_val) == val.end())
			return 1;
		return 0;
	}
 
	if(dp[i][xor_val] != -1)
		return dp[i][xor_val];	
 
	ll ans = rec(i + 1, xor_val);
	ans %= mod;
	ans += rec(i + 1, xor_val ^ arr[i]);
	ans %= mod;
 
 
	return dp[i][xor_val] = ans % mod;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;
 
    int t , cs = 1;
    cin >> t ;
    
    while (t--)
    {
    	int m, x;
 
        cin >> n >> m;

        if(n == 0){
        	cout << 0 << endl;
        	continue;
        }
 
        memset(dp, -1, sizeof dp);
       	
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        for(int i = 1; i <= m; i++){
        	cin >> x;
        	val[x]++;
        }
 
 
        ll ans = rec(1, 0);
 
        cout << "Case " << cs++ << ": " << ans << endl;
    }
 
 
    return 0 ;
}
 