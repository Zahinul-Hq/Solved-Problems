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
    	int n, k;

    	cin >> n >> k;

    	if(n == 1 && k == 1){
    		cout << 1 << endl << 1 << endl;
    		continue;
    	}

    	if(k >= n || k ==  1){
    		cout << -1  <<endl;
    		continue;
    	}
    	vector<int>ans;

    	if(k % 2 == 0){
    		ans.push_back(1);
    		ans.push_back(k);
    		ans.push_back(k + 1);

    		cout << 3 << endl;
    		for(auto i : ans){
    			cout << i << " ";
    		}
    		cout << endl;
    	}else{
    		ans.push_back(1);
    		ans.push_back(k - 1);
    		ans.push_back(k);
    		ans.push_back(k + 1);
    		ans.push_back(k + 2);
    		cout << 5 << endl;
    		for(auto i : ans){
    			cout << i << " ";
    		}
    		cout << endl;

    	}


    }
    return 0 ;
}
