#include <iostream>
#include <vector>
using namespace std;

class Matrix 
{
    private:
        int rows;
        int cols;
        vector<vector<int>> data;

    public:
        Matrix(int r, int c) : rows(r), cols(c), data(r, vector<int>(c, 0)) {}

        int getRows() const 
        {
            return rows;
        }

        int getCols() const 
        {
            return cols;
        }

        void setElement(int i, int j, int value) 
        {
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                data[i][j] = value;
            }
        }

        Matrix add(const Matrix& other) const 
        {
            if (rows != other.rows || cols != other.cols) 
            {
                cout << "Matrices cannot be added" << endl;
                return Matrix(0, 0);
            }
            Matrix result(rows, cols);

            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < cols; j++) {
                    result.data[i][j] = data[i][j] + other.data[i][j];
                }
            }
            return result;
        }

        Matrix multiply(const Matrix& other) const 
        {
            if (cols != other.rows) 
            {
                cout << "Matrices cannot be multiplied" << endl;
                return Matrix(0, 0);
            }
            Matrix result(rows, other.cols);
            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < other.cols; j++) 
                {
                    for (int k = 0; k < cols; k++) 
                    {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }

        void display() const 
        {
            for (int i = 0; i < rows; i++) 
            {
                for (int j = 0; j < cols; j++) 
                {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(int argc, char* argv[]) 
{
    if (argc < 5) 
    {
        cerr << "Usage: " << argv[0] << " <rows1> <cols1> <rows2> <cols2> <elements...>" << endl;
        return 1;
    }

    int rows1 = stoi(argv[1]);
    int cols1 = stoi(argv[2]);
    int rows2 = stoi(argv[3]);
    int cols2 = stoi(argv[4]);

    if (argc != 5 + rows1 * cols1 + rows2 * cols2) 
    {
        cerr << "Invalid number of elements provided" << endl;
        return 1;
    }

    Matrix mat1(rows1, cols1);
    Matrix mat2(rows2, cols2);

    int index = 5;
    for (int i = 0; i < rows1; i++) 
    {
        for (int j = 0; j < cols1; j++) 
        {
            mat1.setElement(i, j, stoi(argv[index++]));
        }
    }

    for (int i = 0; i < rows2; i++) 
    {
        for (int j = 0; j < cols2; j++) 
        {
            mat2.setElement(i, j, stoi(argv[index++]));
        }
    }

    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();

    Matrix sum = mat1.add(mat2);
    if (sum.getRows() != 0 && sum.getCols() != 0) 
    {
        cout << "Sum of matrices:" << endl;
        sum.display();
    }

    Matrix product = mat1.multiply(mat2);
    if (product.getRows() != 0 && product.getCols() != 0) 
    {
        cout << "Product of matrices:" << endl;
        product.display();
    }

    return 0;
}