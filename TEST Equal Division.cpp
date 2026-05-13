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

ll MAX = 2e12;
ll binary_expo(ll base, int pwr, ll mod){
	ll result = 1; 
	base %= mod, pwr %= mod;
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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll Q, K, L, R;

    	cin >> Q >> K;
    	vector<ll>pwrs;

    	for(ll i = 1;; i++){
    		ll pwr_val = binary_expo(i, K, inf);

    		if(pwr_val <= MAX){
    			pwrs.push_back(pwr_val);
    		}else{
    			break;
    		}
    	}

    	cout << pwrs.size() << endl;

    	while(0){

    		cin >> L >> R;

    	}

    }
    return 0 ;

    runtime();

}
