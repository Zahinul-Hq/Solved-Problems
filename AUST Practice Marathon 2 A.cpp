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
const int N = 1e6, mod = 998244353;

int power(long long n, long long k) {
	int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
	while (k) {
    	if (k & 1) ans = (long long) ans * n % mod;
    	n = (long long) n * n % mod;
    	k >>= 1;
  	}
  return ans;
}
ll f[N], invf[N];
ll nCr(int n, int r) {
 	if (n < r or n < 0) return 0;
	return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
int ncr(int n, int r)
	{
		if (r > n or r < 0) return 0;

		ll res = 1;
		ll badd = 1;
		for (int i = n; i > n - r; i--)
			res *= i, res %= mod;

		for (int i = 2; i <= r; i++)
			badd *= i, badd %= mod;

		return (res * power(badd, mod - 2)) % mod;
	}
void initialize(){
	f[0] = 1;
  	for (int i = 1; i < N; i++) {
    	f[i] = 1LL * i * f[i - 1] % mod;
  	}
  	invf[N - 1] = power(f[N - 1], mod - 2);
  	for (int i = N - 2; i >= 0; i--) {
    	invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	initialize();

	int _n, k;
	cin >> _n >> k;

	vector<ll>arr(_n, 0);

	ll s = 0;

	for(int i = 0; i < _n; i++){
		cin >> arr[i];

		if(i) s += arr[i];
	}

	if(arr[0] < s + k){
		cout << 0 << endl;
		return 0;
	}

	ll ans = ncr(arr[0] - s - 1, k - 1);

	for(int i = 1; i < _n; i++){
		ans = (ans % mod * ncr(arr[i] + k - 1, k - 1) % mod) % mod;
	}

	//debug(ans);

	cout << ans << endl;


    
    return 0 ;

    runtime();

}
