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

    
       	int n, k;
       	cin >> n >> k;

       	vector<int> arr(n + 1, 0),pref(n + 1);
       	for(int i = 1; i <= n; i++){
       		cin >> arr[i];
       		pref[i] = pref[i - 1] + (arr[i] == 0); 
       	}
       	int ans = 0, x, y;
       	for(int i = 1; i <= n; i++){

       		int p = upper_bound(pref.begin() , pref.end(), pref[i - 1] + k) - pref.begin();

       		if(p > n)
       			p = n + 1;
       		if(ans < p - i){
       			ans = max(ans, p - i);
       			x = i, y = p;

       		}
       	}

       	cout << ans << endl;
       	for(int i = 1; i <= n; i++){
       		if(i >= x && i < y){
       			cout << 1 << " ";
       		}else{
       			cout << arr[i] << " ";
       		}

       	}
    
    return 0 ;
}
