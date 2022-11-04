#include "FileNotOpenException.hpp"

FileNotOpenException::FileNotOpenException(std::string probString):Exception("FILE",probString){
    mTag = "FILE"; 
    mProblem = probString;
}