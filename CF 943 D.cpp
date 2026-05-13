#include<bits/stdc++.h>
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
        ll n, k, by, sh, mx = 0, ind = -1;

        cin >> n >> k >> by >> sh;

        vector<ll>per(n + 1 , 0);
        vector<ll>sc(n + 1,0);

        for(int i = 1; i <= n; i++){
        	cin >> per[i];
        }
        for(int i = 1; i <= n; i++){
        	cin >> sc[i];
        	mx = max(mx, sc[i]);
        }

        ll by_ans = 0, sh_ans = 0, st = 0, pos = by, val =0, kk = k, mx_val =0, d = 0;

        map<int,int>mp1,mp2;

        while(kk && sc[pos] != mx){

        	val += sc[pos];
        	pos = per[pos];

        	kk--;
        	
        	d = val + (kk * sc[pos]);

        	mx_val = max(d, mx_val);

        	mp1[pos]++;

        	//cout << val << " " << pos << endl;

        	if(mp1[pos] >= 2)
        		break;
        }

        ll c = k * sc[by] ;

        by_ans = max(c, mx_val);

        sh_ans = 0, st = 0, pos = sh, val =0, kk = k, mx_val = 0, d =0;

        while(kk > 0 && sc[pos] != mx){

        	val += sc[pos];

        	mp2[pos]++;
        	pos = per[pos];

        	kk--;

        	d = val + (kk * sc[pos]);

        	mx_val = max(d, mx_val);
        	
        	if(mp2[pos]  > 1)
        		break;
        	
        	
        }

         c = k * sc[sh] ;

        sh_ans = max(c, mx_val);

        if(sh_ans == by_ans){
        	cout << "Draw" << endl;
        }else if(sh_ans > by_ans){
        	cout << "Sasha" << endl;
        }else{
        	cout << "Bodya" << endl;
        }

       // cout << sh_ans << " " << by_ans << endl;
    }
    return 0 ;
}
