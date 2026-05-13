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
        int n, mod;
        string s;
        cin >> n >> mod;
       
        vector<ll>arr(n + 1), pref(n + 1), ans;
        pref[0] = 1;

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];

        }
        cin >> s;
        int left_cnt = 0, right_cnt = 0;
        for(int i = 0; i < n - 1; i++){
        	left_cnt += (s[i] == 'L');
        	right_cnt += (s[i] == 'R');
        }
        int pos = left_cnt + 1 ;
        left_cnt = 0, right_cnt = 0;
        ll mul = arr[pos] % mod;
        ans.push_back(mul);

        for(int i = n - 2; i >= 0; i--){
        	if(s[i] == 'L'){
        		
        		left_cnt++;
        		mul *= arr[pos - left_cnt];
        		mul %= mod;
        		ans.push_back(mul);
        	}else{
        		
        		right_cnt++;
        		mul *= arr[pos + right_cnt];
        		mul %= mod;
        		ans.push_back(mul);
        	}
        }

        reverse(ans.begin(), ans.end());
        for(auto i : ans){
        	cout << i << " ";
        }
        cout << endl;




    }
    return 0 ;
}
