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

        vector<ll> a(n), b(n + 1);

        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        for(int i = 0; i < n + 1; i++){
        	cin >> b[i];
        }

        ll op = 0, mx = 0, mn = inf;

        bool betw = 0;

        for(int i = 0; i < n; i++){

        	if( !betw && min(a[i], b[i]) <= b[n ] && b[n ] <= max(a[i], b[i])){
        		betw = 1;
        		op += 1;
        	}
        	op += (abs(a[i] - b[i]));
        	mx = max({mx, a[i], b[i]});
        	mn = min({mn, a[i], b[i]});
        }

        if(betw){
        	cout << op << endl;
        	continue;
        }

        

        op += min((abs(mn - b[n ])),(abs(mx - b[n])))  ;
        op++;

        cout << op << endl;


    }
    return 0 ;
}
