#include<bits/stdc++.h>
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

        vector<int> arr(n), a(n), b(n), c(n);

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        }

        for(int i = 0; i < n - 2; i++){
        	a[i] = arr[i];
        	b[i] = arr[i + 1];
        	c[i] = arr[i + 2];
        }
        map<pair<int,int>, int>mp;
        map<pair<int,pair<int,int>>, int>mpa;

        ll ans = 0;

        for(int i = 0; i < n - 2; i++){

        	pair<int,int>p = {a[i], b[i]};
        	pair<int,pair<int,int>> pa = {a[i], {b[i], c[i]}};
        	mp[p]++;
        	mpa[pa]++;
        	if(mp[p] > 1){
        		ans += mp[p];
        		ans  -= mpa[pa];
        	}
        }
        mp.clear();
        mpa.clear();
        for(int i = 0; i < n - 2; i++){

        	pair<int,int>p = {a[i], c[i]};
        	pair<int,pair<int,int>> pa = {a[i], {b[i], c[i]}};
        	mp[p]++;
        	mpa[pa]++;
        	if(mp[p] > 1){
        		ans += mp[p];
        		ans  -= mpa[pa];
        	}
        }
        mp.clear();
        mpa.clear();
        for(int i = 0; i < n - 2; i++){

        	pair<int,int>p = {b[i], c[i]};
        	pair<int,pair<int,int>> pa = {a[i], {b[i], c[i]}};
        	mp[p]++;
        	mpa[pa]++;
        	if(mp[p] > 1){
        		ans += mp[p];
        		ans  -= mpa[pa];
        	}
        }


        cout << ans  << endl;


    }
    return 0 ;
}
