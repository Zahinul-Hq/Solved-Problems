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
vector<int>v ;
int getpos(int x){

	int hi= v.size()-1  , lo = 0  ;

	while(hi>=lo){

		int mid = (hi+lo)/2 ;

		if(v[mid]==x){
			return mid ;
		}else if(v[mid]<x){
			lo = mid+1;
		}else{
			hi= mid-1;
		}
	}

	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL) ;
	inout() ;

   
        int n , m ,x;

        cin>>n ;

        vector<int>arr[n];

        for(int i=0 ; i<n ; i++){
        	cin>>m ;
        	for(int j=0 ; j<m ; j++){
        		cin>>x ;
        		arr[i].pb(x) ;
        		v.pb(x) ;
        	}
        }
        sort(v.begin() , v.end()) ;

        int split =0 ;

        for(int i=0 ; i<n ; i++){
        	if(arr[i].size()==1)
        		continue ;

        	for(int j=0 ;  j<arr[i].size() ;){

        		int indx= getpos(arr[i][j]) ;

        		while(v[indx]==arr[i][j] && indx<v.size() && j<arr[i].size()){
        			indx++ ;
        			j++ ;

        		}

        		if(j==arr[i].size())
        			break ;
        		split++ ;
        	}

        }

        cout<<split<<" "<<(n+split-1)<<endl;


    
    return 0 ;
}
