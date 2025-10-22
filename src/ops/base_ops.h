#include "../matrix_types/matrix_base.h" 
#include "../errors.h"
#include <type_traits>
#include <concepts>

enum class MatrixCategories; 

template <typename T> 
concept is_Matrix_type = requires{
    typename T::value_T; 
    std::is_base_of_v<MatrixBase<T,typename T::value_T>,T>; 
}; 

template <is_Matrix_type Der, is_Matrix_type Der2>
auto add(const MatrixBase<Der,  typename Der::value_T> &  a, const MatrixBase<Der2, typename Der2::value_T>& b){
    static_assert(!((MatrixTraits<Der>::category == MatrixCategories::Block) ^ 
                (MatrixTraits<Der2>::category == MatrixCategories::Block)),
                "Cannot add a block matrix with a non-block matrix"); //Block matrices cannot be added with non block matrices
    if(!((a.cols() == b.cols()) && (a.rows() == b.rows()))){
        throw ErrorCode::ADDITION_INCOMPATIBLE; 
    }
    
    size_t cols = a.cols(); 
    size_t rows = a.rows(); 
    Der result(rows, cols); 
    for (size_t i{}; i < rows; i++){
        for (size_t j{}; j < cols; j++){
            result.at(i,j) = a.at(i,j) + b.at(i,j); 
        }
    }
    return result; 
}