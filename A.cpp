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
	#endif
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

    int t ;

    cin>>t  ;

    while(t--)
    {
    	
    	string s ;
    	string  s1 = "asemblr" ;
    	string  s2 = "operand" ;

    	int n ;

    	cin>>n>>s ;


    	

    	int c=0 , d=0 ,i ,j  ;

    	for( i=0 ; i<7 ;i++)
    	{
    		for( j=0 ; j<n ;j++)
    		{

    			cout<<c<<endl;


    			if(s[j]==s1[i])
    			{
    				
    			}
    			if(s2[i]==s[j])
    			{
    				d++ ;
    				break ;
    			}

    		}
    	}

    	cout<<c<<d ;

    	if(c==7 || d==7)
    		cout<<"Yes"<<endl ;
    	else
    		cout<<"No"<<endl ;
    }
    return 0 ;
}
