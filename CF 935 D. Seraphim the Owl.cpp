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
const int N = 200007;
int arr[N][2], m , n , p  ;

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
        cin >> n >> m;

        ll ans = 0 ;

        for(int i = 1; i <= n; i++){
        	cin >> arr[i][0] ;
        }
        for(int i = 1; i <= n; i++){
        	cin >> arr[i][1] ;
        }

        for(int i = n; i > m ; i--){
        	ans += min(arr[i][0], arr[i][1]);
        
        }

        ll a = arr[m][0] , b = 0, bsum = inf, asum = inf ;

        for(int i = m; i >= 1 ; i--){

        	
        	if( i == m)
        		bsum = a;
        	else
        		bsum = min(bsum, b + arr[i][0]);

        	b += arr[i][1];


        }


        cout << ans + bsum << endl;

        



        
    }
    return 0 ;
}
