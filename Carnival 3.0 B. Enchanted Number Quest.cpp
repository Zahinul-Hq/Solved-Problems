#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    // Read test cases and determine maximum B.
    vector<pair<int,int>> testCases(T);
    int maxB = 0;
    for (int i = 0; i < T; i++){
        int A, B;
        cin >> A >> B;
        testCases[i] = {A, B};
        maxB = max(maxB, B);
    }
    
    // We need divisor counts for numbers up to maxB (since for base b, we need tau(b-1) and b-1 <= maxB-1).
    int maxN = maxB;
    vector<int> divCount(maxN + 1, 0);
    
    // Sieve approach: For each integer i, add 1 to every multiple j of i.
    for (int i = 1; i <= maxN; i++){
        for (int j = i; j <= maxN; j += i){
            divCount[j]++;
        }
    }
    
    // Build a prefix sum array so that prefix[i] = divCount[1] + divCount[2] + ... + divCount[i]
    vector<long long> prefix(maxN + 1, 0);
    for (int i = 1; i <= maxN; i++){
        prefix[i] = prefix[i-1] + divCount[i];
    }
    
    for (auto &tc : testCases) {
        int A = tc.first, B = tc.second;
        if (B < 2) {

            cout << 0 << "\n";
            continue;
        }
        int lowBase = max(A, 2);
        int L = lowBase - 1;  // starting index for b-1
        int R = B - 1;        // ending index for b-1
        long long ans = prefix[R] - (L - 1 >= 1 ? prefix[L - 1] : 0);
        cout << ans << "\n";
    }
    
    return 0;
}
