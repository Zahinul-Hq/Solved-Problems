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
    	ll n, m, L, l , r, p , x, c = 1, j = 0;

    	cin >> n >> m >> L;

    	vector<pair<int,int>>rng, vals;
    	vector<ll>arr[n + 2];
    	map<int,int>mp;
 
    	ll ls = 0;

    	for(int i = 0; i < n; i++){
    		cin >> l >> r;

    		if(r - l + 1 > ls){
    			rng.push_back({l, r});
    			ls = r - l + 1;
    		}
    		mp[l] = c++;
    		
    	}
    	
    	for(int i = 0; i < m; i++){
    		cin >> p >> x;

    		if(j < rng.size()){
    			if(p < rng[j].F){
    				arr[j].push_back(x);
	    		}else if(j + 1 < rng.size()){
	    			j++;
	    			arr[j].push_back(x);
	    		}

    		}
    	}

    	ll ans=0;
    	ll sum = 0;

    	//cout << rng.size() << endl;


    	for(int i = 0; i < rng.size(); i++){
    		sort(arr[i].rbegin(), arr[i].rend());
    		bool f = 1;
    		debug(rng[i], arr[i]);


    		for(int k = 0; k < arr[i].size(); k++){

    			if(sum >= (rng[i].S - rng[i].F + 1)){
    				break;
    			}

    			sum += arr[i][k];
    			ans++;
    		}

    		if(sum < ((rng[i].S - rng[i].F + 1))){
    			ans = -1;
    			break;
    		}
    	}

    	cout << ans << endl;

    }
    return 0 ;
}
