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

vector<bool>bin_convert(int val){
	vector<bool>ans(40, 0);
	int indx = 0;
	while(val){
		ans[indx++] = val % 2;
		val = val / 2;
	}
	return ans;
}

vector<vector<int>>pre_calc(int n, vector<int>&arr){
	vector<vector<int>> pre_val(40, vector<int>(n + 2,-1));

	for(int j = n; j >= 1; j--){
		vector<bool>bin = bin_convert(arr[j]);
		for(int i = 0; i < 40; i++){
			if(!bin[i]){
				pre_val[i][j] = j;
			}else{
				pre_val[i][j] = pre_val[i][j + 1];
			}
		}
	}

	/*for(int j = n; j >= 1; j--){
		for(int i = 0; i < 40; i++){
			cout << pre_val[i][j] << " ";
		}
		cout << endl;
	}*/
	return pre_val;
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
        int n, q;
        cin >> n;

        vector<int>arr(n + 1);
        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        }

        vector<vector<int>> pref = pre_calc(n, arr);

        cin >> q;
        while(q--){

        	int l , k;
        	cin >> l >> k;

        	if(arr[l] < k){
        		cout << -1 << " ";
        		continue;
        	}
        	if(l == n){
        		cout << n << " ";
        		continue;
        	}
        	ll hi = n, lo = l, ans = l;

        	while(hi >= lo){
        		ll r = (hi + lo) / 2;
        		ll val = 0;

        		for(int i = 0; i < 40; i++){
        			if(pref[i][l] == pref[i][r])
        				val += (1 << i);
        		}

        		if(val >= k){
        			lo = r + 1;
        			ans = max(ans, r);
        		}else{
        			hi = r - 1;
        		}
        	}

        	cout << ans   << " ";


        }
        cout << endl;
    }
    return 0 ;
}
