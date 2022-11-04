#include "OutOfRangeException.hpp"

OutOfRangeException::OutOfRangeException(std::string probString): Exception("OUT_OF_RANGE",probString){
    mTag = "OUT_OF_RANGE";
    mProblem = probString;
}