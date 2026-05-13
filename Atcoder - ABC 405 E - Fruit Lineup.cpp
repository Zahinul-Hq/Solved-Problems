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
#include<bits/stdc++.h>
using namespace std;

const int N = 4e6 + 7, mod = 998244353;

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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    f[0] = 1;
  	for (int i = 1; i < N; i++) {
    	f[i] = 1LL * i * f[i - 1] % mod;
	}
  	invf[N - 1] = power(f[N - 1], mod - 2);
  	for (int i = N - 2; i >= 0; i--) {
    	invf[i] = 1LL * invf[i + 1] * (i + 1) % mod;
  	}

  	int Apple, Orange, Banana, Grape;

  	cin >> Apple >> Orange >> Banana >> Grape;

  	ll ans = 0;

  	for(int i = 0; i <= Banana; i++){

  		ans += (((f[Apple + Orange + i] % mod * invf[Apple + i] % mod * invf[Orange] % mod ) % mod) * ((f[Grape - 1 + Banana - i] % mod * invf[Grape - 1] % mod * invf[ Banana - i]) % mod)) % mod ;
  		ans %= mod;
  	}

  	cout << ans << endl;
    return 0 ;

    runtime();

}
