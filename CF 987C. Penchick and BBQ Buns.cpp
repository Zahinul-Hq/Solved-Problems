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
    	vector<int>ans(n + 1, 1);

    	if(n % 2 == 0){
    		for(int i = 1; i <= n; i += 2){
    			ans[i] = i;
    			ans[i + 1] = i;
    		}
    		
    	}else{

    		if(n < 26){
    			cout << -1 << endl;
    			continue;
    		}else{
    			int val = 2;
    			for(int i = 2; i <= n; i += 2){
    				if(i == 1 || i == 10 || i == 26 || i == 27 || i == 11){
    					continue;
    				}
    				ans[i] = val;
    				ans[i + 1] = val;
    				val++;
    			}
    			ans[27] = val;
    			ans[11] = val;
    		}

    	}
    	for(int i = 1; i <= n; i++){
    		cout << ans[i] << " ";
    	}
    	cout << endl;
    }
    return 0 ;
}
