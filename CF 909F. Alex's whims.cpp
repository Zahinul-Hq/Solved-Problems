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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n, q;
        cin >> n >> q;

        for(int i = 1; i < n; i++){
        	cout << i << " " << i + 1 << endl;
        }
        int curr_size = n - 1, u = 1, v1 = 2, v2, d;

        while(q--){
        	cin >> d;
        	if(curr_size == d){
        		cout << "-1 -1 -1" << endl;
        		continue;
        	}
        	if(curr_size < d){

        		cout << u << " " << v1 << " ";

        		while(curr_size < d){
        			curr_size++;
        			v1--;
        		}
        		cout << v1 << endl;
        	}else{
        		cout << u << " " << v1 << " ";

        		while(curr_size > d){
        			curr_size--;
        			v1++;
        		}
        		cout << v1 << endl;

        	}
        }
    }
    return 0 ;
}
