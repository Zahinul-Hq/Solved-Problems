#include<bits/stdc++.h>
using namespace std ;

int main ()
{
        int  c ,d, i , j ,l, k, t ,n  ;

       cin>>t ;

       for(i=0 ; i<t ; i++)
       {
               cin>>n ;

                      string str[n] , temp ;
                int a[n] , b[n] ;

                for(l=0 ; l<n;l++)
                cin>>str[l]>>a[l]>>b[l] ;

                for(l=0;l<n;l++)
                {
                        for(j=l+1;l<n;l++)
                        {
                                if(str[l]>str[j])
                                {
                                       temp = str[j] ;
                                       str[j] =str[j+1] ;
                                       str[j+1] =temp ;
                                }

                        }


                }

                for(l=0;l<n;l++)
                        cout<<str[l]<<endl ;


       }



}
