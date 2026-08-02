#include<bits/stdc++.h> 
using namespace std;

// rotate matrix by 90 degree;

// brute sol;
vector<vector<int>> brute(vector<vector<int>> &matrix){         // tc = O(n*n) ; sc = O(n*n)
    int n = matrix.size();
    vector<vector<int>> ans(n, vector<int>(n , 0));

    for (int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            ans[j][n-i-1] = matrix[i][j];
        }
    }
    return ans;
}

// optimal sol;                    // tc = O(2*n*n) ; sc = O(1)

    void rotateMatrix(vector<vector<int>>& matrix) {      // You only visit the upper triangular half of the matrix, but asymptotically that's still:Time = O(n²)
        int n = matrix.size();

        // transpose of matrix :
        for(int i = 0; i<n ; i++){
            for(int j = i+1 ; j<n ; j++){
                swap(matrix[i][j] , matrix[j][i]);
            }
        }

        // reverse of evrey row;                    // There are n rows, and each row has n elements : Time = O(n²)
        for(int i = 0; i<n ; i++){
                reverse( matrix[i].begin() , matrix[i].end());
        }
    }

int main(){
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<vector<int>> rotated = brute(mat);

    // Print the rotated matrix
    for (auto row : rotated) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    return 0;
}