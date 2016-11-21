#include <iostream>
#include <fstream>
using namespace std;

const int DECLARED_SIZE = 10;

//the multi matrix consists of the first matrix, the second matrix, and the multiplied matrix
void multi_matrix(int matrix1[DECLARED_SIZE][DECLARED_SIZE],int matrix2[DECLARED_SIZE][DECLARED_SIZE],int matrix_new[DECLARED_SIZE][DECLARED_SIZE]);

int main() {
    int matrix1st[DECLARED_SIZE][DECLARED_SIZE] = {}, matrix2nd[DECLARED_SIZE][DECLARED_SIZE] = {}, matrix_multi[DECLARED_SIZE][DECLARED_SIZE] = {};

    
    multi_matrix(matrix1st, matrix2nd, matrix_multi);
    return 0;
}

void multi_matrix(int matrix1[DECLARED_SIZE][DECLARED_SIZE],int matrix2[DECLARED_SIZE][DECLARED_SIZE],int matrix_new[DECLARED_SIZE][DECLARED_SIZE])
  {
    //this is to count the number of rows and columns that
    //are BEING USED in matrix 1 and matrix 2
    int num_in_row_matrix1 = 0;
    int num_in_col_matrix1 = 0;
    int num_in_col_matrix2 = 0;
    int num_in_row_matrix2 = 0;

    //this is getting the first matrix
    cout << "Enter first matrix:" << endl;
    for(int i = 0; i < DECLARED_SIZE; i++){
        for(int j = 0; j < DECLARED_SIZE; j++){
            cin >> matrix1[i][j];
            num_in_col_matrix1++; 
            char c2 = cin.peek();
            if(c2 == '\n'){
                break;
                
            }
        }
        
        num_in_row_matrix1++;
        char c4 = cin.get();
        char c3 = cin.peek();
        if(c3 == '\n'){
            break;
        }
        num_in_col_matrix1 = 0;
    }
    //this gets the second matrix
    cout << "Enter second matrix:" << endl;
    for(int i = 0; i < DECLARED_SIZE; i++){
        for(int j = 0; j < DECLARED_SIZE; j++){
            cin >> matrix2[i][j];
            num_in_col_matrix2++;
            char c2 = cin.peek();
            if(c2 == '\n'){
                break;
            }
        }
        num_in_row_matrix2++;
        char c4 = cin.get();
        char c3 = cin.peek();
        if(c3 == '\n'){
            break;
        }
        num_in_col_matrix2 = 0;
    }
    // for a 2 by 2 matrix multiplication,the first matrix's column MUST equal
    // the second matrix's row. We use that using the count defined at the beginning of the function
    // if they are equal, then we would start the multiplication by multiplying each matrix and adding the
    // numbers into a new matrix. We would then print out ONLY the number of columns and rows that
    // were used in the new matrix and we print our multiplied matrix result
    if (num_in_col_matrix1 == num_in_row_matrix2){
        cout << "The product is:" << endl;
        for(int i = 0; i < DECLARED_SIZE; i ++){
            for(int j = 0; j < DECLARED_SIZE; j++){
                for(int k = 0; k < DECLARED_SIZE; k++){
                    matrix_new[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        for(int i = 0; i < num_in_row_matrix1; i++){
            for(int j = 0; j < num_in_col_matrix2; j++){
                if(matrix_new[0][j]!=matrix_new[0][num_in_col_matrix2-1]){
                    cout <<matrix_new[i][j]<<" ";
                }
                else{
                    cout<<matrix_new[i][num_in_col_matrix2-1];
                }

            }
            cout << endl;
        }
    }else{
        // if matrix 1's columns DOES NOT equal matrix 2's rows, 
        // THEN we aren't able to do the matrix multiplication
        cout << "The two matrices have incompatible dimensions." << endl; 
    }
    

}