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
        int n;
        cin >> n;

        ll sum = 0, ans = 0;
        vector<ll>arr(n + n, 0);

        for(int i = 0; i < n * 2; i++){
        	cin >> arr[i];
        	ans += abs(arr[i]);
        	sum += abs(arr[i] - (-1));
        }
        if(n == 1){
        	cout << min(ans,abs(arr[0] - arr[1])) << endl;
        	continue;
        }else if(n == 2){
        	ans = min(ans, abs(arr[0]- 2) + abs(arr[1]- 2) + abs(arr[2]- 2)+ abs(arr[3]- 2)) ;
        }
        if(n % 2 == 0){
        	for(int i = 0; i < 2 * n; i++){
        		ans = min(ans , sum - abs(arr[i] - (-1)) + abs(arr[i] - n));
        	}
        }

        cout << ans << endl;
    }
    return 0 ;
}
