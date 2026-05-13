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
        int n , sum ;

        cin>>n>>sum ;

        vector<int>vec(n+1,0) ;

        for(int i=1 ; i<=n ; i++){
        	cin>>vec[i];
        }

        for(int i=2 ; i<=n ;i++){
        	vec[i]= vec[i-1]+vec[i] ;
        }

        if(vec[n]<sum){
        	cout<<-1<<endl;
        	continue ;
        }


        int flag=0 , ans=INT_MAX;

        for(int i=1 ; i<=n ;i++){

            int hi = n , lo=i , mid=0;

            while(hi>=lo){

                 mid = (hi+lo)/2 ;

                int tsum= vec[mid] - vec[i-1] ;

                if(tsum<= sum){
                    lo = mid+1 ;
                    if(tsum==sum)
                        flag=mid;
                }else 
                    hi=mid-1 ;
            } 

            if(flag){
                ans= min(ans , (n-flag)+i-1) ;
            }

            flag=0 ;

        }

        cout<<ans<<endl;

        
        

        
    }
    return 0 ;
}
