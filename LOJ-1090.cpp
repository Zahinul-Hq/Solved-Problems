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
const int N = 1e6 + 9;
ll spf[N], pref5[N], pref2[N];
void precalculate(){

  	for (int i = 2; i < N; i++) {
    	spf[i] = i;
  	}
  	for (ll i = 2; i < N; i++) {
    	for (int j = i; j < N; j += i) {
      		spf[j] = min(spf[j], i);
    	}
  	}

  	pref5[1] = pref5[0] = pref2[1] = pref2[0] = 0;

  	for(int i = 2; i < N; i++){
  		int n = i;
	  	while (n > 1) {
			pref5[i] += (spf[n] == 5);
			pref2[i] += (spf[n] == 2);
	      	n /= spf[n];
	    }
	    pref5[i] = pref5[i - 1] + pref5[i];
	    pref2[i] = pref2[i - 1] + pref2[i];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	precalculate();
    int test_cases, cs= 1 ;
    cin >> test_cases ;

    //debug(pref5, pref2);
    
    while (test_cases--)
    {
    	ll n, r, p, q;

    	cin >> n >> r >> p >> q;

    	ll tot_5 = pref5[n] - pref5[r] - pref5[n - r] + ((pref5[p] - pref5[p - 1]) * q);
    	ll tot_2 = pref2[n] - pref2[r] - pref2[n - r] + ((pref2[p] - pref2[p - 1]) * q);

    	cout << "Case " << cs++ << ": "<< min(tot_5, tot_2) << endl;
    }
    return 0 ;

    runtime();

}
