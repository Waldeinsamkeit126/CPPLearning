#include <iostream>
#include <vector>
using namespace std;


template <class Type>
struct Triple{
    int row;
    int col;
    Type data;
};

template <class Type>
class SparseMatrix{
private:
    int Rows;
    int Cols;
    int NonZero_Terms;

    vector<Triple<Type>> SMArray;

public:

    SparseMatrix(int r = 0, int c = 0){
        Rows = r;
        Cols = c;
        NonZero_Terms = 0;

        SMArray.resize(1);
    }


    void Add(int row, int col, Type value){
        if (value != 0){
            Triple<Type> temp;

            temp.row = row;
            temp.col = col;
            temp.data = value;

            SMArray.push_back(temp);

            NonZero_Terms++;
        }
    }
    SparseMatrix<Type> Mat_Transpose();
    SparseMatrix<Type>
    Mat_Fast_Transpose(SparseMatrix<Type> b);
    void PrintMatrix();
    void PrintTriple();
};


template <class Type>
SparseMatrix<Type>
SparseMatrix<Type>::Mat_Transpose(){
    SparseMatrix<Type> b(Cols, Rows);

    for (int col = 0; col < Cols; col++){
        for (int i = 1; i <= NonZero_Terms; i++){
            if (SMArray[i].col == col){
                b.Add(
                    SMArray[i].col,
                    SMArray[i].row,
                    SMArray[i].data
                );
            }
        }
    }

    return b;
}




template <class Type>
SparseMatrix<Type>
SparseMatrix<Type>::
Mat_Fast_Transpose(SparseMatrix<Type> b){

    int i, j;
    int* x = new int[Cols];
    int* y = new int[Cols];
    b.Rows = Cols;
    b.Cols = Rows;
    b.NonZero_Terms = NonZero_Terms;
    b.SMArray.resize(NonZero_Terms + 1);


    if (NonZero_Terms > 0){

        for (i = 0; i < Cols; i++){
            x[i] = 0;
        }



        for (i = 1; i <= NonZero_Terms; i++){
            x[SMArray[i].col]++;
        }
        y[0] = 1;


        for (i = 1; i < Cols; i++){
            y[i] = y[i - 1] + x[i - 1];
        }


        for (i = 1; i <= NonZero_Terms; i++){

            int col = SMArray[i].col;


            j = y[col];
            b.SMArray[j].row = SMArray[i].col;
            b.SMArray[j].col = SMArray[i].row;
            b.SMArray[j].data = SMArray[i].data;
            y[col]++;
        }
    }
    delete[] x;
    delete[] y;
    return b;
}


template <class Type>
void SparseMatrix<Type>::PrintTriple(){
    cout << "row\tcol\tdata" << endl;

    for (int i = 1; i <= NonZero_Terms; i++){
        cout
            << SMArray[i].row << "\t"
            << SMArray[i].col << "\t"
            << SMArray[i].data
            << endl;
    }
}

template <class Type>
void SparseMatrix<Type>::PrintMatrix(){
    vector<vector<Type>> matrix(
        Rows,
        vector<Type>(Cols, 0)
    );


    for (int i = 1; i <= NonZero_Terms; i++){
        matrix[SMArray[i].row]
              [SMArray[i].col]
              = SMArray[i].data;
    }

    for (int i = 0; i < Rows; i++){
        for (int j = 0; j < Cols; j++){
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}