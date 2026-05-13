#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll ;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	inout() ;

    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
        int n;
        string s;
        cin >> n >> s;

        int seg_0 = 0, cnt1 = 0;

        for(int i = 0; i < n - 1; i++){
        	if(s[i] == '0' && s[i + 1] == '1' ){
        		seg_0++;
        	}
        	if(s[i] == '1')
        		cnt1++;
        }
        if(s[n - 1] == '0'){
        		seg_0++;
        }
        if(s[n - 1] == '1')
        		cnt1++;

        if(seg_0 >= cnt1){
        	cout <<"No" << endl;
        }else{
        	cout << "Yes" << endl;
        }

        
    }
    return 0 ;
}
