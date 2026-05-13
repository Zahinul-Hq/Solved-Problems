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
string s ;
int i ;
bool A(){

	if(s[i] == 'a' && i < s.size()){
		i++;
		return A();
	}
	return true;
}

bool B(){

	if(s[i] == 'b' && i == s.size() - 1){
		return true;
	}

	if(s[i] == 'b' && i < s.size()){
		i++;
		if(B()){
			return true;
		}

	}

	return false;

}

bool C(){

	if(s[i] == 'c' && i == s.size() - 1){
		return true;

	}

	if(s[i] == 'c'){
		i++;

		if(C()){
			i++;
			return s[i] == 'd';
		}
	}

	return false;

}

bool S(){
	if(A()){
		if(B()){
			if(C()){
				return true;
			}
		}
	}
	return false;
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
    	cin >> s;

    	if(S()){
    		cout << "Valid" <<endl;
    	}else{
    		cout << "invalid" << endl;
    	}

    	i = 0;
    }
    return 0 ;

    runtime();

}
