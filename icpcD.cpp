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
    #endif
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    inout() ;

    int t ,i=0 ;
    cin>>t ;

    while (t--)
    {
        ll a , b , c , k ,sum  ;


        cin>>a>>b>>c>>k ;



        ll x1 , x2 , x3 , y1,y2 ,y3 ,sum1=0 , sum2=0;


        x1= a- (a%k) ;

        x1 = x1/k ;

        x2= b- (b%k) ;

        x2 = x2/k ;

        x3= c- (c%k) ;

        x3 = x3/k ;




                y1= a- (a%(k)) ;

                y1 = y1/(2*k) ;

                y2= b- (b%(k)) ;

                y2 = y2/(2*k) ;

                y3= c- (c%(k)) ;

                y3 = y3/(2*k) ;



                if( (x1+x2+x3)%3==0)
                    cout<<"Case "<<++i<<": "<<"Peaceful"<<endl ;
                else if((y1+y2+y3)%3==0 && (y1+y2+y3)%2==0)
                    cout<<"Case "<<++i<<": "<<"Peaceful"<<endl ;

                else
                    cout<<"Case "<<++i<<": "<<"Fight"<<endl ;




    }




    return 0 ;
}
