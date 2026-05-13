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
        ll n , m ;

        cin >> n >> m ;

        vector<ll> last_indx(n + m + 5, 0), arr(n, 0);

        ll ans = n * m * ( m + 1) ;


        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	last_indx[arr[i]] = m + 1;
        }

        for(int i = 0; i < m; i++){
        	int pos, val;
        	cin >> pos >> val;
        	pos--;

        	last_indx[arr[pos]] -= (m - i);
        	last_indx[val] += (m - i);

        	arr[pos] = val;
        }

        for(int i = 0; i <= n + m; i++){
        	ans -= ((last_indx[i] * (last_indx[i] - 1)) / 2);
        }

        cout << ans << endl;
    }
    return 0 ;
}
