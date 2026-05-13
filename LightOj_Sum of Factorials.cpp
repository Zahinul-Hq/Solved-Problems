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
vector<ll>fact(20,1) ;
void factorials(){

	for(int i = 1; i <= 20; i++){
		fact[i] = fact[i-1] * i ;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

	factorials();

    int t , c = 1 ;
    cin >> t ;

    while (t--)
    {

    	ll n; 

    	cin >> n ;
    	vector<ll>ans;

    	for(int i = 20; i >= 0; i--){

    		if(fact[i] <= n){
    			ans.push_back(i);
    			n = n - fact[i];
    		}
    	}

        cout << "Case "<< c++ << ": " ;

        if(n == 0){

        	for(int i = ans.size() - 1; i >= 0 ; i--){

        		cout << ans[i] << "!" ;
        		if(i != 0){
        			cout << "+" ;
        		}
        	}
        }else {

        	cout << "impossible";
        }

        cout << endl;
    }
    return 0 ;
}
