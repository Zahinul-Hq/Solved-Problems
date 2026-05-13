#include<iostream>
#include<cstring>
using namespace std ;

int main ()
{
        int i , j=0 , k , l , n ,t , lenn ;

        int a, b, c ;

        cin>>t ;

        for(i=1;i<=t;i++)
        {

                cin>>n ;
                char s[n] ;
                char ot[n] ;
                j=0 ;

                cin>>s ;

                for(l=n-1; l>=0; l--)
                {

                        if(s[l]!=48)
                        {
                                ot[j]= (s[l]-48) + 96 ;
                                j++ ;
                        }

                        else if(s[l]==48)
                        {
                                ot[j] = (s[l-1]-48) +(10* (s[l-2]-48)) +96 ;
                                l=l-2 ;
                                j++ ;
                        }
                }
               for(k=j-1;k>=0; k--)
               {
                       cout<<ot[k];
               }

               cout<<endl ;
        }

        return 0 ;
}
