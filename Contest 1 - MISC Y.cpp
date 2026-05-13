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


bool cmp(pair<long double,pair<long double,long double>> x, pair<long double,pair<long double,long double>> y){
	if(x.S.S >= y.S.S)
		return false;
    
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int t = 1 ;
    //cin >> t;
    while(t--){
        ll n , m;
        cin >> n >> m;
        long double p , c;

        vector<pair<long double,pair<long double,long double>>>vp;

        for(int i = 0; i < n; i++){
            cin >> p >> c;

            vp.push_back({p,{c, c/p}});
        }

        sort(vp.begin(), vp.end(), cmp);

        ll ans = inf;

        ll sump = 0, sumc = 0;

        for(int i = 0; i < n; i++){

            sump += vp[i].F;
            sumc += vp[i].S.F;

            ll days = ((sumc + sump - 1)/ sump) ;
            ll rem = max((m - ((days * sump) - sumc))*1LL, 0LL);

            days += ((rem + sump - 1) / sump);
            ans = min(ans, days);

        }

        cout << ans << endl;
    }
    return 0 ;


}
