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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n,  q;
    cin >> n >> q;

    vector<ll>arr(n + 1), pref(n + 1,0);

    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    	pref[i] = pref[i - 1] + arr[i];
    }

    debug(pref);

    int sq = sqrt(n) + 1;

    ll dp[sq + 1][n  + 2];

    memset(dp, 0, sizeof dp);

    for(int l = 1; l <= sq; l++){
    	for(int i = n; i >= 1; i--){

            if(i + l - 1 > n)
                continue;

            ll sum = pref[i + l - 1] - pref[i - 1];

            if(i + l <= n){
                dp[l][i] = sum - dp[l][i + l];
            }else{
                dp[l][i] = sum;
            }
        }
    }

    for(int i = 0; i <= n; i++){
        debug(dp[3][i], i);
    }


    while(q--){
        int l, r, k;

        cin >> l >> r >> k;

        if(k <= sq){

            ll x = -1;
            if(((r - l + 1) / k) % 2){
                x = 1;
                
            }
            cout << dp[k][l] + (x * dp[k][r + 1]) << endl;
        }else{

            int f = 1;
            ll sum = 0;

            for(int i = l; i + k - 1 <= r; i += k){

                if(f){
                    sum += (pref[i + k - 1] - pref[i - 1]);
                }else{
                    sum -= (pref[i + k - 1] - pref[i - 1]);
                }

                f ^= 1;
                
            }

            debug(sum);

            cout << sum << endl;
        }
    }

    

    return 0 ;

    runtime();

}
