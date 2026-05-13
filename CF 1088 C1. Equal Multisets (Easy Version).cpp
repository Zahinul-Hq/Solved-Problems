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
    	int n, k;
    	cin >> n >> k;

    	vector<int>arr(n + 1, 0), brr(n + 1, 0);

    	for(int i = 1; i <= n; i++){
    		cin >> arr[i];
    	}
    	map<int,int>mp;
    	for(int i = 1; i <= n; i++){
    		cin >> brr[i];
    		if(i <= k)
    			mp[brr[i]]++;
    	}

    	bool f = 1;
    	

    	for(int i = 1; i <= k; i++){
    		if(mp[arr[i]] == 0){
    			
    			if(mp[-1] > 0)
    				mp[-1]--;
    			else{
    				f = 0;
    				break;
    			}
    		}
    	}

    	if(!f){
    		cout << "NO" << endl;
    		continue;
    	}

    	for(int i = k + 1; i <= n; i++){
    		int ina = arr[i] , inb = brr[i], outa = arr[i - k], outb = brr[i - k];


    		mp[outb]--;
    		mp[inb]++;

    		if(inb == -1)
    			inb = ina;

    		if(ina == inb && outa == outb){
    			continue;
    		}

    		if(outb == -1 && mp[outa] == 0 && ina == inb){
    			continue;

    		}

    		f = 0;
    	}

    	if(f){
    		cout << "YES" << endl;
    	}else{
    		cout << "NO" << endl;
    	}






    }
    return 0 ;

    runtime();

}
