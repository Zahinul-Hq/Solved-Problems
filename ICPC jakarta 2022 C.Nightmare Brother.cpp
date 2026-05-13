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

 
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
const auto start_time = std::chrono::high_resolution_clock::now();
void runtime()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> diff = end_time-start_time;
    cerr<<"Time: "<<roundl(diff.count())<<"ms\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;


    int n , k, p;
    string s;
    cin >> n >> k;

    vector<pair<int,string>>vp;
    for(int i = 0; i < n; i++){
    	cin >> p >> s;
    	vp.push_back({p - 1, s});
    }
    string ans;
    int ok = 0;

    set<string>st;

    for(int i = 0; i <= n; i++){
    	string temp(k, '#');
    	bool collide = 0;
    	for(int j = 0; j < n; j++){
    		if(j == i)
    			continue;
    		string str = vp[j].S;

    		for(int l = vp[j].F, t = 0; l <= str.size() + vp[j].F - 1; l++, t++){
    			if(temp[l] == '#' || temp[l] == str[t])
    				temp[l] = str[t];
    			else{
    				collide = 1;
      			}
    		}
    	}
    	for(int t = 0; t < k; t++){
    		if(temp[t] == '#'){
    			collide = 1;
    		}
    	}

    	if(!collide)
    		st.insert(temp);

    }
    if(st.size() == 1){
    		cout << *st.begin() << endl;
    	}else if(st.size() >= 2){
    		cout << -2 << endl;
    	}else{
    		cout << -1 << endl;
    	}
    return 0 ;

    runtime();

}
