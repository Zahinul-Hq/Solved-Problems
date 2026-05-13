#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int x, n;
    	cin >> x >> n;

        ll ans = 1;

        for(ll i = 1; i * i <= x; i++){

            if(x % i == 0 && (x / i) >= n){
                ans = max(ans, i);
            }

            if( x % i == 0 && i >= n){
                ans = max(x / i , ans);
            }
            
        }
    	cout << ans << endl;
    }
    return 0 ;

}
