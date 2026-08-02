#include<bits/stdc++.h>
using namespace std;
// helper fun for brute force sol

void row (vector<vector<int>> &matrix , int i ,int n){
    for(int k = 0 ; k<n ; k++){
        if(matrix[i][k] != 0){
            matrix[i][k] = -1;
        }
    }
}

void column (vector <vector<int>> &matrix ,int j, int m){
    for(int i = 0 ; i<m ; i++){
        if(matrix[i][j] != 0){
            matrix [i][j] = -1;
        }
    }
}

// Set matrix zeroes : 

// brute
void brute (vector<vector <int>> &matrix){          // tc = O(n*m + n+m + n*m) = approx (n*n*n) ; sc = (1)
    // get no of rows;
    int m = matrix.size();
    // get no of colums;
    int n = matrix[0].size();

    for(int i = 0 ; i<m ; i++){
        for(int j = 0; j<n ; j++){
            if (matrix[i][j] == 0){
                row(matrix , i ,n);
                column(matrix ,j , m);
            }
        }
    }
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(matrix [i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }
}

// better

void better (vector<vector<int>> &matrix){          // tc = O(2*n*m) ; sc = (n+m)
    int m = matrix.size();
    int n = matrix[0].size();
    vector <int> column(n , 0);
    vector <int> row ( m , 0);

    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(matrix [i][j] == 0){
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n ; j++){
            // if(row[i] == 1){
            //     int k = 0;
            //     while(k < n){
            //         matrix[i][k] = 0;
            //         k++;
            //     }                
            // }
            // if(column[j] == 1){
            //     int l = 0;
            //     while (l<m){
            //         matrix[l][j] = 0;
            //         l++;
            //     }
            // }

        if(row[i] == 1|| column[j] == 1){
            matrix [i][j] = 0;
        }
        }
    }
}

// optimlal sol

void optimal (vector<vector<int>> &matrix){         // tc = O(2*m*n ) ; sc = O(1);
    int m = matrix.size();
    int n = matrix[0].size();
    int colo0 = 1;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j<n ; j++){
            if(matrix [i][j] == 0){
                matrix[i][0] = 0;
                if(j!=0){
                matrix [0][j] = 0;
                }
                else{
                    colo0 = 0;
                }
            }
        }
    }
    for(int i = m-1 ; i>0 ; i--){
        for(int j = n-1 ; j>0 ;j--){
            if(matrix[0][j] == 0 || matrix [i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(matrix[0][0] == 0){
        for(int j = 0 ; j<n ; j++){
            matrix[0][j] = 0;
        }
    }
    // cout << colo0 << " i am colo0" << endl; 
    if(colo0 == 0){
        for(int i = 0 ; i<m ; i++){
            matrix[i][0] = 0;
        }
    }
    // matrix[0][0] = 9;
    // for(int i = 0 ; i<m ; i++){
    //     for(int j = 0; j<n ; j++){
    //         if(matrix[i][0] == 0){
    //             matrix[i][j] = 0;
    //         }
    //         if(matrix[0][j] == 0){
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }
}

int main(){
// Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,1,1},{0,1,1}};
    // Call function to modify matrix
    optimal(matrix);
    
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}