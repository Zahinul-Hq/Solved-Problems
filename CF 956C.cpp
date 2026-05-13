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
        cin >> n;
        ll tot = 0;
        ll arr[3][n + 1];
        ll pref[3][n + 1];
        pref[0][0] = pref[1][0] = pref[2][0] = 0;
        for(int i = 0; i < 3; i++){
        	for(int j = 1; j <= n; j++){
        		cin >> arr[i][j];
        		if(i == 0)
        			tot += arr[i][j];
        	}
        }

        tot = (tot / 3) + ((tot % 3) > 0);
        cout << tot << endl;
        for(int i = 0; i < 3; i++){
        	for(int j = 1; j <= n; j++){
        		pref[i][j] = pref[i][j - 1] + arr[i][j];
        	}

        }
        int L[3], R[3];
        bool f = 0;

        

        for(int x = 0; x < 3; x++){
        	for(int i = 1; i <= n; i++){
        		ll srch = tot + pref[x][i - 1];
        		int pos = lower_bound(pref[x], pref[x] + n  , srch) - pref[x];
        		//cout << pos << endl;
        		if(pos >= n)
        			break;
        		ll lf[3], rt[3];
        		for(int p = 0; p < 3; p++){
        			if(p == x)
        				continue;
        			lf[p] = pref[p][i - 1];
        			rt[p] = pref[p][n] - pref[p][pos];
        		}
        		if(x == 0){
        			if(lf[1] >= tot && rt[2] >= tot ){
        				f = 1;
        				
        				cout << i << " " << pos << " " << 1 << " " << i - 1 << " " << pos + 1 << " " << n << endl;
        			}
        			if(lf[2] >= tot && rt[1] >= tot ){
        				f = 1;
        				cout << i << " " << pos << " " << pos + 1 << " " << n << " "<< 1 << " " << i -  1<< endl;
        			}
        		}
        		else if(x == 1){
        			if(lf[0] >= tot && rt[2] >= tot ){
        				f = 1;
        				cout << 1 << " " << i - 1 << " " << i  << " " << pos << " " << pos + 1 << " " << n << endl;
        			}
        			if(lf[2] >= tot && rt[0] >= tot ){
        				f = 1;
        				cout << pos + 1 << " " << n << " " << i << " " << pos << " " << 1 << " " << i - 1 <<  endl;
        			}
        		}
        		else if(x == 2){
        			if(lf[1] >= tot && rt[0] >= tot ){
        				f = 1;
        				cout << pos + 1 << " " << n << " " << 1 << " " << i - 1<< " " << i  << " " << pos  << endl;
        			}
        			if(lf[0] >= tot && rt[1] >= tot ){
        				f = 1;
        				cout << 1 << " " << i - 1 << " "<< pos + 1 << " " << n << " " << i  << " " << pos << endl;
        			}
        		}
        		if(f){

        			break;
        		}
        		
        	}
        	if(f)
        		break;
        }

        if(!f){
        	cout << -1 << endl;
        }

        int val = 13 ^ 14 ^ 15 ^ 12 ;
        cout << val << endl;


    }
    return 0 ;
}
