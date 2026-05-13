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

        bool zero = 0;

        for(int i = 0; i < n; i++){
        	if(s[i] == '0')
        		zero = 1;
        }
        if(zero && n > 3){
        	cout << 0 << endl;
        	continue;
        }
        if(n == 3 && (s[0] == '0' || (s[2] == '0'))){
        	cout << 0 << endl;
        	continue;
        }
        if(n == 2){
        	if(s[0] == '0'){
        		cout << s[1] << endl;
        	}else{
        		cout << s << endl;
        	}
        	continue;
        }
        ll ans = inf;
        for(int i = 0; i < n - 1; i++){
        	ll sum = 0;
        	for(int j = 0; j < n; j++){
        		int val = s[j] - '0';
        		if(j == i){
        			val = ((s[j] - '0') * 10) + (s[j + 1] - '0');
        			j++;
        		}
        		if(sum == 1){
        			sum *= val;
        			continue;
        		}
        		if((val == 1 && sum != 0)){
        			sum *= 1;
        		}else{
        			sum += val;
        		}
        	}
        	ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    return 0 ;
}
