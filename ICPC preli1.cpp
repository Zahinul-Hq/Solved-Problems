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
        string s ;

        cin>>s ;

        int over= s.size()/6 ;

        int overmd = s.size()%6 ;

        int run = 0 ;

        int wkt = 0 ;

        for(int i=0 ;  i<s.size() ; i++){

        	if(s[i]=='W')
        		wkt++ ;
        	else{
        		run+=(s[i]-'0') ;
        	}
        }

        string ovr="Over" , rn="Run" , wick="Wicket" ;


        if((over>1) || (over>=1 && overmd>0))
        	ovr+='s' ;

        if(run>1)
        	rn+='s';

        if(wkt>1)
        	wick+='s';


        cout<<over<<"."<<overmd<<" "<<ovr<<" "<<run<<" "<<rn<<" "<<wkt<<" "<<wick<<"."<<endl;


    }
    return 0 ;
}
