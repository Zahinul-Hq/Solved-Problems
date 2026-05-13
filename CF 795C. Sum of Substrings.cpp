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
        int n , k ;

        string s ;

        cin>>n>>k>>s;

        int dis=0;

        int cnt = count(s.begin() ,s.end(), '1') ;

        if(cnt==0){
        	cout<<0<<endl;
        	continue;
        }
        bool flag1 = 0 , f2=0;


        for(int i=n-1 ; i>=0 ; i--){

        	if(s[i]=='0')
        		dis++;
        	else{

        		if(dis<=k){
        			swap(s[i],s[n-1]);
        		}else{
        			dis=0;
        		}
        		break ;
        	}

        }

        k-=dis ;
        dis=0 ;
        

        for(int i=0 ; i<s.size()-1 ; i++){

        	if(s[i]=='0')
        		dis++;
        	else{

        		if(dis<=k)
        			swap(s[i],s[0]);

        		break ;
        	}
        }

        
        ll sum=cnt*11;

        if(s[0]=='1'&& s[n-1]=='1'){
        	sum-=11 ;
        }else if(s[n-1]=='1'){
        	sum-=10 ;
        }else if(s[0]=='1'){
        	sum-=1;;
        }

        

        cout<<sum<<endl;


    }
    return 0 ;
}
