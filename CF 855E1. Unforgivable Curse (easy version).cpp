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

        string s , t , tms , tmt ;

        cin>>n>>k>>s>>t ;

        tms=s ;
        tmt=t ;

        sort(tms.begin() , tms.end());
        sort(tmt.begin() , tmt.end());

        if(tms!=tmt){
        	cout<<"No"<<endl;
        	continue ;
        }

        if(n<=3){
        	if(s==t)
        		cout<<"Yes"<<endl;
        	else
        		cout<<"No"<<endl;

        	continue;
        }

        if(n<6){
        	if(n==4){
        		if((s[1]==t[1])&&(s[2]==t[2]))
        			cout<<"Yes"<<endl;
        		else
        			cout<<"No"<<endl;

        	}else{
        		if((s[2]==t[2]))
        			cout<<"Yes"<<endl;
        		else
        			cout<<"No"<<endl;
        	}

        	continue ;

        }else
        	cout<<"Yes"<<endl;


    }
    return 0 ;
}
