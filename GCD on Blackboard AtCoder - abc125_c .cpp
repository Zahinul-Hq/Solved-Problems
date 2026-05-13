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

    
        int n;
        cin >> n;
        vector<int>arr(n + 1, 0), gcd_suff(n + 2, 0), gcd_pref(n + 1 ,0);
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }
        int g = 0;

        for(int i = 1; i <= n; i++){
        	gcd_pref[i] = __gcd(gcd_pref[i - 1], arr[i]);
        }
        for(int i = n; i >= 1; i--){
        	gcd_suff[i] = __gcd(gcd_suff[i + 1], arr[i]);
        }

        for(int i = 1; i <= n; i++){
        	g = max(g, __gcd(gcd_pref[i - 1], gcd_suff[i + 1]));
        }

        cout << g << endl;



    
    return 0 ;
}
