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
const int Mod = 1e9;
int binary_expo(int base, ll pwr, int mod){
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
vector<ll> pre_cal(){

	int lim = 1e8;

	vector<ll>ans;

	for(int i = 1; i <= lim; i++){
		ll sum = 0;
		int k = log10(i) + 1;
		int val = i;
		while(val > 0){
			int last = val % 10;
			val /= 10;
			sum += binary_expo(last, k, Mod);
		}
		
		if(sum == i){
			cout << sum << endl;
			ans.push_back(sum);
		}
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	//vector<ll>ans = pre_cal();
	vector<ll>arr = {1,2,3,4,5,6,7,8,9,153,370,371,407,1634,8208,9474,54748,92727,93084,548834,1741725,4210818,9800817,9926315,24678050,24678051,88593477};
	//debug(ans);
    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll l, r;
    	cin >> l >> r;

    	if(l > r){
    		swap(l, r);
    	}
    	int p = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
    	int q = upper_bound(arr.begin(), arr.end(), r) -arr.begin();

    	cout << q - p << endl;
    }
    return 0 ;

    runtime();

}
