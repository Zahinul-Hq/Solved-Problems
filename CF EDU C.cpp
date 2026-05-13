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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll>arr(n), narr;
        map<ll,ll>mp;
        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	
        }
        sort(arr.begin(), arr.end());
        narr = arr;
        narr.erase(unique(narr.begin(), narr.end()), narr.end());
        reverse(narr.begin(), narr.end());

        int last =  narr[0];
        mp[narr[0]] = narr[0];

        for(int i = 1; i < narr.size(); i++){
        	if(abs(narr[i] - narr[i - 1]) <= 1){
        		mp[narr[i]] = last ;
        	}else{
        		last = narr[i];
        		mp[narr[i]] = narr[i];
        	}

        }

        ll mx = 0;

        for(int i = narr.size() - 1; i >= 0; i--){
        	ll cnt = upper_bound(arr.begin(), arr.end(), min(mp[narr[i]], narr[i] + x - 1)) - lower_bound(arr.begin(), arr.end(), narr[i]);
        	mx = max(mx, cnt);

        	//cout << mp[narr[i]] << " " << cnt << endl;
        	
        }

        cout << mx << endl;

        
    }
    return 0 ;
}
