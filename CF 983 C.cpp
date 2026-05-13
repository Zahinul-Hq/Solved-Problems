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
    	int n;
    	cin >> n;
    	vector<ll>arr(n + 1 , 0);

    	for(int i = 1; i <= n ; i++){
    		cin >> arr[i];
    	}
    	sort(arr.begin(), arr.end());

    	int op = INT_MAX;

    	debug(arr);
    	for(int i = 2; i <= n; i++){
    		ll val = arr[i] + arr[i - 1];

    		int r = lower_bound(arr.begin(), arr.end(), val) - arr.begin();

    		debug(i, n + 1 - r);

    		

    		op = min(op, i + n +1 - r - 2);
    		if(r > n)
    			break;
    	}

    	if(INT_MAX == op){
    		cout  << 0 << endl;
    	}else{
    		cout << op << endl;

    	}

    	
    }
    return 0 ;
}
