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
        int n ;

        string s ;

        cin>>n>>s;

        bool flag=1;

        int ans=INT_MAX ;


       	for(char ch = 'a' ; ch<='z' ; ch++){

	        int l =0 , r=n-1 ,cnt = 0 ;

	        while(l<=r){

	        	if(s[l]==s[r]){
	        		l++ ,r-- ;
	        	}else if(s[l]==ch){
	        		l++ ,cnt++ ;
	        	}else if(s[r]==ch){
	        		r--, cnt++ ;
	        	}else{
	        		cnt=n+1 ;
	        		break;
	        	}
	        	
	        }

	        ans=min(ans,cnt) ;
       	}

       	if(ans== n+1)
       		cout<<-1<<endl;
       	else
       		cout<<ans<<endl;


    }
    return 0 ;
}
