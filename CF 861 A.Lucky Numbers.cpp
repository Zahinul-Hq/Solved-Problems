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
int get(int x){
	int mn = 10, mx = 0;
	while(x){
	    mn = min(mn, x % 10);
	    mx = max(mx, x % 10);
	    x /= 10;
	}
	return mx - mn;
}
 
void solve(){
	int l, r;
	cin >> l >> r;
	int mx = 0, ans = l;
	for(int i = l; i <= r; i++){
		int cur = get(i);
		if(cur > mx){
			mx = cur;
			ans = i;
		}
		if(mx == 9) break;
	}
	cout << ans << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;
    
    while (t--)
    {
        solve() ;
    }
    return 0 ;
}
