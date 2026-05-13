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

int a(int n, vector<int>&pref, vector<int>&arr, ll m){
	if(m <= 2 * n){
		return arr[m];
	}

	ll res = 0;

	if(m % 2 == 0){
		res = res ^ pref[n] ^ a(n, pref, arr, m / 2);
	}else{
		res = res ^ pref[n] ^ a(n, pref, arr, m / 2) ^ a(n, pref, arr, m / 2) ;
	}

	return res;

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
    	ll n, l, r;

    	cin >> n >> l >> r;

    	vector<int>arr(n + n + 3, 0), pref(n + n + 3, 0);

    	int p = 0;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		pref[i] = pref[i - 1] ^ arr[i];
    	}
    	bool f = 0;
    	if(n % 2 == 0){
    		f = 1;
    		n++;
    	}

    	for(int i = n + f; i <= n + n; i++){
    		arr[i] = pref[i / 2];
    		pref[i] = pref[i - 1] ^ arr[i];
    	}

    	ll ans = 0;


    	while(1){

    		

    	}


    }
    return 0 ;

    runtime();

}
