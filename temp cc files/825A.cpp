#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int n , x ,y ,p =0 , q=0;

        cin>> n ;

        int a[n] ;
        int b[n] ;


        for(int i=0 ; i<n ;i++)
        {
            cin>>a[i] ;
            if(a[i]==1)
                p++ ;
        }
        for(int i=0 ; i<n ;i++)
        {
           cin>>b[i] ;
            if(b[i]==1)
                q++ ;
        }

        int res ;

         res = abs(p-q);

        int flag=0 ,d=0 ,l;


        if(p==q)
        {

            for( l=0 ;l<n ;l++)
            {
                if(a[l]!=b[l])
                    flag=1 ;
            }

            if(flag)
                cout<<"1"<<endl ;
            else
                cout<<"0"<<endl ;
        }
        else
        {
            int c=0 ;
            for( l=0 ;l<n ;l++)
            {
                if(a[l]!=b[l])
                    c++ ;
            }

            if(c==res)
            {
                cout<<res<<endl ;
            }
            else
                cout<<res+1<<endl ;
        }

    }

    return 0 ;
}
