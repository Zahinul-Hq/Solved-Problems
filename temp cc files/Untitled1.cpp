#include<bits/stdc++.h>
using namespace std ;
int main()
{
      int t  , l;
        int n,c1=0,c2=0,j,i,count=0, m;
      cin>>t ;
      for(l=1;l<=t;l++)
      {
            cin>>n ;
            int ground[n] ;
            int water[n] ;
            int total[n];
            for(i=0;i<n;i++)
                cin>>ground[i] ;

            for(i=0;i<n;i++)
                cin>>water[i] ;

            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                        if(i==j && j<n-1)
                                j++ ;

                       if(ground[i] >ground[j])
                                c1++;
                      else if(water[i] > water[j])
                                c2++ ;
                }

                total[i]=c1+c2;
                c1=c2= 0 ;
            }
            m=*max_element(total , total + n) ;
            for(i=0;i<n;i++)
            {
                if(total[i]==m)
                        count++ ;
            }
                cout<<count<<endl ;
                count = 0 ;
        }

        return 0 ;
}

