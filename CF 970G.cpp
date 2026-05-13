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
        int n, k;
        cin >> n >> k;
        vector<ll> arr(n);



        ll gcd = 0;

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	gcd = __gcd(gcd, arr[i]);
        }
        if(n == 1){
        	cout << (k - 1) + (gcd < k) << endl;
        	continue;
        }
        ll i = 1, rng = k, val = 0;
        for(; i < n; i++){
        	if(rng - gcd < 0)
        		break;
        	val += gcd;
        	rng -= (gcd - 1);
        }

        cout << val + rng << endl; 
        
    }
    return 0 ;
}
