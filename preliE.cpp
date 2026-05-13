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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, m; 
        cin >> n >> m;

        vector<ll>ps(n, 0), ext(m ,0);

        for(int i = 0; i < n; i++){
        	cin >> ps[i];
        }
        for(int i = 0; i < m; i++){
        	cin >> ext[i];
        }

        //sort(ps.begin(), ps.end());

        sort(ext.begin(), ext.end());

        unsigned long long ans = 0;

        for(int i = 0; i < n; i++){
        	ll pos = lower_bound(ext.begin(), ext.end(), ps[i]) - ext.begin();
        	ll val = abs(ext[pos] - ps[i]);
        	if(pos - 1 >= 0){
        		ll x = abs(ext[pos - 1] - ps[i]);
        		val = min( x , val);
        	}
        	ans += val;
        }
        cout << ans << endl;
    }
    return 0 ;
}
