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
        int n, k;
        string s;
        cin >> n >> k >> s;

        if(k == 0){
        	cout << s << endl;
        	
        	for(int i = 0; i < n; i++){
        		cout << 0 << " ";
        	}
        	cout << endl;
        	continue;
        }

        vector<int>ans;
        string str = "";
        int rem = k, last_zero = 0, last_indx = 0;

        for(int i = 0; i < n ; i++){
        	str += '1';
        	if(k % 2){
        		ans.push_back(s[i] == '1');
        	}else{
        		ans.push_back(s[i] == '0');
        	}
        	
        	last_indx = i;
        	rem -= ans[i];
        	if(!rem)
        		break;
        }

        
        if(!rem){
        	for(int i = last_indx + 1; i < n; i++){
        		if(k % 2 == 0){
        			str += s[i];
        		}else{
        			str += ((s[i] == '0') + '0');
        		}
        		ans.push_back(0);
        	}
        	cout << str << endl;
        	for(auto i : ans){
        		cout << i << " ";
        	}
        	cout << endl;
        	continue;
        }
        if(rem % 2 == 0){
        	cout << str << endl;
        	for(int i = 0; i < ans.size() - 1; i++){
        		cout << ans[i] << " "; 
        	}
        	cout << ans[n - 1] + rem << endl;
        	continue;
        }
        bool f = 0;
        int d = 0;

        for(int i = 1; i <= n; i++){
        	if(rem % i == 0){
        		if(i % 2 == 0)
        			if((rem / i) <= n){
        				d = rem / i;
        				break;
        			}
        		if((rem / i) % 2 == 0){
        			d = i;
        			break;
        		}
        	}
        }
        if(d == 0){
        	str[n - 1] = '0';
        	cout << str << endl;
        	for(int i = 0; i < ans.size() - 1; i++){
        		cout << ans[i] << " "; 
        	}
        	cout << ans[n - 1] + rem << endl;

        }else{
        	int ex = rem / d;
        	cout << str << endl;
        	for(int i = 0; i < n; i++){
        		if(i < d)
        			cout << ans[i] + ex << " ";
        		else{
        			cout << ans[i] << " ";
        		}
        		
        	}
        	cout << endl;
        }
    }
    return 0 ;
}
