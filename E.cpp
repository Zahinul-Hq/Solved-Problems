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

    int t , i=1 ;
    cin>>t ;
    
    while (t--)
    {
        string s ;

	    cin>>s  ;

	    int zero=0  , one= 0 , flag=1;

	    for(int i = s.size()-1 ; i>=0  ;i--){

	    	if(s[i]=='0'){
	    		zero++ ;
	    	}

	    	if(s[i]=='1'){

	    		zero=zero-2 ;

	    		if(zero<0){

	    			flag= 0;
	    			break ;
	    		}
	    	}
	    }


	    if(flag && zero==0)
	    	cout<<"Case "<<i++<<": yes"<<endl;
	    else
	    	cout<<"Case "<<i++<<": no"<<endl;



    }
    return 0 ;
}
