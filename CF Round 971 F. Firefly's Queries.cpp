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
ll prf_sum(ll x, vector<ll>&prf, ll n){

	ll p = x / n, rm = x % n;

	ll r = p + rm, l = 0;

	if(rm == 0){
		return p * prf[n];
	}

	if(r > n){
		l = r - n;
		r = n;
	}


	debug(p, rm, r, l);

	ll sum = p * prf[n] + prf[r] - prf[p] + prf[l]; 
	return sum;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n, q;
    	cin >> n >> q;

    	vector<ll>arr(n + 1), prf(n + 1, 0);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}
    	for(int i = 1; i <= n; i++){
    		prf[i] = prf[i - 1] + arr[i];
    	}

    	ll l, r;

    	debug(prf);

    	while(q--){
    		cin >> l >> r;
    		cout << prf_sum(r, prf, n) - prf_sum(l - 1, prf, n) << endl;
    	}



    }
    return 0 ;

    runtime();

}
