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

    int t ,c=1;
    cin>>t ;
    
    while (t--)
    {
        ll n ;

        cin>>n ;

        vector<int>bin ;
        while(n>0){

        	bin.pb(n%2);
        	n=n/2 ;
        }
        bin.pb(0) ;


        int indx=-1 ;


        for(int i=0; i<bin.size() ; i++){

        	if(bin[i]==1)
        		indx=i ;

        	if(indx!=-1 && bin[i]==0){
        		swap(bin[i], bin[indx]);
        		break;
        	}
        }

        int j =0 ;



        indx-- ;



        while(indx>j){

            if(bin[indx]!=1)
                --indx;

            if(bin[j]!=0)
                j++ ;

            if(bin[indx]==1 && bin[j]==0){
                swap(bin[j], bin[indx]);
                --indx ;
                j++ ;
            }

        }

        ll sum=0 ;

        for(int i=0 ; i<bin.size() ; i++){
        	if(bin[i])
        		sum+=(1<<i);
        }

        cout<<"Case "<<c++<<": "<<sum<<endl;
    }
    return 0 ;
}
