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
	int n;
	cin >> n;
	ll pref[14][n + 5];
	vector<ll>arr(n + 5, 0), mnth(n + 5,0),mm[14];

	for(int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> mnth[i];
	}
	for(int i = 1; i <= n; i++){
		mm[mnth[i]].push_back(arr[i]);
		sort(mm[mnth[i]].rbegin(), mm[mnth[i]].rend());
	}
	memset(pref, 0, sizeof pref);
	for(int i = 1; i <= 12; i++){
		if(mm[i].size() == 0)
			continue;
		for(int j = 1; j <= mm[i].size(); j++){
			pref[i][j] = pref[i][j - 1] + mm[i][j - 1];
			
		}
	}
	
    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int typ ,x, y; 
        cin >> typ;
        if(typ == 1){
        	cin >> x;
        	ll ans = 0;
        	for(int i = 1; i <= x; i++){
        		int pos = mm[i].size();
        		ans += (pref[i][pos] - pref[i][0]);
        	}
        	cout << ans << endl;
        }else{
        	cin >> x >> y;
        	ll ans = 0;
        	for(int i = 1; i <= x; i++){
        		int pos = mm[i].size();
        		pos =  min(pos , y);
        		ans += (pref[i][pos] - pref[i][0]);
        	}
        	cout << ans << endl;

        }

        
    }
    return 0 ;
}