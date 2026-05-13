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
        ll n ;

        cin >> n;

        ll case1 = 0, case2 = 0;

        ll last_case = (1LL << 31) - 1;

        for(int i = 0; i < n - 2; i++){

        	case1 ^= i;
        	case2 ^= (i + 1);
        }

        if(case1 != 0){

        	for(int i = 0; i < n - 2; i++)
        		cout << i << " ";

        	case1 ^= last_case;


        	cout << last_case << " " << case1 << endl;

        }else{

        	for(int i = 1; i <= n - 2; i++)
        		cout << i << " ";

        	case2 ^= last_case;


        	cout << last_case << " " << case2 << endl;

        }
    }
    return 0 ;
}
