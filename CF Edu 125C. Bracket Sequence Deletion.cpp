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
        int n  , ans=0 , flag, i=0 , k;

        string s ;

        cin>>n>>s ;

        for(  i=0 ; i+1<n ; ){

            if(s[i]=='('){

                if(i+1<n)
                    ans++ ;
                
                i+=2 ;
                continue ;
            }

            k=i+1 ;

            while(s[i]!=s[k] && k<n)
                k++ ;

            if(k==n)
                break ;

            ans++ ;

            i=k+1 ;
        }

        cout<<ans<<" "<<n-i<<endl;


    }
    return 0 ;
}
