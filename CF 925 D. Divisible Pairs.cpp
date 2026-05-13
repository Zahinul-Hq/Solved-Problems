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

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, x, y, val;
        cin >> n >> x >> y;

        vector<int>vx, vy, arr;
        map<pair<int,int>, int>mp;

        ll ans = 0;
        for(int i = 0; i < n; i++){
        	cin >> val;
        	int search_x = x - (val % x);
        	int search_y = (val % y);
        	if(val % x == 0){
        		ans += mp[{0, search_y}];
        	}else
        		ans += mp[{search_x, search_y}];
        	mp[{val % x, search_y}]++;
        	
        }
        cout << ans << endl;

    }
    return 0 ;
}
