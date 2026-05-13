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
        int n ,cnt=0 , g=0,f=0;

        cin>>n;

        vector<int>a(n,0);

        map<int,int>mp ;

        for(int i=0 ; i<n ; i++){
        	cin>>a[i] ;
        	mp[a[i]]++ ;
        }

        int n1=0 ,n2=0 ,n3=0;

        for(auto i : mp){

        	if(i.S>=2){
        		cnt++ ;
        	}

        	if(i.S==2 && n1==0){
        		n1=i.F ;
        	}
        	if(i.S==2 && n2==0){
        		n2=i.F ;
        	}

        	if(i.S>2 && i.S<4){
        		g++ ;
        		n3=i.F ;
        	}

        	if(i.S>3)
        		f++ ;
        }

        if((cnt<2 && g==0)|| f){
        	cout<<-1<<endl;
        	continue ;
        }

        cnt=2 ;

        if(g){

        	for(int i=0 ; i<n ; i++){

        		if(a[i]==n3)
        			cout<<max(mp[a[i]]--,1)<<" ";
        		else
        			cout<<1<<" ";
        	}
        }else{

        	int flag=0;

        	for(int i=0 ; i<n ; i++){

        		if(a[i]==n2){

        			cout<<mp[a[i]]<<" ";

        			mp[a[i]]=1 ;
        		}
        		else if(a[i]==n1){

        			if(!flag){
        				cout<<3<<" ";
        				flag=1 ;
        			}else
        				cout<<1<<" ";


        		}else 
        			cout<<1<<" " ;


        	}
        }

        cout<<endl;
    }
    return 0 ;
}
