#include "Matrices.h"
#include <cmath>

namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols)
    {
        a.resize(_rows);
        for (int i = 0; i <_rows; i++)
        {
            a[i].resize(_cols);
            for (int j = 0; j < _cols; j++)
            {
                a[i][j] = 0;
            }
        }
    }

    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        Matrix results(a.getRows(), b.getCols());
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
               results(i,j) = a(i,j) + b(i,j);
            }
        }
        return results;
    }

    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        Matrix results(a.getRows(), b.getCols());
        for (int j = 0; j < b.getCols(); j++)
        {
            for (int i = 0; i < a.getRows(); i++)
            {
                double total = 0;
                for (int k = 0; k< a.getCols(); k ++)
                {
                    total += a(i,k) * b(k,j);
                }
                results(i,j)  = total;
            }
        }
        return results;
    }

    bool operator==(const Matrix& a, const Matrix& b)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < b.getCols(); j++)
            {
                if(abs(a(i, j) - b(i, j))< 0.001)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }

    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for(int i = 0; i < a.getRows(); i++)
        {
            for(int j = 0; j < a.getCols(); j++)
            {
                os << a(i, j) << " ";
            }
            os << "\n";
        }
        return os;
    }

    RotationMatrix::RotationMatrix(double theta) : Matrix(2, 2)
            {
                (*this)(0,0) = cos(theta);
                (*this)(0,1) = -sin(theta);
                (*this)(1,0) = sin(theta);
                (*this)(1,1) = cos(theta);
            }

    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
            {
                (*this)(0,0) = scale;
                (*this)(0,1) = 0;
                (*this)(1,0) = 0;
                (*this)(1,1) = scale;
            }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2, nCols)
            {
                for (int i = 0; i < nCols; i++)
                {
                    (*this)(0,i) = xShift;
                    (*this)(1,i) = yShift;
                }
            }

}