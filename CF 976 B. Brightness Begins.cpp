#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
//#define low   -2e18
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
ll floorSqrt(ll n) {
    ll low = 1, high = n;
   
    while (low <= high) {
        ll mid = (low + high) / 2;
        if (mid <= ((ll)(n) / mid)){
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return high;
}
ll k, sq;
bool f(ll x){
	ll d = floorSqrt(x);
	return k <= (x - d);
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
    	cin >> k;

    	ll lo = k + floorSqrt(k), hi = floorSqrt(1e18) + 1e18, ans = 0;

    	while(hi >= lo){

    		ll mid =  (hi + lo) / 2;

    		if(f(mid)){
    			ans = mid;
    			hi = mid - 1;
    		}else{
    			lo = mid + 1;
    		}
    	}

    	cout << ans << endl;
  
    }
    return 0 ;
}
