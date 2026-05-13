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
    	int n, q;
    	cin >> n;

    	vector<ll>arr(n + 1), pref(n + 1), ans;
    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		pref[i] = pref[i - 1] + arr[i];
    	}

    	cin >> q;
    	ll l, u;
    	while(q--){
    		cin >> l >> u;
    		ll val = u;
    		val += pref[l - 1];

    		int r = lower_bound(pref.begin(), pref.end(), val) - pref.begin();
    		
    		if(pref[r] == val || r > n || r == l){
    			ans.push_back(r - (r > n));
    			continue;
    		}

    		int rem = val - pref[r - 1];

    		if(2 * rem >= arr[r])
    			ans.push_back(r);
    		else
    			ans.push_back(r - 1);

    	}

    	for(auto i : ans){
    		cout << i << " ";
    	}
    	cout << endl;

        
    }
    return 0 ;
}
