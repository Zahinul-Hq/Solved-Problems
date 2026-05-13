#include<bits/stdc++.h>
using namespace std ;


int factorial ( int n  )
{
    long factorial = 1.0;

        for(int i = 1; i <= n; ++i) {
            factorial *= i ;
        }

    return factorial;
}


int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int n ;

        cin>>n ;

        int a[n] ;

        for(int i=0 ; i<n ;i++)
        {
            cin>>a[i] ;
        }


        int per = factorial(10-n)/factorial((10-n)-2) ;

        if((10-n)>2)
        {
            int res= per*3 ;

            cout<<res<<endl ;
        }
        else
            cout<<"6"<<endl ;

    }

    return 0 ;
}
