#include<bits/stdc++.h>
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
        int n;

        cin >> n;

        vector<int> arr(n + 1);

        for(int i = 1 ; i <= n; i++){
        	cin >> arr[i];
        }
        if(n < 3){
        	cout << min(arr[1], arr[2]) << endl;
        	continue;
        }

        int mx = 0;

        for(int l = 3; l <= 3 ; l++){
        	for(int i = 1; i <= n - l + 1; i++){
        		int r = i + l - 1 ;
        		vector<int>temp ;

        		for(int j = i; j <= r; j++){
        			temp.push_back(arr[j]);
        		}

        		sort(temp.begin(), temp.end());

        		int mid = (temp.size() + 1) / 2;

        		if(mid > 0){
        			mx = max(mx, temp[mid - 1]);
        		
        		}
        	}
        }

        cout << mx << endl;
    }
    return 0 ;
}
