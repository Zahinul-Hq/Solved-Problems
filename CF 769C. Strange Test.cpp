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
const int N = 2097152;
int a, b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	cin >> a >> b;

    	int ans = b - a;

    	for(int i = a; i < b; i++){
    		int temp = 0;

    		for(int j = 21; j >= 0; j--){
    			if(b & (1 << j)){
    				temp ^= (1 << j);
    			}else{
    				if(i & (1 << j)){
    					temp ^= (1 << j);
    					break;
    				}
    			}
    		}
    		ans = min(ans, i + (i | temp) + 1 - a - b);
    	}
    	cout << ans << endl;
        
    }
    return 0 ;
}
