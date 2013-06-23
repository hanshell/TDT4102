#include <iostream>
#include "Matrix2x2.h"
using namespace std;
Matrix2x2::Matrix2x2(double pos1, double pos2, double pos3, double pos4) {
    setMatrixElement(0, 0, pos1);
    setMatrixElement(0, 1, pos2);
    setMatrixElement(1, 0, pos3);
    setMatrixElement(1, 1, pos4);
}

Matrix2x2::Matrix2x2() {
    setMatrixElement(0, 0, 1);
    setMatrixElement(0, 1, 0);
    setMatrixElement(1, 0, 0);
    setMatrixElement(1, 1, 1);
}

double Matrix2x2::getMatrixElement(int posY, int posX)const {
    return matrix[posY][posX];
}

void Matrix2x2::setMatrixElement(int posY, int posX, double value) {
    matrix[posY][posX] = value;
}

Matrix2x2& Matrix2x2::operator+=(Matrix2x2& matrix1) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->setMatrixElement(i, j, (matrix1.getMatrixElement(i, j)) + this->getMatrixElement(i, j));
        }
    }
}

Matrix2x2 Matrix2x2::operator-=(Matrix2x2& matrix1) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            this->setMatrixElement(i, j, (this->getMatrixElement(i, j)) - matrix1.getMatrixElement(i, j));
        }
    }
}
Matrix2x2 Matrix2x2::operator+(Matrix2x2& matrix1) {
    Matrix2x2 matrix2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix2.setMatrixElement(i, j, (matrix1.getMatrixElement(i, j) + this->getMatrixElement(i, j)));
        }
    }
    return matrix2;
}
Matrix2x2 Matrix2x2::operator-(Matrix2x2& matrix1) {
    Matrix2x2 matrix2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix2.setMatrixElement(i, j, (this->getMatrixElement(i, j)-matrix1.getMatrixElement(i, j)));
        }
    }
    return matrix2;
}

Matrix2x2 Matrix2x2::operator*(Matrix2x2& matrix1) {
    Matrix2x2 matrix2;
    matrix2.setMatrixElement(0, 0, (this->getMatrixElement(0, 0) * matrix1.getMatrixElement(0, 0))
            +(this->getMatrixElement(0, 1) * matrix1.getMatrixElement(1, 0)));
    matrix2.setMatrixElement(1, 0, (this->getMatrixElement(1, 0) * matrix1.getMatrixElement(0, 0))
            +(this->getMatrixElement(1, 1) * matrix1.getMatrixElement(1, 0)));
    matrix2.setMatrixElement(0, 1, (this->getMatrixElement(0, 0) * matrix1.getMatrixElement(0, 1))
            +(this->getMatrixElement(0, 1) * matrix1.getMatrixElement(1, 1)));
    matrix2.setMatrixElement(1, 1, (this->getMatrixElement(1, 0) * matrix1.getMatrixElement(0, 1))
            +(this->getMatrixElement(1, 1) * matrix1.getMatrixElement(1, 1)));
    return matrix2;
}
Matrix2x2 Matrix2x2::operator*=(Matrix2x2& matrix1) {
    double temp[4];
    temp[0] = this->getMatrixElement(0, 0);
    temp[1] = this->getMatrixElement(0, 1);
    temp[2] = this->getMatrixElement(1, 0);
    temp[3] = this->getMatrixElement(1, 1);

    setMatrixElement(0, 0, (temp[0] * matrix1.getMatrixElement(0, 0))
            +(temp[1] * matrix1.getMatrixElement(1, 0)));
    setMatrixElement(1, 0, (temp[2] * matrix1.getMatrixElement(0, 0))
            +(temp[3] * matrix1.getMatrixElement(1, 0)));
    setMatrixElement(0, 1, (temp[0] * matrix1.getMatrixElement(0, 1))
            +(temp[1] * matrix1.getMatrixElement(1, 1)));
    setMatrixElement(1, 1, (temp[2] * matrix1.getMatrixElement(0, 1))
            +(temp[3] * matrix1.getMatrixElement(1, 1)));
}

Vector2 Matrix2x2::operator*(Vector2& vector) {
    double value1=vector.getVectorElement(0);
    double value2=vector.getVectorElement(1);
    for (int i = 0; i < 2; i++) {
        vector.setVectorELement(i, ((getMatrixElement(i, 0) * value1)
        + (getMatrixElement(i, 1) * value2)));
    }
    return vector;
}
std::ostream& operator<<(std::ostream& out, Matrix2x2& matrix1) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            out << matrix1.getMatrixElement(i, j) << "  ";
        }
        out<<endl;
    }
    return out;
}

void Matrix2x2::print() {
    std::cout << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << matrix[i][j] << "   ";
        }
        std::cout << std::endl;
    }
}

double Matrix2x2::det() const {
    if (this->getMatrixElement(0, 0) - this->getMatrixElement(1, 1) != 0)
        return this->getMatrixElement(0, 0) * this->getMatrixElement(1, 1) -
        this->getMatrixElement(1, 0) * this->getMatrixElement(0, 1);
    cout<<"Det(M)=0. No inverse"<<endl;
    return 0;
}

Matrix2x2 Matrix2x2::inverse() const {
    Matrix2x2 inverse;
    double inv = 1 / det();
    cout<<det()<<endl<<endl;
    inverse.setMatrixElement(0, 0, inv * getMatrixElement(1, 1));
    inverse.setMatrixElement(0, 1, inv*(getMatrixElement(0, 1)*-1));
    inverse.setMatrixElement(1, 0, inv*(getMatrixElement(1, 0)*-1));
    inverse.setMatrixElement(1, 1, inv * getMatrixElement(0, 0));
    return inverse;
}