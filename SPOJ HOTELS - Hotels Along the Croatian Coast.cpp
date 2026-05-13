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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    ll n, m, x;

    cin >> n >> m;

    vector<ll>arr(n + 1,0), pref(n + 1,0);


    for(int i = 1; i <= n; i++){
    	cin >> arr[i];
    	pref[i] = pref[i - 1] + arr[i];
    }

    ll sum = 0;

    for(int i = 0; i <= n; i++){

    	int pos = upper_bound(pref.begin(), pref.end(), m + pref[i]) - pref.begin();

    	if(pos > n) pos = n;

    	if(pref[pos] - pref[i] <= m){
    		sum = max(sum, pref[pos] - pref[i]);
    	}
    	if(pref[pos - 1] - pref[i] <= m){
    		sum = max(sum, pref[pos - 1] - pref[i]);
    	}
    }

    cout << sum << endl;


    return 0 ;
}
