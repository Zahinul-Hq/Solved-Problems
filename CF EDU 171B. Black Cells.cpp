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

const int N = 2005;
vector<ll>arr(N);

bool check(ll k, int n){

	ll mn_diff = inf;

	for(int i = 1; i <= n; i += 2){
		ll mnn = 1;
		for(int j = 2; j < i; j += 2){

			mnn = max(mnn, arr[j] - arr[j - 1]);
		}
		for(int j = i + 2; j <= n; j += 2){

			mnn = max(mnn, arr[j] - arr[j - 1]);
		}

		mn_diff = min(mn_diff, mnn);

		debug(i, mn_diff, k);
	}	//ebug(mn_diff, k);


	return mn_diff <= k;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	cin >> n;

    	ll mn = 1;

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    		if(n % 2 == 0 && i % 2 == 0){
    			mn = max(mn, arr[i] - arr[i - 1]);

    		}
    	}

    	if(n % 2 == 0){
    		cout << mn << endl;
    		continue;
    	}

    	ll hi = 1e18, lo = 0, ans = 1;

    	while(hi >= lo){

    		ll mid = (hi + lo) / 2;

    		if(check(mid, n)){
    			hi = mid - 1;
    			ans = mid;
    		}else{
    			lo = mid + 1;
    		}


    		//debug(ans, mid, hi, lo );

    	}

    	cout << ans << endl;



    }
    return 0 ;
}
