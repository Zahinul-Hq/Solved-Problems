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
vector<pair<int,int>> ans ;
void check_segment(vector<int> & val , int i){

	int pos1 = -1, pos2 = 0;

	for(int l = 0; l < val.size(); l++){
		if(val[l] != 0){
			if(pos1 == -1)
				pos1 = l;
			else
				pos2 = l;
		}

	}

	i = i - val.size() + 1;
	if((val[pos1] != val[pos2]) && ((pos1 + pos2) % 2 == 0) || (val[pos1] == val[pos2]) && ((pos1 + pos2) % 2 != 0)){
		ans.push_back({i, i + pos2});
	}else if((val[pos1] == val[pos2]) && ((pos1 + pos2) % 2 == 0)){
		ans.push_back({i, i + pos2 - 2});
		ans.push_back({i + pos2 -1, i + pos2});
	}else if((val[pos1] != val[pos2]) && ((pos1 + pos2) % 2 != 0)){
		ans.push_back({i, i + pos2 - 1});
		ans.push_back({i + pos2, i + pos2});

	}

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
        int n, sum = 0;

        cin >> n;

        vector<int>arr(n + 1);

        for(int i = 1; i <= n; i++){
        	cin >> arr[i];
        	sum += abs(arr[i]);
        }

        
        if(sum == 0){
        	cout << 1 << endl;
        	cout << 1 << " " << n << endl;
        	continue;
        }
        if(sum % 2 != 0){
        	cout << -1 << endl;
        	continue;
        }

        int len = 0;
        vector<int>temp, zero;

        for(int i = 1; i <= n; i++){
        	if(arr[i] != 0) 
        		len++;

        	if(len == 0){
        		zero.push_back(i);
        	}else{
        		temp.push_back(arr[i]);

        	}

        	

        	if(len == 2){
        		if(zero.size() > 0){
        			ans.push_back({zero[0], zero[zero.size() -1]});
        			zero.clear();
        		}
        		check_segment(temp, i);
        		
        		temp.clear();
        		len = 0;	
        	}

        }
        if(zero.size() > 0){
        	ans.push_back({zero[0], zero[zero.size() -1]});
        	zero.clear();
        }

        cout << ans.size() << endl;

        for(auto i : ans){
        	cout << i.F << " " << i.S << endl;
        }

        ans.clear();
    }
    return 0 ;
}
