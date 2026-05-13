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
const int mod =  998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

    int n;
    cin >> n;
    vector<int>arr(n + 1, 0);

    vector<vector<int>>pref(32, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    }

    for(int bit = 0; bit <= 31; bit++){
    	for(int i = 1; i <= n; i++){
    		pref[bit][i] = (pref[bit][i - 1] + ((arr[i] & (1 << bit)) > 0)) % 2 ;
    	}
    }

    debug(pref);
    ll ans = 0;

    for(int bit = 0; bit <= 31; bit++){
        ll ev_sum = 0, odd_sum = 0, ev_cnt = 0, odd_cnt = 0, total = 0;
        for(int i = n; i >= 0; i--){
            if(pref[bit][i]){
                total += ( ev_sum - (ev_cnt * i) % mod);
                if(total < 0) total += mod;
                total %= mod;
                odd_sum += i;
                odd_sum %= mod;
                odd_cnt++;
            }else{
                total += (odd_sum - (odd_cnt * i) % mod);
                if(total < 0) total += mod;
                total %= mod;
                ev_sum += i;
                ev_sum %= mod;
                ev_cnt++;
            }
        }

        ans += ((total * (1LL << bit)) % mod);
        ans %= mod;
    }

    cout << ans << endl;


    return 0 ;

    runtime();

}
