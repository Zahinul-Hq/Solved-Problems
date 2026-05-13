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
int div_by_3(int n){

	int sub = 0 ;
	if(n % 3 == 0){
		sub = n / 3 ;
	}else{

		sub = (n / 3) + 1 ;
	}

	return n - sub; 
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t , c = 1 ;
    cin>>t ;
    
    while (t--)
    {
        ll a, b, ans;

        cin >> a >> b; 

        
        ans  = div_by_3(b) - div_by_3(a-1);

        cout << "Case " << c++ << ": " << ans << endl;
    }
    return 0 ;
}
