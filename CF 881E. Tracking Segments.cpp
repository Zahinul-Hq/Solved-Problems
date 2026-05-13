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
const int N = 1e5 + 7;
int l[N], r[N], arr[N];
int n, q, m;
bool check(int last){

	ll pref[n + 2], a[n + 2];
	for(int i = 0; i <= n + 1; i++){
		pref[i] = a[i] = 0;
	}
	for(int i = 1; i <= last; i++){
		a[arr[i]] = 1;
	}
	for(int i = 1; i <= n; i++){
		pref[i] = pref[i - 1] + a[i];
	}
	//cout << endl;
	for(int i = 1; i <= m; i++){
		//cout << pref[r[i]] - pref[l[i] - 1] << " " << ((r[i] - l[i]) / 2 ) << endl;
		if((pref[r[i]] - pref[l[i] - 1]) > ((r[i] - l[i] + 1) / 2 )){
			//cout << last << " " <<i << endl;
			return true;
		}
	}
	return false;
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
        
        cin >> n >> m;

        for(int i = 1; i <= m; i++){
        	cin >> l[i] >> r[i];
        }
        cin >> q;
        for(int i = 1; i <= q; i++){
        	cin >> arr[i];
        }
        ll hi = q , lo = 1, ans = inf;

        while(hi >= lo){
        	ll mid = (hi + lo ) / 2;

        	//cout << mid << endl;

        	if(!check(mid)){
        		lo = mid + 1;
        	}else{
        		//cout << hi << endl;
        		ans = mid;
        		hi = mid - 1;
        	}
        }

        if(ans == inf)
        	cout << -1 << endl;
        else
        	cout << ans << endl;


    }
    return 0 ;
}
