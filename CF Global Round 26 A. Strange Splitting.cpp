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
       	vector<int> arr(n + 1, 0);

        bool flag = 0;

        for(int i = 0; i < n; i++){
        	cin >> arr[i];
        	
        }
        for(int i = 1; i < n; i++){
        	if(arr[i] != arr[i - 1])
        		flag = 1;
        	
        }

        if(!flag){
        	cout << "NO" << endl;
        	continue;
        }

        string s;
        for(int i = 0; i < n; i++){
        	s += 'R';
        }

        if(arr[n - 2] == arr[n - 3]){
        	s[n - 1] = 'B';
        	s[n - 2] = 'B';
        }else{
        	s[n - 1] = 'B';
        }

        cout << "YES" << endl << s << endl;
    }
    return 0 ;
}
