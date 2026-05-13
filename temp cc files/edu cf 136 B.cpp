#include<bits/stdc++.h>
using namespace std ;

int main()
{
    int  i, j , k , n ,s , t ;



    cin>>t ;

    while (t--)
    {
        cin>>n ;
        int a[n] ;
        int d[n] ;
        int flag= 0 ;

        for(i=0;i<n;i++)
            cin>>d[i] ;
            a[0]=d[0] ;

            int p=0 ,q=0 ;

        for(i=1;i<n;i++)
        {
            p=a[i-1]+d[i] ;
            q=a[i-1]-d[i] ;

            if(p>=0 && q>=0 &&p!=q)
            {
                flag++ ;
                break ;
            }

            else
                a[i]=p ;

        }

        if(flag)
            cout<<"-1"<<endl ;
        else
        {
            for(j=0;j<n;j++)
                cout<<a[j]<<" ";

            cout<<endl ;
        }



    }

    return 0 ;
}

