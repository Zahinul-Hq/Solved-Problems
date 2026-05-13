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
const int nmax = 10+5;
const long long int mod = 4294967296;

struct Matrix{
    /// after constructing val contains garbage
    long long int val[nmax][nmax];
    int row, col;

    Matrix(int _r, int _c){
        row = _r;
        col = _c;

        /* memset */
        for(int i = 0; i<row; i++)
            for(int j = 0; j<col; j++)
                val[i][j] = 0;
    }

    Matrix operator*(Matrix other){
        Matrix result(row, other.col); /// O(nmax*nmax)

        for(int i = 0; i<row; i++){
            for(int j = 0; j<other.col; j++){
                for(int k = 0; k<col; k++){
                    result.val[i][j] += val[i][k] * other.val[k][j];
                    result.val[i][j] %= mod;
                }
            }
        }
        /// O(row * col * other.col)

        return result;  /// O(nmax*nmax)
    }

    void print(){
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                cout<<val[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

/// X^n
Matrix Matexpo(Matrix X, long long int n){
    Matrix Y(X.row, X.col);

    if(n == 0){
        for(int i = 0; i<X.row; i++)
            Y.val[i][i] = 1;

        return Y;
    }
    Y = Matexpo(X, n/2);
    Y = Y * Y;

    if(n % 2 == 1){
        Y = Y * X;
    }

    return Y;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n" ;

	ll n;
	cin >> n;
    Matrix M(8, 8), F(8, 8);

    M.val[0][0] = 1;

    for(int row = 0; row < 8; row++){
    	for(int col = 0; col < 8; col++){
    		for(int dr : {-2, -1, 1, 2}){
    			for(int dc : {-2, -1, 1, 2}){
    				if(abs(dr) != abs(dc)){
    					int new_row = row + dr;
    					int new_col = col + dc;
    					if(new_row < 8 && new_row >= 0 && new_col < 8 && new_col >= 0 ){
    						F.val[new_row][new_col] += M.val[row][col];
    					}
    				}

    			}
    		}
    	}
    }

   // M = Matexpo(M, n );

    unsigned int answer = 0;

    for(int i = 0; i < 8; i++){
    	for(int j = 0; j < 8; j++){
    		answer += M.val[i][j];
    		answer %= mod;
    	}
    }

    cout << answer << endl;




    M.print();


    return 0 ;

    runtime();

}
