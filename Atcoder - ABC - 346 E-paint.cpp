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

	int h, w , m;

	cin >> h >> w >> m;

	vector<int> t(m + 1), a(m + 1), x(m + 1);

	for(int i = 0; i < m; i++){
		cin >> t[i] >> a[i] >> x[i];
		t[i]--;
	}
    map<pair<int,int>, bool> used;
    map<int, ll> cnt;
   	ll rc[2] = {w, h};

   	while(m--){

   		if(!used[{t[m], a[m]}]){
   			used[{t[m], a[m]}] = 1;
   			cnt[x[m]] += rc[t[m]];
   			rc[t[m] ^ 1]--;
   		}
   	}
   	cnt[0] += (rc[0] * rc[1]);
   	int c = 0;
   	for(auto i : cnt){
   		if(i.S)
   			c++;
   	}
   	cout << c << endl;

   	for(auto i : cnt){
   		if(i.S)
   			cout << i.F << " " << i.S << endl;
   	}
    return 0 ;
}
