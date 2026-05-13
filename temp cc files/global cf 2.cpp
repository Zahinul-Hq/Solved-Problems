#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        int n;

        cin>>n ;

        int a[n] ;

        int flag =0 , z=0 , one=0 ;

        for(int i=0 ; i<n;i++)
        {
            cin>>a[i] ;


           if(a[i]==0)
                z++ ;
            else
                one++ ;
        }

        int i=0 , j=n ,c=0 ;

        while(j--)
        {
            if(a[j]== 0)
            {
                for(;i<n;i++)
                {
                    if(i>j)
                        break ;

                    if(a[i]==1 )
                    {
                        swap(a[i] ,a[j]) ;
                        c++ ;
                        break ;
                    }
                }
            }

            if(i>j)
                break ;
        }

        cout<<c<<endl ;

    }

    return 0 ;
}
