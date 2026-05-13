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
        int n;

        string s ;

        cin>>n>>s ;

        string ans="" ;

        for(int i=0 ; i<=n ; i++)
        	ans+="0" ;

        int npr=0 , pr=0 ; 

        for(int i=0 ; i<n/2 ; i++){

        	if(s[i]==s[n-1-i])
        		pr++;
        	else
        		npr++ ;
        }

        if(n%2==0){

        	if(npr==0){

        		for(int i=0 ; i<=n ; i+=2)
        			ans[i]='1';
        	}else{

        		cout<<pr<<"rrr"<<npr<<endl;

        		pr++ ;

        		for(int i=npr; pr-- ; i+=2)
        			ans[i]='1';




        	}

        	cout<<ans<<endl;

        	continue;
        }

        if(npr==0){

        	for(int i=0 ; i<=n ; i+=1)
        		ans[i]='1';
        }else{


        	pr=pr*2 ;

        	pr+=2;


        	for(int i=npr; pr-- ; i+=1)
        		ans[i]='1';
        }

        cout<<ans<<endl;
        



    }
    return 0 ;
}
