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

   	string a, b;

   	cin >> a >> b;

   	int pref[b.size() + 1][2];
   	pref[0][1] = 0;
   	pref[0][0] = 0;

   	for(int i = 1; i <= b.size(); i++){

   		pref[i][0] = pref[i - 1][0] + (b[i - 1] == '1');
   		pref[i][1] = pref[i - 1][1] + (b[i - 1] == '0');
   	}

   	ll ans = 0;

   	for(int i = 1; i <= a.size(); i++){
   		int val = a[i - 1] - '0';
   		int l = i - 1, r = b.size() + i - a.size();

   		ans += (pref[r][val] - pref[l][val]);
   	}

   	cout << ans << endl;

    return 0 ;
}
