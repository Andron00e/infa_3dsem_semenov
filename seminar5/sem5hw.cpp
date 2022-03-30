#include <iostream>
#include <conio.h>
using namespace std;


class Matrix
{
    private:
        int m;
        int n;
        int** mat;
    public:
        void Del()
        {
            for (int z = 0; z < m; z++)
                delete[] mat[z];

            delete[] mat;
        }

        void CreateMatrix()
        {
            mat = new int* [m];

            for (int z = 0; z < m; z++)
                mat[z] = new int[n];
        }

        void Elements()
        {
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    cin >> mat[i][j];
        }

        void Print()
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << mat[i][j] << " ";
                }

                cout << endl;
            }
        }

        int return_m(){
            return m;
        };

        int return_n(){
            return n;
        };

        Matrix(){

            int m = 0;
            int n = 0;
            int mat = 0;
        }

        Matrix(int m, int n){

            this->m = m;
            this->n = n;
            CreateMatrix();
        }

        void matrix_copying(const Matrix& M){

            Del();
            CreateMatrix();

            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; ++j)
                    mat[i][j] = M.mat[i][j];
        }

        friend Matrix operator + (Matrix& A, Matrix& B){

            int m_new = A.return_m();
            int n_new = B.return_n();
            Matrix temp(m_new, n_new);

            for (int i = 0; i < m_new; ++i){
                for (int j = 0; j < n_new; ++j){
                    temp.mat[i][j] = A.mat[i][j] + B.mat[i][j];
                }
            }

            return temp;
        }

        void T(const Matrix& M){
            int temp;
            for(int i = 0; i < m; ++i)
            {
                for(int j = i; j < n; ++j)
                {
                    temp = mat[i][j];
                    mat[i][j] = mat[j][i];
                    mat[j][i] = temp;
                }
            }
        }

        friend Matrix operator - (Matrix& A, Matrix& B){
            int m_new = A.return_m();
            int n_new = B.return_n();
            Matrix temp(m_new, n_new);

            for (int i = 0; i < m_new; i++){
                for (int j = 0; j < n_new; j++){
                    temp.mat[i][j] = A.mat[i][j] - B.mat[i][j];
                }
            }

            return temp;
        }

 /*       friend Matrix operator * (Matrix& A, Matrix& B) {
            int N;
            Matrix temp(m1, n1);
            if (N = n = m){
            for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++){
                temp.mat[i][j] += A.mat[i][k] * B.mat[k][j];

        }
        return temp;
        }
            else {
                cout << "Problem";
            }

         Matrix operator = (const Matrix& B){
            matrix_copying(B);
            return *this;
        }
 */
        ~Matrix(){
            for (int z = 0; z < m; z++)
                delete[] mat[z];

            delete[] mat;
        }

};

ostream& operator <<(ostream& ostr, Matrix& m)
{
    m.Print();
    return (ostr);
}

istream& operator >>(istream& in, Matrix& m)
{
    m.Elements();
    return (in);
}

int main()
{
    Matrix A(3, 3);
    cout << "A = " << endl;
    cin >> A;
    cout << "Matrix A = " << endl;
    cout << A;
    Matrix B(3, 3);
    cout << "B = " << endl;
    cin >> B;
    cout << "Matrix B = " << endl << B << endl;

    Matrix C = A + B;
    cout << "Matrix A + B = " <<endl;
    cout << C << endl;

    Matrix D = A - B;
    cout << "Matrix A - B = " <<endl;
    cout << D << endl;

    //Matrix F = A * B;
    //cout << "Matrix A * B = " <<endl;
    //cout << F << endl;


    return 0;
}
