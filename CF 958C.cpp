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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n;
        cin >> n;

        vector<ll>bin, ans;

        ll val = n;

        while(val > 0){
        	bin.push_back(val % 2);
        	val = val / 2;
        }
        ans.push_back(n);

        for(ll i = 0; i < bin.size(); i++){
        	if(bin[i]){
        		ll x = n - (1LL << i);
        		if(x > 0)
        			ans.push_back(x);
        	}

        }
        reverse(ans.begin(), ans.end());

        cout << ans.size() << endl;
        for(auto i : ans){
        	cout << i << " ";
        }
        cout << endl;
    }
    return 0 ;
}
