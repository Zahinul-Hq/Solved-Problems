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
    	int n,x ;
    	cin >> n;
    	int cnt1 = 0, cnt0 = 0;

    	for(int i = 0; i < 2*n; i++){
    		cin >> x;
    		cnt1 += x;
    	}

    	cnt0 = 2*n - cnt1;

    	if(cnt1 % 2 == 0){
    		cout << 0 << " " << min(cnt1, cnt0) << endl;
    	}else{
    		cout << 1 << " " << min(cnt1, cnt0) << endl;
    	}

    }
    return 0 ;
}
