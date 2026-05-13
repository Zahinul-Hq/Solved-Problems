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
const int mod = 1e9 + 7;
ll binary_expo(ll base, ll pwr){
	ll result = 1; 
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n + 1 , 0), psum(n + 1, 0);

        for(int i = 1; i <= n; i++){
        	cin>>v[i];
        }
        for(int i = 1; i <= n; i++){
        	psum[i]=(psum[i - 1] % mod) + (v[i] % mod);
        	psum[i]%=mod; 
        }

        ll total = 0;

        for(int i = 1; i <= n; i++){
        	tot = (tot % mod) + (((arr[i] % mod) * ((pref[n] - pref[i] + mod) % mod)) % mod);
        	tot %= mod;
        }

       	ll d = (n * (n - 1) / 2) ;

       	ll ans = (binary_expo(d, mod - 2) * tot) % mod;

       	cout << ans << endl;

        
    }
    return 0 ;
}
