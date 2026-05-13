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
        double n;
	    cin >> n;
	    double ans = 0.00;
	    for(int i=1;i<=n-1;i++){
	        double x;
	        cin >> x ;
	         ans += x;
	    }
	    n-- ;
	    double tot_need = 3.50*8.00;
	    double need = 1.00*(tot_need - ans);
	    double cg = (need/(1.000*(8.00-n)));


	    if(cg<=3.7000) {
	        cout<<"YES"<<'\n';
	        cout<<fixed<<setprecision(2)<<cg<<'\n';
	    }
	    else {
	        cout<<"NO"<<'\n';
	    }

    }
    return 0 ;
}
