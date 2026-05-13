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

        char ch = s[0] , nm=s[1] ;


        for(int i=1 ; i<=8 ; i++){

        	if(s[1]-'0'!=i)
        		cout<<ch<<i<<endl;
        }
        for(char c = 'a' ; c<='h' ; c++){

        	if(s[0]!=c)
        		cout<<c<<nm<<endl;
        }


    }
    return 0 ;
}
