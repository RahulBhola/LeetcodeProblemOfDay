#include <iostream>
#include <vector>
using namespace std;

int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> in(N + 1), out(N + 1);
    for (auto a : trust) {
        ++out[a[0]];
        ++in[a[1]];
    }
    for (int i = 1; i <= N; ++i) {
        if (in[i] == N - 1 && out[i] == 0) return i;
    }
    return -1;
}

int main() {
    int N = 4; // for example, set the value of N
    vector<vector<int>> trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}}; // for example, set the value of trust
    int result = findJudge(N, trust);
    cout << "The town judge is: " << result << endl;
    return 0;
}
