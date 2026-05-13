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

    
        ll N;

        cin >> N;

        int ans = INT_MAX;

        for(ll i = 1; i*i <= N; i++){


        	if( N % i == 0){

	        	int lenX = log10(i) + 1;
	        	int lenY = log10((N / i)) + 1;
	        	ans = min(ans, max(lenX, lenY));
        	}
        }

        cout << ans << endl;
    
    return 0 ;
}
