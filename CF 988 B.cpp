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
    	ll k, x;

    	cin >> k;

    	map<ll,int>cnt;

    	for(int i = 0; i < k; i++){
    		cin >> x;
    		cnt[x]++;
    	}

    	for(ll i = 1; i <= (k - 2); i++){

    		if((k - 2) % i == 0){
    			ll p = (k - 2) / i;
    			if(cnt[i] > 0 && cnt[p] > 0 && p != i){
    				cout << i << " " << ((k - 2) / i) << endl;
    				break;
    				
    			}else if(cnt[i] >= 2 && p == i){
    				cout << i << " " << ((k - 2) / i) << endl;
    				break;

    			}
    		}
    	}
    }
    return 0 ;
}
