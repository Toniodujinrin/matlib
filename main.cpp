#include "./src/matrix_types/dense_matrix.h"
#include "./src/ops/base_ops.h" 
#include <iostream>


int main(){
    DenseMatrix<int> mat_1{3,3}; 
    DenseMatrix<float> mat_2{3,3}; 
    std::cout<<mat_1; 
    mat_1.fill(4); 
    mat_2.fill(3.3); 
    std::cout<<mat_1;
    std::cout<<mat_2;  
    auto mat_3{mat_1.transpose()}; 
    auto mat_4 = mat_1+mat_2; 
    std::cout<< mat_4; 
}