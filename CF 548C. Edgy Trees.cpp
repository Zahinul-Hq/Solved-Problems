#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
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
const int mod = 1e9 + 7, N = 1e5 +7;
int binary_expo(int base, int pwr){
	int result = 1; 
	base %= mod, pwr %= mod;
	while(pwr){
		if(pwr & 1){
			result = (result * 1LL * base) % mod;
		}
		base = (base * 1LL * base) % mod;
		pwr >>= 1;
	}
	return result;
}
vector<int>graph[N], vis(N, 0);
int sz ;
void dfs(int u){
	vis[u] = 1;
	for(auto v : graph[u]){
		if(!vis[v]){
			sz++;
			vis[v] = 1;
			dfs(v);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n, k, u , v, ok;
    cin >> n >> k;

    for(int i = 1; i < n; i++){
    	cin >> u >> v >> ok;

    	if(!ok){
    		graph[u].push_back(v);
    		graph[v].push_back(u);
    	}
    }
    ll ans = binary_expo(n, k);

    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		sz = 1;
    		dfs(i);

    		if(sz){
    			ll df = binary_expo(sz, k);

    			if(ans - df < 0) ans += mod;
    			ans -= binary_expo(sz, k);
    		}
    	}
    }

    cout << ans << endl;

    return 0 ;
}
