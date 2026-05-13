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
const int mod = 998244353,N = 60;

int power(long long n, long long k) {
	int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
	while (k) {
    	if (k & 1) ans = (long long) ans * n % mod;
    	n = (long long) n * n % mod;
    	k >>= 1;
  	}
 	return ans;
}
int f[N], invf[N];
int nCr(int n, int r) {
	if (n < r or n < 0) return 0;
	return 1LL * f[n] * invf[r] % mod * invf[n - r] % mod;
}
int nPr(int n, int r) {
	if (n < r or n < 0) return 0;
	return 1LL * f[n] * invf[n - r] % mod;
}
void Precalculate(){
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

	Precalculate();

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;

    	cin >> n;

    	map<ll, ll>cnt;

    	vector<int>arr(n, 0);

    	ll first_box = 0;

    	cin >> first_box;

    	for(int i = 0; i < n; i++){
    		cin >> arr[i];
    	}

    	sort(arr.begin(), arr.end());
    	ll need = 0, mx_cnt = 1;

    	for(int i = 0; i < n - 1; i++){
    		need += (arr[n - 1] - arr[i]);
    		if(arr[i] == arr[n - 1])
    			mx_cnt++;
    	}

    	int fixed_slot = need - first_box;

    	if(fixed_slot > n - 1){
    		cout << 0 << endl;
    		continue;
    	}

    	if(fixed_slot <= 0){
    		cout << f[n] << endl;
    		continue;
    	}

    	debug(fixed_slot);
    	ll ans = (nCr(n - mx_cnt, fixed_slot) * 1LL * f[fixed_slot]) % mod;

    	ans *= f[n - fixed_slot];

    	ans %= mod;
    	

    	cout << ans << endl;

    }
    return 0 ;

    runtime();

}
