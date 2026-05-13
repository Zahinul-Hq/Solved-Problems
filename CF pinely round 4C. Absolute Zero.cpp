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
        int n, odd = 0, even =0;
        cin >> n;
        vector<int>arr(n), ans;
        for(int i = 0 ; i < n; i++){
        	cin >> arr[i];
        	if(arr[i] % 2 != 0)
        		odd++;
        	else{
        		even++;
        	}
        }



        bool ok = (odd == n) || (even == n);
        if(odd == n){
        	for(int i = 0;i < n ; i++){
        		arr[i]--;
        	}
        	ans.push_back(1);
        }


        int t = 40;

        while(t--){
        	int mx = *max_element(arr.begin(), arr.end());
        	int mn = *min_element(arr.begin(), arr.end());

        	bool all_eq = (mx == mn);
        	if(all_eq){
        		for(int i = 0; i < n; i++){
        			arr[i] = 0;
        		}
        		ans.push_back(mn);
        		break;
        	}

        	int d = (mx / 2);

        	int od = 0, ev = 0;


        	for(int i = 0; i < n; i++){
        		if(arr[i] % 2 != 0){
        			od++;
        		}else{
        			ev++;
        		}
        		arr[i] = abs(arr[i] - d);
        	}
        	bool ok = (od == n) || (ev == n);
        	ans.push_back(d);
        
        }

        if(ok){
        	cout << ans.size() << endl;
        	for(auto i : ans){
        		cout << i << " ";
        	}
        	cout << endl;
        }else{
        	cout << -1 << endl;
        }
    }
    return 0 ;
}
