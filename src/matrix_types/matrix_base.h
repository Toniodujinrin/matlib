#ifndef MATRIX_BASE_H 
#define MATRIX_BASE_H 
#include <ostream>
#include <cstddef>
#include <type_traits> 

template <typename T> 
concept is_matrix_number = requires{
    std::is_arithmetic<T>; 
}; 


template <typename Der, is_matrix_number T> 
class MatrixBase{
    public: 
        using value_T = T; 

        size_t rows()const{
            return static_cast<const Der *>(this)->rows(); 
        }
        size_t cols() const{
            return static_cast<const Der *>(this)->cols(); 
        };  

        const T& at(size_t i, size_t j) const{
            return static_cast<const Der*>(this)->at(i,j); 
        }

        T& at(size_t i, size_t j){
            return static_cast<Der*>(this)->at(i,j); 
        }
}; 

template <typename Der, is_matrix_number T> 
std::ostream& operator<<(std::ostream& out, MatrixBase<Der, T>& mat ){
    size_t rows = mat.rows(); 
    size_t cols = mat.cols(); 
    for (size_t i{}; i < rows; i++){
        out<<"["; 
        for (size_t j{}; j < cols; j++){
            out<< mat.at(i,j)<< (j == cols-1?"":", "); 
        }
        out<<"]\n"; 
    }
    return out; 
}













#endif 