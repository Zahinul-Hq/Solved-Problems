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

        vector<int>arr(n, 0), vis(n, 0), ans;

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        }

        int prefix = 0;

        for(int i = 0; i < 32; i++){
        	int indx = -1, curr_mx = prefix;
        	for(int j = 0; j < n; j++){
        		if(!vis[j]){
        			int val = (prefix | arr[j]);
        			if(val > curr_mx){
        				indx = j;
        				curr_mx = val;     			
        			}

        		}
        	}

        	if(indx != -1){
        		vis[indx] = 1;
        		prefix |= arr[indx];
        		ans.push_back(arr[indx]);
        	}
        }


        for(auto i : ans)
        	cout << i << " ";

        for(int i = 0; i < n; i++){
        	if(!vis[i])
        		cout << arr[i] << " ";
        }

        cout << endl;



    }
    return 0 ;
}
