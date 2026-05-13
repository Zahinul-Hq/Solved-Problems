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
        int n ,k , m ;

        cin>>n>>m>>k;

        vector<int>a(n,0) ,b(m,0) ;

        map<int,int>mp1 , mp2 ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;

        	mp1[a[i]]++ ;
        }
        for(int i=0 ; i<m ; i++){
        	cin>>b[i] ;

        	mp2[b[i]]++;
        }

        int flag=0  ,ca=0 , cb=0 , ab=0;

        for(int i=1 ; i<=k ; i++){
        	

        	if(mp1[i]>0 && mp2[i]>0){
        		cb++ ;
        		ca++ ;
        	}
        	else if(mp1[i]>0){
        		ca++ ;
        	}else if(mp2[i]>0){
        		cb++ ;
        	}else{
        		flag=1 ;
        	}


        }

       // cout<<ca<<" "<<cb<<endl;

        if(flag){
        	cout<<"No"<<endl;
        	continue;
        }

        if(ca>=(k/2) && cb>=(k/2)){
        	cout<<"Yes"<<endl;
        	continue;
        }

        cout<<"No"<<endl;





    }
    return 0 ;
}
