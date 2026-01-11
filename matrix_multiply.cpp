#include<bits/stdc++.h>
using namespace std;

// iterative matrix multiplication

void matrixMultiply(vector<vector<int>>& a, vector<vector<int>>& b, vector<vector<int>>& c, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j] = c[i][j] + a[i][k]*b[k][j];
            }
        }
    }
}

// recursive matrix multiplication

void recursiveMatrixMultiply(
    vector<vector<int>>& a,
    vector<vector<int>>& b,
    vector<vector<int>>& c,
    int n
){
    if (n == 1)
    {
        c[0][0] += a[0][0] * b[0][0];
        return;
    }

    int k = n / 2;

    vector<vector<int>> a11(k, vector<int>(k)), a12(k, vector<int>(k));
    vector<vector<int>> a21(k, vector<int>(k)), a22(k, vector<int>(k));
    vector<vector<int>> b11(k, vector<int>(k)), b12(k, vector<int>(k));
    vector<vector<int>> b21(k, vector<int>(k)), b22(k, vector<int>(k));

    vector<vector<int>> c11(k, vector<int>(k, 0));
    vector<vector<int>> c12(k, vector<int>(k, 0));
    vector<vector<int>> c21(k, vector<int>(k, 0));
    vector<vector<int>> c22(k, vector<int>(k, 0));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j + k];
            a21[i][j] = a[i + k][j];
            a22[i][j] = a[i + k][j + k];

            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j + k];
            b21[i][j] = b[i + k][j];
            b22[i][j] = b[i + k][j + k];
        }

    // C11 = A11B11 + A12B21
    recursiveMatrixMultiply(a11, b11, c11, k);
    recursiveMatrixMultiply(a12, b21, c11, k);

    // C12 = A11B12 + A12B22
    recursiveMatrixMultiply(a11, b12, c12, k);
    recursiveMatrixMultiply(a12, b22, c12, k);

    // C21 = A21B11 + A22B21
    recursiveMatrixMultiply(a21, b11, c21, k);
    recursiveMatrixMultiply(a22, b21, c21, k);

    // C22 = A21B12 + A22B22
    recursiveMatrixMultiply(a21, b12, c22, k);
    recursiveMatrixMultiply(a22, b22, c22, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            c[i][j]         += c11[i][j];
            c[i][j + k]     += c12[i][j];
            c[i + k][j]     += c21[i][j];   
            c[i + k][j + k] += c22[i][j];
        }
}


int main(){

    return 0;
}