#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
//typedef __int128 lll;
#define pb push_back
#define inf   2e18
#define low   -2e18
#define PI    acos(-1.0)
#define endl  "\n"
#define F first
#define S second

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

int main()
{
	inout();

    int ar[10];
    int sum=0;
    vector<int>o,t;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
     sum+=(s[i]-'0');
     sum%=3;
     if(s[i]%3==1)o.push_back(i);
     if(s[i]%3==2)t.push_back(i);
    }
    if(sum%3==0)
    {
     cout<<s<<endl;
    }
    else if(sum%3==1){
    	auto it=o.back();
	    if(it==0){
	       bool ok=false;
	       for(int i = 1; i < s.size();i++){
		       	if(s[i]!='0')ok=true;
		        if(ok)cout<<s[i];
	       }
	    }
	    else {
	        for(int i=0;i<s.size();i++){
	        	if(i!=it)cout<<s[i];
	        }
	    }
    }
    else{
    	auto it = t.back();
    	int cnt2 = 0, cnt1 = 0;
    	if(it==0){
       	bool ok=false;;
	       	for(int i =1;i<s.size();i++){
	         if(s[i]!='0')ok=true;
	         if(!ok)cnt2++;
	       	}
	    }
	    else {
	     	
	        cnt2 = 1;
	    }
	    auto it1 = o.back(), it2 = o[o.size() - 2];
	    if(it1 == 0 || it2 == 0){
	    	bool ok=false;
	       	for(int i =1;i<s.size();i++){
	         	if(s[i]!='0' && i != it2)ok=true;
	         	if(!ok)cnt1++;
	       	}
	    }else{
	    	cnt1 = 2;
	    }


    }

}
