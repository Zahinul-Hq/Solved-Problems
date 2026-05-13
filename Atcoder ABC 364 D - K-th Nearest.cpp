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

    int n, q, b, k;
    cin >> n >> q;

    vector<int>arr(n, 0);
    for(int i = 0;i < n; i++){
    	cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    while(q--){
    	cin >> b >> k;

    	auto f = [&](int x) -> bool{
    		auto lb = lower_bound(arr.begin(), arr.end(), b - x);
    		auto ul = upper_bound(arr.begin(), arr.end(), b + x);
    		return ul - lb >= k;
    	};

    	int lw = 0, hi = 2e8 + 7, ans = 0;

    	while(hi >= lw){
    		int mid = (hi + lw) / 2;

    		if(f(mid)){
    			ans = mid;
    			hi = mid - 1;
    		}else{
    			lw = mid + 1;
    		}
    	}

    	cout << ans << endl;

    }
    return 0 ;
}
