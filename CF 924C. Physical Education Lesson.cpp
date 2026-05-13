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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, x;
        cin >> n >> x;
       	ll ans = 0;

        for(int d = 1; d * d <= n - x ; d++){
        	if((n - x) % d == 0 ){
        		if((((n - x) / d) + 2) / 2 >= x && (((n - x) / d)) % 2 == 0 ){
        			if(n - x != d*d)
        				ans++;
        		}
        		if((d + 2) / 2 >= x && d % 2 == 0){
        			ans++;
        		}
        	}
        	
        }
        for(int d = 1; x!= 1 && d * d <= n + x - 2 ; d++){
        	
        	if((n + x - 2) % d == 0){
        		if((((n + x - 2) / d) + 2) / 2 > x && (((n + x - 2) / d)) % 2 == 0 ){
        			if((n + x - 2) != d * d)
        				ans++;
        		}
        		if((d + 2) / 2 > x  && d % 2 == 0){
        			ans++;
        		}

        	}
        }

        cout << ans << endl;
    }
    return 0 ;
}
