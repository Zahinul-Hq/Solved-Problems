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
const int mod = 998244353, N = 2e5 + 7;

ll k, n;

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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> n;

    	k = 0;

    	vector<ll>pref(n + 1, 0), arr(n + 1, 0), pref_pos(n + 1, 0);
    	ll sum  = 0;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		pref[i] = pref[i - 1] + arr[i];
    	}

    	

    	for(int i = 0; i <= n; i++){
    		sum += arr[i];

    		if(i)pref_pos[i] = pref_pos[i - 1] + (sum >= 0);
    		k = max(abs(sum ) + (pref[n] - pref[i]), k);
    		
    	}

    	ll ans = 0;
    	sum = 0;

    	debug(pref_pos);

    	if(pref_pos[n] == n){
			 ans = binary_expo(2, n);

    		cout << ans << endl;
    		continue;
    	}

    	for(int i = 1; i <= n; i++){
    		sum += arr[i];

    		if(abs(sum) + (pref[n] - pref[i]) == k){
    			int x = pref_pos[i - 1];
    			int y = n - i;

    			ans += binary_expo(2, x + y);
    			ans %= mod;

    			debug(x, y, i);
    		}
    	}

    	cout << ans << endl;

    }
    return 0 ;

    runtime();

}
