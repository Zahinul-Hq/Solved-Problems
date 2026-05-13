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
bool check(int val, int val2){	
	vector<int>cnt(10);
	int l1 = 0, l2 = 0;

	while(val){
		cnt[val % 10]++;
		val /= 10;
		l1++;
	}
	while(val2){
		cnt[val2 % 10]++;
		val2 /= 10;
		l2++;
	}
	cnt[0] += l1 < 5;
	cnt[0] += l2 < 5;

	for(int i = 0; i < 10; i++){
		if(cnt[i] > 1 || cnt[i] == 0){
			return false;
		}
	}

	return true;

}
int main()
{


    int N;

    int count = 0;


    while (cin >> N && N)
    {
    	bool f = 1;
    	count++;
		if (count > 1)
			printf("\n");
    	for(int i = 1234; i <= 98765; i++){
    		if(check(i * N, i)){

    			printf("%05d / %05d = %d\n", i * N, i, N);
    			f  = 0;
    		}

    	}
    	if(f){
    		cout << "There are no solutions for " << N << "." << endl;
    	}

    	
    }
    return 0 ;

    runtime();

}
