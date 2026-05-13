#include<bits/stdc++.h>
using namespace std ;

int main ()
{
    int t ;

    cin>>t ;

    while(t--)
    {
        string a , b ;

        cin>>a>>b ;

        if(a[a.size()-1]==b[b.size()-1])
        {
            if(a[a.size()-1]=='S')
            {
                if(a.size()>b.size())
                    cout<<"<"<<endl ;
                else if(a.size()<b.size())
                    cout<<">"<<endl ;
                else
                    cout<<"="<<endl ;
            }
            else if(a[a.size()-1]=='L'||a[a.size()-1]=='M')
            {
                if(a.size()>b.size())
                    cout<<">"<<endl ;
                else if(a.size()<b.size())
                    cout<<"<"<<endl ;
                else
                    cout<<"="<<endl ;
            }

        }
        else
        {
            if(a[a.size()-1]=='L' &&b[b.size()-1]=='M')
                cout<<">"<<endl ;
           else if(a[a.size()-1]=='L' && b[b.size()-1]=='S')
                cout<<">"<<endl ;
           else if(a[a.size()-1]=='M' && b[b.size()-1]=='L')
                cout<<"<"<<endl ;
           else if(a[a.size()-1]=='S' && b[b.size()-1]=='L')
                cout<<"<"<<endl ;
            else if(a[a.size()-1]=='M' && b[b.size()-1]=='S')
                cout<<">"<<endl ;
            else if(a[a.size()-1]=='S' && b[b.size()-1]=='M')
                cout<<"<"<<endl ;

        }

    }

    return  0 ;
}
