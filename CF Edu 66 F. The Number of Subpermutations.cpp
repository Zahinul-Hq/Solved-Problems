#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   1e18
#define lw   -2e18
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
ll rnd(ll low, ll high) {

    static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    uniform_int_distribution<ll> dist(low, high);

    return dist(rng);
}
const ll  l = 1000008, r = inf;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	int n;
	cin >> n;

	vector<ll>hs(n + 1 , 0), arr(n + 1 , 0), hashed_array(n + 1, 0), pref_xr(n + 1, 0), valid_xr(n + 1, 0);
	int ones = 0;

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
		ones += (arr[i] == 1);
		hs[i] = rnd(l, r);
	}

	for(int i = 1; i <= n; i++){
		pref_xr[i] = pref_xr[i - 1] ^ hs[arr[i]];
		valid_xr[i] = valid_xr[i - 1] ^ hs[i];
	}

	ll prev_one = 0, last_one = 0;

	ll ans = 0, mx_val = 1;

	for(ll i = 1; i <= n; i++){
		if(arr[i] == 1){
			prev_one = last_one;
			last_one = i;
			mx_val = 1 ;
		}
		if(last_one == 0) continue;

		mx_val = max(mx_val, arr[i]);


		ll r = i, l = max(i - mx_val, prev_one);
					
		//debug(valid_xr[arr[i]], (pref_xr[r] ^ pref_xr[l]), i, r, l);
		if(valid_xr[mx_val] == (pref_xr[r] ^ pref_xr[l])){
			ans++;
		}

	}

	last_one = n , prev_one = n;

	bool f = 0;
	for(int i = n; i >= 1; i--){

		if(arr[i] == 1){
			prev_one = last_one;
			last_one = i;
			mx_val = 1;
			f = 1;
		}

		if(!f ) continue;

		mx_val = max(arr[i], mx_val);



		int l = i - 1, r = min(i + mx_val - 1, prev_one);

		debug(valid_xr[mx_val], (pref_xr[r] ^ pref_xr[l]), i, r, l, mx_val);

		if(valid_xr[mx_val] == (pref_xr[r] ^ pref_xr[l])){
			ans++;
		}

	}

	cout << ans - ones << endl;

    return 0 ;

    runtime();

}
