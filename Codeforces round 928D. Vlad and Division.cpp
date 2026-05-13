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

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n;
        cin >> n;

        int mx = (1LL << 31) - 1;
        int zero_count = 0, mx_count = 0;
        map<int,int> mp;

       	vector<int>arr(n);
       	for(int i = 0; i < n; i++){
       		cin >> arr[i];
       		mp[arr[i]]++;
       	}
       	ll ans = n;
       	for(int i = 0; i < n; i++){
       		int val =  mx ^ arr[i];
       		//cout << val << " " ;
       		if(mp[val] > 0 && mp[arr[i]] > 0){
       			mp[val]--;
       			mp[arr[i]]--;
       			ans--;
       		}
       	}

       	cout << ans << endl;
    }
    return 0 ;
}
