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
const  int N = 2e5 + 7;
vector<int>arr(N, 0);
int last = INT_MAX, n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {

        cin >> n;
        for(int i = n - 1; i >= 0; i--){
        	cin >> arr[i];
        }
        ll total_op = 0;
        last = arr[0];
        for(int i = 1; i < n; i++){
        	if(arr[i] > last){
        		int k = (arr[i] + last - 1) / last;
        		total_op += (k - 1);
        		last = (arr[i] / k); 
        	}else{
        		last = arr[i];
        	}
        	//cout << last << endl;
        }
        cout << total_op << endl;
    }
    return 0 ;
}
