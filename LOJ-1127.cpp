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
const int N = 35;
vector<ll> subset_sum(vector<ll> arr){
	vector<ll>sums;
	for(int i = 0; i < (1 << arr.size()); i++){
		ll sum = 0;
		for(int j = 0; j < arr.size(); j++){
			if(i & (1 << j)){
				sum += arr[j]; 
			}
		}
		sums.push_back(sum);
	}
	return sums;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases,cs =1 ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, x, W;
        cin >> n >> W;
        vector<ll>v1, v2, sums1, sums2;


        for(int i = 0; i < n; i++){
        	cin >> x;
        	if(i & 1)
        		v1.push_back(x);
        	else
        		v2.push_back(x);
        }
        sums1 = subset_sum(v1);
        sums2 = subset_sum(v2);
        sort(sums2.begin(), sums2.end());

        ll ans = 0;
        for(ll val : sums1){
        	ll s = W - val;
        	ans += upper_bound(sums2.begin(), sums2.end(), s) - sums2.begin();
        }

        cout << "Case " << cs++ << ": "<< ans << endl;
    }
    return 0 ;
}
