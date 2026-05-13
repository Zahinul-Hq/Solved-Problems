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

    int test_cases , cs = 1;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, max_gcd = 0;
        cin >> n;
        vector<ll>arr(n + 1);

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        vector<ll>prefix_sqsum(n + 1, 0);
        for(int i = 1; i <= n; i++){
        	prefix_sqsum[i] = prefix_sqsum[i - 1] + (arr[i] * arr[i]);
        }

        max_gcd = arr[n - 1];
        ll max_cost = inf, gcd = 0;

        for(ll i = 2; i <= max_gcd; i++){

        	ll cost = abs((i * i * n) - prefix_sqsum[n]);

        	if(max_cost >= cost){
        		gcd = i;
        		max_cost = cost;
        	}
        }
        cout << "Case " << cs++ << ": " << max_cost << " " << gcd << endl;
    }
    return 0 ;
}
