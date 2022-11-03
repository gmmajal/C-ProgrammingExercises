#include <cassert>
#include <cmath>

template<unsigned int DIM> class DoubleVector{
    private:
        double mData[DIM];
    public:
        double& operator[](int index){
            assert(index<DIM);
            assert(index>-1);
            assert( -1e-6<=mData[index]  &&  mData[index] <= (1+1e-6) );
            if( -1e-6<= mData[index] && mData[index]<0.0){
                mData[index]=0.0;
                return mData[index];
            }
            else if( mData[index]>1.0 && mData[index]<=(1+1e-6) ){
                mData[index]=1.0;
                return mData[index];
            }
            else{
                return mData[index];
            }
        }
}; 
