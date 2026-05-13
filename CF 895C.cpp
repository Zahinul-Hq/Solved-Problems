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
        int l ,r ;

        cin>>l>>r ;

        if(l>=1 && r<=3){

        	cout<<-1<<endl;

        	continue ;
        }

        

        int lef= l , rig=r, flag=0  ,ans ;

        if(l==r){

        	if(l%2==0){
        		cout<<l/2<<" "<<l/2<<endl;
        		continue ;
        	}else{

        		for(int i=3 ; i*i<=l ; i+=2){

        			if(l%i==0){
        				flag=1 ;
        				ans=i ;
        				break;
        			}
        		}
        	}


        	if(!flag){
	        	cout<<-1<<endl;
	        	continue ;
	        }else{

	        	cout<<l-ans<<" "<<ans<<endl;
	        	continue;
	        }
        }else{
        	
        	if(r%2==0)
        		cout<<r/2<<" "<<r/2<<endl;
        	else
        		cout<<(r-1)/2<<" "<<(r-1)/2<<endl;
        }



        

    }
    return 0 ;
}
