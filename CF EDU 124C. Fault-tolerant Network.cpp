#include<bits/stdc++.h>
using namespace std ;

typedef long long ll ;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second 

void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

ll add_edge(ll val, vector<ll>arr){

    ll res = inf;

    for(int i = 0; i < arr.size(); i++){
        res = min(res, abs(val - arr[i]));
    }

    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t;
    cin >> t;
    
    while (t--)
    {
        ll n, x, f1 = 0, f2 = 0, l1 = 0, l2 = 0;

        cin >> n;

        vector<ll>a(n), b(n);

        ll ans = inf;

        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        

        ans = min(ans, abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]));
        ans = min(ans, abs(a[0] - b[n-1]) + abs(b[0] - a[n-1]));

        ll ans2 = inf, ans3 = inf;

        ans2 = min(ans, (abs(a[0] - b[n-1]) + add_edge(b[0], a) + add_edge(a[n-1], b)));
        ans2 = min(ans2, (abs(a[n-1] - b[n-1]) + add_edge(b[0], a) + add_edge(a[0], b)));
        ans2 = min(ans2, (abs(a[0] - b[0]) + add_edge(b[n-1], a) + add_edge(a[n-1], b)));
        ans2 = min(ans2, (abs(a[n-1] - b[0]) + add_edge(b[n-1], a) + add_edge(a[0], b)));


        ans = min(ans2 , (add_edge(a[0], b) + add_edge(b[0], a) + add_edge(a[n-1], b) + add_edge(b[n-1], a)));

        cout << ans << endl;

    }
    return 0 ;
}
