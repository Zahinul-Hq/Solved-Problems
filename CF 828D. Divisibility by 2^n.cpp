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

int div(int num){

	int ans=0 ;

	while(num%2==0){

		num=num/2 ;

		ans++ ;

	}

	return ans ;
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
        int n ,x , cnt=0 , op=0,pw=0 ;

        cin>>n ;

        vector<int>a ;

        for(int i=1 ; i<=n ;i++){
        	cin>>x ;

        	if(x%2==0)
        		cnt+=div(x);
        }


        for(int i=2 ; i<=n ;i+=2){

        	a.pb(div(i)) ;        	
        }

        sort(a.begin() , a.end() , greater<int>()) ;


        for(int i : a){

        	if(cnt<n){
        		op++ ;

        		cnt+= i ;
        	}
        }




        if(cnt>=n){
        	cout<<op<<endl;
        }else{
        	cout<<-1<<endl; 
        }


    }
    return 0 ;
}
