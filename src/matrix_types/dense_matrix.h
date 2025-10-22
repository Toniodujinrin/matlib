#ifndef DENSE_MATRIX_H 
#define DENSE_MATRIX_H



#include "./matrix_base.h"
#include "../matrix_categories.h"
#include <memory>


template <typename T> 
class DenseMatrix; 

template <typename T> 
struct MatrixTraits; 

template <typename T> 
struct MatrixTraits<DenseMatrix<T>>{
    constexpr static MatrixCategories category = MatrixCategories::Dense; 
}; 

template <typename T> 
class DenseMatrix : public MatrixBase<DenseMatrix<T>,T> {
    public: 
        DenseMatrix(size_t rows, size_t cols): 
            m_size{rows*cols},
            m_rows{rows}, 
            m_cols{cols}, 
            _inner{std::make_unique<T[]>(rows*cols)}
        {}; 
        DenseMatrix() = delete; 
        ~DenseMatrix() = default; 
        
        DenseMatrix(const DenseMatrix& src):DenseMatrix(src.rows(),src.cols()){
            for (int flat_i{}; flat_i < src.get_size(); flat_i++ ){
                _inner[flat_i] = src.flat_at(flat_i); 
            }
        }

        DenseMatrix(const DenseMatrix&& src){

        }
 
        size_t rows() const noexcept{
            return m_rows; 
        }; 
        size_t cols() const noexcept{
            return m_cols; 
        }; 

        size_t get_size() const noexcept{
            return m_size; 
        }

        T& at(size_t i, size_t j){
            return _inner[(j*m_rows) + i]; //column major mapping used
        }; 

        const T& at(size_t i, size_t j) const {
            return _inner[(j*m_rows) + i]; 
        }; 

        const T& flat_at(size_t i) const{
            return _inner[i]; 
        }

        T& flat_at(size_t i){
            return _inner[i]; 
        }

        void fill(T value){
            for(size_t i{}; i < m_size; i++){
                _inner[i] = value; 
            }
        }
        
        template <typename Der, typename U> 
        DenseMatrix<T> operator+(const MatrixBase<Der, U> & b ){
           return add(*this, b); 
        }

        DenseMatrix<T> transpose(){
            DenseMatrix<T> result(m_cols, m_rows); 
            for(size_t i{}; i < m_rows; i++){
                for(size_t j{}; j<m_cols; j++){
                    result.at(j,i) = at(i,j); 
                }
            }
            return result; 
        }

    private: 
        size_t m_size, m_rows, m_cols; 
        std::unique_ptr<T[]> _inner {nullptr}; 
     
};    

#endif //DENSE_MATRIX_H 