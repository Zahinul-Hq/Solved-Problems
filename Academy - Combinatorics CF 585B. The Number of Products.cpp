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

    
       	int n, x;

       	cin >> n;

       	vector<int>arr(n +1), pref(n + 1);

       	pref[0] = 1;


       	for(int i = 1; i <= n; i++){
       		cin >> x;

       		if(x > 0) arr[i] = 1;
       		else arr[i] = -1;

       		pref[i] = pref[i - 1] * arr[i];
       	}

       	map<int,int>cnt;
       	cnt[pref[0]]++;

       	ll ans = 0;

       	for(int i = 1; i <= n; i++){
       		ans += cnt[pref[i]]++;
       		
       	} 

       	cout << 1LL * n * (n + 1) / 2 - ans << " " << ans << endl;
    
    return 0 ;
}
