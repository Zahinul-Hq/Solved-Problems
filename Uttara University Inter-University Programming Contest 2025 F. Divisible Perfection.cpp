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


    int test_cases ;
    cin >> test_cases ;
    
    while (test_cases--)
    {
    	int n;
    	string s;

    	cin >> n >> s;

    	if(s.size() > 5){
    		cout << "NO" << endl;
    		continue;
    	}
    	vector<pair<int,int>>arr;

    	bool ok = 1;

    	for(int l = 0; l < min(5, n); l++){
    		for(int i = 0; i < n - l; i++){
    			string temp = "";
    			for(int j = i; j <= i + l; j++){
    				temp += s[j];
    			}

    			int val = stoi(temp);

    			if(val % (int)temp.size() != 0){
    				ok = 0;
    			}


    		}

    	}

    	if(ok){
    		cout << "YES"<< endl;
    	}else{
    		cout << "NO" << endl;
    	}

    	debug(arr);

    	
    }
    return 0 ;

    runtime();

}
