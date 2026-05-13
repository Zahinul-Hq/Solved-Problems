#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
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
const int N = 1e6 + 7;
vector<int>spf(N, INT_MAX);
void seive(){
	spf[1] = 1;
	for (int i = 2; i < N; i++){
	    if (spf[i] == INT_MAX){
	        for (int j = i; j < N; j += i){
	            spf[j] = min(spf[j], i);
	        }
	    }
	}
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
	seive();
	int n, q;
	cin >> n >> q;

	vector<int>arr(n + 1);
	vector<int>pf[n + 1];

	vector<ll> pref(n + 1, 0);

	ll hs[N][3] ;

	memset(hs, -1, sizeof hs);

	for(int i = 1; i <= n; i++){
		cin >> arr[i];

		int val = arr[i];



		while(val > 1){
			pf[i].push_back(spf[val]);
			for(int j = 0; j < 3; j++){
				if(hs[spf[val]][j] == -1  && j != 2)
					hs[spf[val]][j] = rnd(l, r);
				if(j == 2)
					hs[spf[val]][2] = hs[spf[val]][0] ^ hs[spf[val]][1];
			}
			val /= spf[val];
		}
	}


	vector<int>cnt(N, 0);

	for(int i = 1; i <= n; i++){
		ll xr = 0;
		for(int j = 0; j < pf[i].size(); j++){
			xr ^= hs[pf[i][j]][cnt[pf[i][j]]++ % 3];
		}

		pref[i] = pref[i - 1] ^ xr;
	}

	int L, R;

	while(q--){
		cin >> L >> R;

		if((pref[R] ^ pref[L - 1]) == 0){
			cout << "Yes"<< endl;
		}else{
			cout <<"No" << endl;
		}
	}


    
    return 0 ;

    runtime();

}
