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
const int N = 101 ;




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
        vector<ll>a(n,0) , arr(n,0);

        for(int i=0 ; i<n ; i++){
        	cin>>a[i];
        }


        ll lo = 1 , hi = 1e18 , mid=2 ;


        while(true){

        	set<ll>s;

        	for(int i=0 ; i<n ; i++){
        		arr[i]=a[i] ;
        	}

			for(int i=0 ; i<n ; i++){
				arr[i]=arr[i]%mid ;
				s.insert(arr[i]);
			}

        	if(s.size()>=2){
        		break ;
        	}else{
        		mid=mid*2 ;
        	}
        }

        cout<<mid<<endl;

    }
    return 0 ;
}
