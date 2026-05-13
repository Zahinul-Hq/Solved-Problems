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

const int N = 1e6 + 7;
vector<bool>is_prime(N, true);
vector<ll> cnt(N, 0), primes;
void seive(){

	for (ll i = 2; i < N; i++) {
	    if (cnt[i] == 0) {
	        for (ll j = i; j < N; j += i)
	            cnt[j]++;
	    }
	}
	for(ll i = 6; i < N; i++){
		if(cnt[i] == 2)
			primes.push_back(i * i);
	}
	// Change N 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	seive();


	int q;
	cin >> q;

	//debug(primes);

	while(q--){
		ll x; cin >> x;

		cout << *prev(upper_bound(primes.begin(), primes.end(), x)) << endl;
	}

	
   
    return 0 ;

    runtime();

}
