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
        int n, sum = 0;
        cin >> n;

        vector<int>arr(n, 0), ans;

        for(int i = 0; i < n - 1; i++){
        	cin >> arr[i];

        	sum += arr[i];
        }

        ans.push_back(sum + 1);

        for(int i = 0; i < n - 1; i++){
        	ans.push_back(ans.back() + arr[i]);
        }

        for(auto i : ans){
        	cout << i << " ";
        }

        cout << endl;
    }
    return 0 ;
}
