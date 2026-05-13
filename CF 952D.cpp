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
        ll x, y, z, k;

        cin >> x >> y >> z >> k;

        vector<ll>xv, yv, zv;

        for(ll i = 1; i <= x; i++){
        	for(ll j = 1; j <= y; j++){
        		if((k % (i * j)) == 0){
        			if(k / (i * j) <= z){
        				xv.push_back(i);
        				yv.push_back(j);
        				zv.push_back((k / (i * j)));
        				
        			}
        		}
        	}
        }
        /*if(!cnt){
        	cout << 0 << endl;
        	continue;
        }*/

        ll ans = 0;
        
        for(int i = 0; i < xv.size(); i++){
        	ll x_cnt = x - xv[i] + 1, y_cnt = y - yv[i] + 1, z_cnt = z - zv[i] + 1;

        	ans = max(ans, (x_cnt * y_cnt * z_cnt));
        }

        cout << ans << endl;
        


    }
    return 0 ;
}
