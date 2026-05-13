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
    	int q ;
    	cin>>q ;
    	bool otherA = false, otherB = false;
   			ll cntA = 0, cntB = 0;

        while(q--){

        
			ll k ,d ;

			

			string s ;

			cin>>d>>k>>s ;

			for(auto c: s){

				if(d==1){

					if(c!='a')
						otherA=1 ;
					else
						cntA+=k ;
				}else{
					if(c!='a')
						otherB=1 ;
					else
						cntB+=k ;

				}

			}

			if(otherB) {
	            cout << "YES\n";
	        } else if(!otherA && cntA < cntB) {
	            cout << "YES\n";
	        } else {
	            cout << "NO\n";
	        }        

        }

    }
    return 0 ;
}
