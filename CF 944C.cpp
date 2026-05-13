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
        int a , b, c , d;

        cin >> a >> b >> c >> d;

        if(min(a, b) < min(c, d) && min(c, d) < max(a ,b) && (max(a,b) < max(c,d) )){
        	cout << "YES" << endl;
        	continue;
        }
        if(min(c, d) < min(a, b) && min(a, b) < max(c ,d) && (max(c,d) < max(a,b) )){
        	cout << "YES" << endl;
        	continue;
        }

        cout << "NO" << endl;
    }
    return 0 ;
}
