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

const int N = 2e5+5 ;
int n , k ;
vector<int>a(N,0), h(N,0) , length(N,0), perf(N,0);

bool f(int dis){

	bool found=0 ;

	for(int i=0 ; i<n-dis+1 ; i++){

		if(length[i]<dis)
			continue ;

		int sum = perf[i+dis]-perf[i] ;

		if(sum<=k){
			return true ;
		}
	}
	return false ;
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
        

        cin>>n>>k ;

     
        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;

        	perf[i+1]=perf[i]+a[i] ;
        }

        for(int i=0 ; i<n ; i++){
        	cin>>h[i] ;
        }

        length[n-1]=1 ;

        for(int i=n-2 ; i>=0 ; i--){

        	if(h[i]%h[i+1]==0){
        		length[i]=length[i+1]+1;
        	}else
        		length[i]=1 ;
        }

        int seg=1 , ans=0 ;

        int hi= N, lo=1; 

        while(hi>=lo){

        	int mid =(hi+lo)/2 ;

        	if(f(mid))
        		lo= mid+1;
        	else 
        		hi = mid-1 ;
        }

        



        


        cout<<hi<<endl;


    }
    return 0 ;
}
