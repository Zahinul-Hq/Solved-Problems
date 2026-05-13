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

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        ll n, m, k, w;
        cin >> n >> m >> k >> w;
        vector<ll>arr(w + 1, 0), val, x;

        for(int i = 1; i <= w; i++){
        	cin >> arr[i];
        } 

        for(ll j = k ; j >= 1 ; j--){

        	val.push_back(j * j);
        	x.push_back((n/j) + (m/j));
        }

        for(int i = 0; i < x.size(); i++){
        	if(i)
        		x[i] = x[i - 1] + x[i];
        	//cout << x[i] << " ";
        }

        ll ans  = 0, p = 0;

        sort(arr.rbegin(), arr.rend());

        for(int i = 1; i <= w; i++){
        	if(p < (k -1) && x[p] > i){
        		p++;
        	}
        	ans += (val[p] * arr[i]);

        }

        cout << ans << endl;
    }
    return 0 ;
}
