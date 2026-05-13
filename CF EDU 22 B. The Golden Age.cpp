#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   1e18
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
ll pwr(ll base, ll p){

	ll ans = 1;

	while(p--){
		if(ans > (inf / base))
			break;
		ans *= base;

	}
	//cout << p << endl;

	if(p == -1)
		return ans;
	else
		return 0;
	
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll x, y, l, r;

    cin >> x >> y >> l >> r;
    vector<ll>values;

    for(ll i = 0; i < 64; i++){
    	for(ll j = 0; j < 64; j++){
    		ll xp = pwr(x, i);
    		ll yp = pwr(y, j);

    		ll tot = xp + yp;
    		//cout << xp << " " << yp << endl;
    		if(l <= tot && tot <= r && xp && yp){
    			values.push_back(tot);
    		}
    	}
    }


    sort(values.begin(), values.end());
    //values.erase(unique(values.begin(), values.end()), values.end());


    ll mx = r - l + 1;
    if(values.size() != 0){
    	mx = 0;
    	mx = max(values[0] - l, r - values[values.size() - 1]);
    	for(int i = 0; i < values.size() - 1; i++){
	    	ll diff = values[i + 1] - values[i] - 1  ;
	    	mx = max(mx, diff);
    	}
    }

    
    


    cout << mx << endl;
    return 0 ;
}
