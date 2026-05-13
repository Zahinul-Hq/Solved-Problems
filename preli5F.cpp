#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll x;
    cin>>x;
        ll n;
        cin>>n;
        vector<ll>deya;
        vector<string>pp;
        for(int i=0;i<n;i++){
            string s;
            ll j;
            cin>>s>>j;
            pp.push_back(s);
            deya.push_back(j);
        }
        string ans;
        vector<vector<ll>>arr;
        ll flag=-1;
        ll total=0;
        vector<string>arr1={"Monday","Tuesday","Wednesday","Thursday","Friday"};
        for(int i=0;i<5;i++){
            for(int j=0;j<n;j++){
                int c;
                cin>>c;
                
                total+=c*deya[j];
                if(total>=x && flag==-1){
                    flag=i;
                    ans=pp[j];
                }
            }
            if(flag!=-1)
                break;
            
        }
        if(flag==-1){
            cout<<"Diet control na korleo cholbe."<<endl;
            cout<<total<<endl;
        }else{
            cout<<arr1[flag]<<endl;
            cout<<total<<endl;
            cout<<"Ar khabo na "<<ans<<endl;
        }
    return 0;
}