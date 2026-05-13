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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
const int mod = 1e9 + 7;

ll binary_expo(ll base, ll pwr){
	ll result = 1; 
	base %= mod;
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
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	ll n;
	cin >> n;

	ll ans = 0; 

	debug(ans);

	ll sum = 0;

	for(int i = 1; i <= n; i++){
		sum += (n / i);
		if(n / i != i){
			sum += (i);
		}
	}

	cout << sum - 1 << endl;

	for(ll i = 1; i * i <= n; i++){
		ll x = (n / i);
		ans += ((x % mod * (x + 1) % mod) % mod * binary_expo(2LL, mod - 2)) % mod;
		ans %= mod;
		if(x != i){
			ans -= ((i % mod * (i + 1) % mod) % mod * binary_expo(2LL, mod - 2)) % mod;
			ans %= mod;
			ans += ((i) % mod * (x - i) % mod) % mod;
			ans %= mod;

		}
		debug(i, x);

	}
	
	cout << ans << endl;
    return 0 ;

    runtime();

}
