#include<bits/stdc++.h>
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

bool possible(ll val, ll x, vector<ll> & arr){

	for(int i = 0; i < arr.size(); i++){

		if(arr[i] >= val)
			continue;

		x= x - (val - arr[i]);

		if(x < 0)
			return false;

	}

	return true;

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
        ll n, k , x = 0;

        cin >> n >> k;

        vector<ll> arr(n, 0);


        for(int i = 0; i < n; i++){
        	cin >> arr[i];

        	x = max(x, arr[i]);
        }

        ll hi = 2e12, lo = 0, mx = 0;

        while(hi >= lo){

        	ll mid = (hi + lo ) / 2;

        	if(possible(mid, k, arr)){
        		lo = mid + 1 ;
        		mx = mid;
        	}else{
        		hi = mid - 1;
        	}
        }

        ll  cnt = 0; 

        for(int i = 0; i < n; i++){
        	if(arr[i] < mx){
        		k -= (mx - arr[i]);
        		arr[i] += (mx - arr[i]);

        	}
        }

        for(int i = 0; i < n; i++){
        	if(arr[i] > mx){
        		cnt++;
        	}else if(k > 0){

        		if(arr[i] + 1 > mx)
        			cnt++;
        			k--;
        	}
        }


        ll ans  = mx + ((mx - 1) * (n - 1));

        ans += cnt;

        cout << ans << endl;

    }
    return 0 ;
}
