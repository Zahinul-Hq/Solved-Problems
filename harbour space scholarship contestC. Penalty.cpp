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
        int n = 10 ;

        string s ;

        cin>>s ;

        int ans = 9 ;

        int cnt0=0 , cnt1=0 ;


        for(int i=0 ; i<n ; i++){

        	if(i%2==0)cnt0+=(s[i]!='0');
        	else cnt1+=(s[i]=='1') ;

        	if(cnt0>cnt1 + (10-i)/2)ans=min(ans,i);
        	if(cnt1>cnt0 + (9-i)/2)ans=min(ans,i);
        }

         cnt0=0 , cnt1=0 ;


        for(int i=0 ; i<n ; i++){

        	if(i%2==0)cnt0+=(s[i]=='1');
        	else cnt1+=(s[i]!='0') ;

        	if(cnt0>cnt1 + (10-i)/2)ans=min(ans,i);
        	if(cnt1>cnt0 + (9-i)/2)ans=min(ans,i);
        }

        cout<<ans+1<<endl;
    }
    return 0 ;
}
