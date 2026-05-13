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
        int n, k;
        cin >> n >> k;
        vector<int>arr(n, 0);

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        }

        ll mx = *max_element(arr.begin(), arr.end());

        auto possible = [&](ll mid)->bool{
        	if (mx >= mid)
        		return true;
        	for(int i = 0; i < n - 1; i++){
        		vector<int> temp = arr;
        		int ii = i;
        		int rem = k;

        		int target = mid;

        		while(1){
        			if(rem < 0 || ii == n)
        				break;
        			if(temp[ii] >= target)
        				return true;
        			rem -= (target - temp[ii]);
        			target--;
        			ii++;
        		}
        	}
        	return false;
        };

        ll hi = 2e8 + 10, lo = 2, ans = mx;

        while(hi >= lo){
        	ll mid = (lo + hi) / 2;

        	if(possible(mid)){
        		ans = mid;
        		lo = mid + 1;
        	}else{
        		hi = mid - 1;
        	}
        }

        cout << ans << endl;


    }
    return 0 ;
}
