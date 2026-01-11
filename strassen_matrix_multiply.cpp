#include<bits/stdc++.h>
using namespace std;

void strassenMatrixMultiply(
    vector<vector<int>>& A,
    vector<vector<int>>& B,
    vector<vector<int>>& C,
    int n
){
    if (n == 1)
    {
        C[0][0] += A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    vector<vector<int>> A11(k, vector<int>(k)), A12(k, vector<int>(k));
    vector<vector<int>> A21(k, vector<int>(k)), A22(k, vector<int>(k));
    vector<vector<int>> B11(k, vector<int>(k)), B12(k, vector<int>(k));
    vector<vector<int>> B21(k, vector<int>(k)), B22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    // S matrices
    vector<vector<int>> S1(k, vector<int>(k)), S2(k, vector<int>(k));
    vector<vector<int>> S3(k, vector<int>(k)), S4(k, vector<int>(k));
    vector<vector<int>> S5(k, vector<int>(k)), S6(k, vector<int>(k));
    vector<vector<int>> S7(k, vector<int>(k)), S8(k, vector<int>(k));
    vector<vector<int>> S9(k, vector<int>(k)), S10(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            S1[i][j]  = B12[i][j] - B22[i][j];
            S2[i][j]  = A11[i][j] + A12[i][j];
            S3[i][j]  = A21[i][j] + A22[i][j];
            S4[i][j]  = B21[i][j] - B11[i][j];
            S5[i][j]  = A11[i][j] + A22[i][j];
            S6[i][j]  = B11[i][j] + B22[i][j];
            S7[i][j]  = A12[i][j] - A22[i][j];
            S8[i][j]  = B21[i][j] + B22[i][j];
            S9[i][j]  = A11[i][j] - A21[i][j];
            S10[i][j] = B11[i][j] + B12[i][j];
        }

    // P matrices
    vector<vector<int>> P1(k, vector<int>(k, 0)), P2(k, vector<int>(k, 0));
    vector<vector<int>> P3(k, vector<int>(k, 0)), P4(k, vector<int>(k, 0));
    vector<vector<int>> P5(k, vector<int>(k, 0)), P6(k, vector<int>(k, 0));
    vector<vector<int>> P7(k, vector<int>(k, 0));

    strassenMatrixMultiply(A11, S1,  P1, k);
    strassenMatrixMultiply(S2,  B22, P2, k);
    strassenMatrixMultiply(S3,  B11, P3, k);
    strassenMatrixMultiply(A22, S4,  P4, k);
    strassenMatrixMultiply(S5,  S6,  P5, k);
    strassenMatrixMultiply(S7,  S8,  P6, k);
    strassenMatrixMultiply(S9,  S10, P7, k);

    // Compute C blocks
    vector<vector<int>> C11(k, vector<int>(k));
    vector<vector<int>> C12(k, vector<int>(k));
    vector<vector<int>> C21(k, vector<int>(k));
    vector<vector<int>> C22(k, vector<int>(k));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C11[i][j] = P5[i][j] + P4[i][j] - P2[i][j] + P6[i][j];
            C12[i][j] = P1[i][j] + P2[i][j];
            C21[i][j] = P3[i][j] + P4[i][j];
            C22[i][j] = P5[i][j] + P1[i][j] - P3[i][j] - P7[i][j];
        }

    // Combine into C
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
        {
            C[i][j]         += C11[i][j];
            C[i][j + k]     += C12[i][j];
            C[i + k][j]     += C21[i][j];
            C[i + k][j + k] += C22[i][j];
        }
}


int main(){

    return 0;
}