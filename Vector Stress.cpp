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

 
void inout()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt" ,"r" , stdin);
		freopen("output.txt" , "w" ,stdout);
		cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;
	#endif
}

std::vector<int> generateRandomVector(int size) {
    std::vector<int> vec(size);
     mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());  // Seed the random number generator
    
    for(int i = 0; i < size; ++i) {
        vec[i] = rand() % 25 + rand() % 29 ;  // Generates random number between 1 and 50
    }

    return vec;
}

int main() {

	inout();


    int t = 100;

    cout << 100 << endl;
    
    while(t--){
    	std::vector<int> randomVec = generateRandomVector(10);

    	cout << 10 << endl;

    
	    for(int val : randomVec) {
	        std::cout << val << " ";
	    }
	    cout << endl;
    }

    return 0;
}