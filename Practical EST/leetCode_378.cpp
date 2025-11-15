#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];

        while (low < high) {
            long long mid = low + ((long long)high - low) / 2;
            int cnt = countLessEqual(matrix, mid);
            if (cnt < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }

private:
    int countLessEqual(const vector<vector<int>>& mat, long long target) {
        int n = mat.size();
        int row = n - 1, col = 0, count = 0;
        while (row >= 0 && col < n) {
            if (mat[row][col] <= target) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
};




int main() {
  Solution sol;
  vector<vector<int>> matrix = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
  int k = 8;

  int ans = sol.kthSmallest(matrix, k);
  cout<<ans<<endl;
  
  return 0;
}
