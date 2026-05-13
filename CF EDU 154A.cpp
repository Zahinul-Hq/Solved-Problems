#include<bits/stdc++.h>
#include <string>
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
const int n = 105 ;
vector<bool> is_prime(n+1, true);
vector<int>prim ;
void prime(){

	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (is_prime[i] && (long long)i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            is_prime[j] = false;
	        prim.pb(i) ;
	    }
	}
}
int solve( string myString) {
   int x;
   stringstream ss( myString );
   ss >> x;
   return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;
    cin>>t ;

    prime() ;
    
    while (t--)
    {
        ll s ,ans;

        int aa;
        cin>>s ;

        vector<int>vec ;


        for(int i=0 ; i<9 ; i++ ){



        	vec.pb(s%10) ;

        	s=s/10 ;
        }
        reverse(vec.begin() , vec.end()) ;


        for(int i=0 ; i<9 ; i++){
        	for(int j=i+1 ; j<9 ; j++){

        		ans = vec[i]*10 + vec[j] ;

        		

        		//cout<<ans<<endl;

        		//aa = solve(ans);
        		//cout<<aa<<endl;

        		if(is_prime[ans]){
        			cout<<ans<<endl;
        			break;
        		}

        	}

        	if(is_prime[ans])
        		break;
        }

        //cout<<11<<endl;

    }
    return 0 ;
}
