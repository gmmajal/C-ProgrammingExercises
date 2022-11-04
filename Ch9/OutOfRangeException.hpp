#ifndef OUTOFRANGEEXCEPTIONHEADERDEF
#define OUTOFRANGEEXCEPTIONHEADERDEF
#include "Exception.hpp"

class OutOfRangeException:public Exception{
    private:
        std::string mTag, mProblem;
    public:
        OutOfRangeException(std::string probString);
};

#endif