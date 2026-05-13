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

        cin>>n ;

        vector<int>a(n,0 );

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        }


        if(a[0]==a[n-1]){

        	int l=0 , r=0 ;

        	for(l=0 ; l<=n-1 ; l++){

        		if(a[0]!=a[l]){
        			break;
        		}
        	}

        	if(l==n){
        		cout<<0<<endl;
        		continue; 
        	}

        	reverse(a.begin() ,a.end()) ;

        	for(r=0 ; r<=n-1 ; r++){

        		if(a[0]!=a[r]){
        			break;
        		}
        	}

        	int ans = n- (l+r);

        	cout<<ans<<endl;

        	continue ;
        }

        int cnt1 =1 , cnt2= 1 ;

        for(int i=0 ; i<n-1 ; i++ ){

        	if(a[i+1]==a[i]){
        		cnt1++ ;
        	}else
        		break;
        }
        reverse(a.begin() , a.end()) ;

        for(int i=0 ; i<n-1 ; i++ ){

        	if(a[i+1]==a[i]){
        		cnt2++ ;
        	}else
        		break;
        }

        int ans  = n-max(cnt1 , cnt2) ;

        cout<<ans<<endl;
    }
    return 0 ;
}
