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
const int MAX_Value = 1e5 + 3, mod = 1e9 + 7;
vector<ll>freq(MAX_Value + 1, 0), cnt(MAX_Value + 1, 0), ans(MAX_Value + 1, 0);
int binary_expo(int base, ll pwr){
	int result = 1; 
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

	int n;
	cin >> n;
	vector<int>arr(n);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
		freq[arr[i]]++;
	}


	for(int gcd = MAX_Value ; gcd >= 1; gcd--){
		for(int g = gcd; g <= MAX_Value; g += gcd){
			cnt[gcd] += freq[g];
		}
	}

	for(int gcd = MAX_Value ; gcd >= 1; gcd--){
		ans[gcd] = (binary_expo(2, cnt[gcd]) - 1 + mod) % mod;
		for(int g = gcd + gcd; g <= MAX_Value; g += gcd){
			ans[gcd] = ((ans[gcd] % mod - ans[g] % mod) + mod) % mod;
		}
	}

	cout << ans[1] << endl;
    return 0 ;

    runtime();

}
