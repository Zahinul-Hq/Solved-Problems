#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long double ll ;
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

ll distance(ll x1, ll y1, ll x2, ll y2)
{
	ll X = (x2 - x1), Y = (y2 - y1);
    return (X*X) + (Y*Y);
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
       	int n;
       	cin >> n;

       	ll Xs,Ys, Xd, Yd;

       	vector<ll>x(n), y(n);
       	for(int i = 0; i < n; i++){
       		cin >> x[i] >> y[i];
       	}
       	cin >> Xs >> Ys >> Xd >> Yd;

       	ll dis = distance(Xs, Ys, Xd, Yd);
       	bool ok = 1;

       	for(int i = 0; i < n; i++){

       		ll d = distance(x[i], y[i], Xd, Yd) ;

       		if(dis >= d)
       			ok = 0;
       	}
       	
       	if(ok){
       		cout << "YES" << endl;
       	}else{
       		cout << "NO" << endl;
       	}


    }
    return 0 ;
}
