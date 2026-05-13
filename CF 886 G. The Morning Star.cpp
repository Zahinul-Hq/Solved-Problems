#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int t ;
    cin >> t ;
    
    while (t--)
    {
        ll n, x, y;
        cin >> n;

        vector<pair<int, int>> arr;
        map<ll,ll> x_axis, y_axis, xy_axis, yx_axis;

        for(int i = 0; i < n; i++){
        	cin >> x >> y;
        	arr.push_back({x,y});
        	x_axis[x]++;
        	y_axis[y]++;
        	xy_axis[(x - y)]++;
        	yx_axis[x + y]++;
        }

        ll ans = 0;
        for(auto i : x_axis){
        	ll val = (i.S * (i.S + 1)) / 2;
        	ans += val;
        	ans -= i.S;
        }
        for(auto i : y_axis){
        	ll val = (i.S * (i.S + 1)) / 2;
        	ans += val;
        	ans -= i.S;
        }
        for(auto i : xy_axis){
        	ll val = (i.S * (i.S + 1)) / 2;
        	ans += val;
        	ans -= i.S;
        }
        for(auto i : yx_axis){
        	ll val = (i.S * (i.S + 1)) / 2;
        	ans += val;
        	ans -= i.S;
        }

        cout << ans + ans  << endl;
    }
    return 0 ;
}
