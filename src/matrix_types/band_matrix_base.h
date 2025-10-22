#ifndef BAND_MATRIX_BASE_H 
#define BAND_MATRIX_BASE_H
#include "matrix_base.h"

template<typename Der, is_matrix_number T> 
class BandMatrixBase : public MatrixBase{
    public: 
        //return the size of the upper band
        size_t u_band()const{
            return static_cast<const Der *>(this)->u_band()
        }

        //return the size of the lower band
        size_t l_band()const{
            return static_cast<const Der *>(this)->l_band(); 
        }

}; 


#endif //BAND_MATRIX_BASE_H