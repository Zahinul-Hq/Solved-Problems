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

    int t ;
    cin >> t ;
    
    while (t--)
    {
        int n, m, x;

        cin >> n;

        vector<int>a(n),b(n);
        map<int,int>mp, mp2, mp3;

        for(int i = 0; i < n; i++){
        	cin >> a[i];
        }
        for(int i = 0; i < n; i++){
        	cin >> b[i];
        	mp2[b[i]]++;
        }

        cin >> m;

        for(int i = 0; i < m; i++){
        	cin >> x;
        	mp[x]++;
        }

        bool ok = 1;
        bool more = 0;

        for(auto i : mp)
        {
            if(mp2[i.F] <= i.S && mp2[i.F]>0){
                if(more)
                	more = 0;
                continue;
            }
            else if(mp3[i.F] && mp2[i.F] == 0){
                if(more)
                	more = 0;
                continue;
            }
            else if(mp2[i.F] == 0){
                more = 1;
            }
            else ok=false;
        }
        for(int i = 0; i < n; i++){
            if(a[i] != b[i] && mp[b[i]] == 0)
            	ok=false;
        }

        if(ok && more == 0){
        	cout << "YES" << endl;
        }else{
        	cout <<"NO" << endl;
        }


    }
    return 0 ;
}
