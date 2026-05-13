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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	ll x, m, y,ans = 0;

    	cin >> x >> m;


    	if(x >= m){
            for(y = 1; y <= m; y++){
                ll xr = x ^ y;
                if(xr % x == 0 && xr != 0){
                    ans++;
                }
                if(xr % y == 0){
                    ans++;
                } 
            }
        }else{
            ans = (m - x) / x  - ((m - x) >= x);

            for(y = 1; y <= x; y++){
                ll xr = x ^ y;
                if(xr % y == 0){
                    ans++;
                }
                debug(xr, y, ans);
            }

            for(ll xr = max(m - x, x) + 1; xr <= m + x; xr++){
                y = xr ^ x;
                if(y >= 1 && y <= m && xr % x == 0){
                    ans++;
                }
                debug(xr, y, ans);
            }

        }

    	cout << ans << endl;

    }
    return 0 ;
}
