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
vector<bool>mask(int val, int n){
	vector<bool>ans(n, 0);
	int i = 0;
	while(val){
		if(val % 2 == 1){
			ans[i] = 1;
		}
		val = val / 2;
		i++;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
    ll mn_diff = inf;

    for(int i = 1; i <= (1 << n); i++){
    	ll sum_left = 0, sum_right = 0;
    	vector<bool>temp = mask(i, n);
    	for(int j = 0; j < n; j++){
    		if(temp[j]){
    			sum_left += arr[j];
    		}else{
    			sum_right += arr[j];
    		}
    	}

    	mn_diff = min(mn_diff, abs(sum_left - sum_right));
    }

    cout << mn_diff << endl;

    return 0 ;
}
