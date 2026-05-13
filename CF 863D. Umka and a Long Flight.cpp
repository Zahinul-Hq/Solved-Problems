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

    ll fib[50] ;
    fib[0] = fib[1] = 1;
    for(int i = 2; i <= 45; i++){
    	fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    while (test_cases--)
    {
        ll n, x, y;
        cin >> n >> x >> y;

        bool ok = 1;
        ll dx = fib[n + 1] , dy = fib[n], tx = 0, ty = 0;

        for(int i = n; i >= 1; i--){
        	ll dis = fib[i];
        	
        	if(dx - y >= dis){
        		dx = dx - dis;
        	}else if(x - tx > dis){
        		tx = tx + dis;
        	}else if(dy  - x >= dis){
        		dy = dy - dis;
        	}else if(y - ty > dis){
        		ty = ty + dis;
        	}else{
        		ok = 0;
        		break;
        	}
        }

        if(ok){
        	cout << "YES" << endl;
        }else{
        	cout << "NO" << endl;
        }
    }
    return 0 ;
}
