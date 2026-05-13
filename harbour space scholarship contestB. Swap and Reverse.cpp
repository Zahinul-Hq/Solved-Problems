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
        int n , k ;

        cin>>n>>k ;

        string s ,ans ;

        cin>>s;
        ans=s ;

        sort(ans.begin() , ans.end()) ;

        if(k%2==0){
        	cout<<ans<<endl;
        	continue ;
        }

        string odd="" ,ev="" ;

        for(int i=0 ; i<n ; i++){

        	if(i%2==0)
        		odd+=s[i] ;
        	else
        		ev+=s[i] ;
        }

        sort(odd.rbegin() ,odd.rend());
        sort(ev.rbegin() , ev.rend()) ;


        for(int i=0 ; i<n; i++){
        	if(i%2==0){
        		ans[i]=odd.back();
        		odd.pop_back() ;
        	}else{

        		ans[i]=ev.back();
        		ev.pop_back() ;

        	}

        }


        cout<<ans<<endl;





    }
    return 0 ;
}
