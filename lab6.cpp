#include <iostream>
#include <fstream>
#include <iomanip>

const int lim_max = 100;
void readFromFile(int matrixa[lim_max][lim_max],int matrixb[lim_max][lim_max], int &size, const char *filename);
void printMatrix(const int matrix[lim_max][lim_max], int size);
void addMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size);
void multMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size);
void subtractMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size);
int main() 
{
    int matrixa[lim_max][lim_max];
    int matrixb[lim_max][lim_max];
    int result[lim_max][lim_max];
    int size;
    readFromFile(matrixa, matrixb, size, "matrix_input.txt");
    std::cout << "Dylan Sailors" << std::endl;
    std::cout << "Lab #6: Matrix manipulation\n" << std::endl;
    //matrix A
    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixa, size);
    //matrix B
    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixb, size);
    //matrix operations
    addMatrix(matrixa, matrixb, result, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(result, size);
    multMatrix(matrixa, matrixb, result, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(result, size);
    subtractMatrix(matrixa, matrixb, result, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(result, size);

    return 0;
}
//read matrix from file
void readFromFile(int matrixa[lim_max][lim_max], int matrixb[lim_max][lim_max], int &size, const char *filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error: Unable to open the file " << filename << std::endl;
        exit(1);
    }
    file >> size;
    //matrix A
    for (int i = 0; i < (size); ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            file >> matrixa[i][j];
        }
    }
    //matrix B
    for (int i = 0; i < (size); ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            file >> matrixb[i][j];
        }
    }
}
//print matrix
void printMatrix(const int matrix[lim_max][lim_max], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n";
}
//add matrices
void addMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = matrixa[i][j] + matrixb[i][j];
        }
    }
}
//multiply matrices
void multMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k) 
            {
                result[i][j] += matrixa[i][k] * matrixb[k][j];
            }
        }
    }
}
//subtract matrices
void subtractMatrix(const int matrixa[lim_max][lim_max], const int matrixb[lim_max][lim_max], int result[lim_max][lim_max], int size) 
{
    for (int i = 0; i < size; ++i) 
    {
        for (int j = 0; j < size; ++j) 
        {
            result[i][j] = matrixa[i][j] - matrixb[i][j];
        }
    }
}
