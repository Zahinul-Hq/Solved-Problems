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
    	int n, m;
    	cin >> n >> m;

    	vector<int>ans(n + 1, 0), arr(m);

    	for(int i = m - 1; i >= 0; i--){
    		cin >> arr[i];
    	}
    	
    	ans[1] = 0;
    	bool ok = 1;
    	for(ll i = 1; i  <= n; i++){
    		for(int j = i + i; j <= n; j += i){
    			if(ans[i] + 1 >= m )
    				ok = 0;

    			ans[j] = ans[i] + 1;
    		}
    	}

        if(!ok){
            cout << -1 << endl;
        }else{

    		for(int i = 1; i <= n; i++){
    			cout << arr[ans[i]] << " ";
    		}
    		cout << endl;
    	}
    }
    return 0 ;
}
