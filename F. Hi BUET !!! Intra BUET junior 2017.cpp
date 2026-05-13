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
const ll N = 1e14+7 ;
vector<ll>pref ;
void precalculate(){

	for(ll i = 2; i*i <= N ; i+=2 ){
		pref.push_back(i*i);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	precalculate() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        ll r, l;

        cin >> l >> r;


        int ans = upper_bound(pref.begin(), pref.end(), (r)) - lower_bound(pref.begin(), pref.end(), (l)) ;


        cout << ans << endl;
    }
    return 0 ;
}
