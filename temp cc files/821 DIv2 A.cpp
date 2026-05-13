#include<bits/stdc++.h>
using namespace std;

int main ()
{
        int b ,i , j ,  k , t , n  ;

        cin>>t ;

        while(t--)
        {
                cin>>n>>k ;

               long long int a[n] ;

                for(i=0 ;i<n ; i++)
                        cin>>a[i] ;

              long long  int sum = 0 ;
              long long int c= 0 ;

                for(int l=1; l<=k ; l++ )
                {
                        int x=l ;
                        for(j=l; j<=n;j=j+k)
                        {

                             if(a[x-1]<a[j-1])
                                {
                                        c=a[j-1] ;
                                        x=j;
                                }
                                else
                                        c=a[x-1];
                        }
                        sum = sum +c ;
                }
                cout<<sum<<endl ;
        }

        return 0 ;
}
