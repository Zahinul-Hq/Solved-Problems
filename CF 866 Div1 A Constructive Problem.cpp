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

        vector<int>v1(n,0);
        set<int>st;



        for(int i =0 ; i<n ; i++){
        	cin>>v1[i] ;
        	st.insert(v1[i]);
        }

       	int mex=0 , lmax, hmax;
       	bool flag=0 , ok=0;


       	for(auto x : st){

       		if(x==mex && !flag){
       			mex++ ;
       		}
       		else{

       			flag=1;
       			hmax=x ;
       			lmax=mex-1;
       			break ;
       		}
       	}

       	if(v1.size()==1){
       		cout<<"No"<<endl;
       		continue ;
       	}


       	if((!flag or mex==0)){
       		cout<<"Yes"<<endl;
       		continue ;
       	}


       	int left1=n+200,left2=n+200 , right1, right2 ;
       for(int i=0 ; i<n ; i++){

       		if(lmax==v1[i]){
       			left1=min(left1, i);
       			right1=i ;
       		}

       		if(hmax==v1[i]){

       			left2=min(left2 ,i);
       			right2= i ;
       		}
       }	


       	if((left1<left2) or(right2<right1))
       		cout<<"Yes"<<endl;
       	else
       		cout<<"No"<<endl;

       		






       		

        


    }
    return 0 ;
}
