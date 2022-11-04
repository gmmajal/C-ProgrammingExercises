#ifndef FILENOTOPENEXCEPTIONHEADERDEF
#define FILENOTOPENEXCEPTIONHEADERDEF
#include "Exception.hpp"

class FileNotOpenException:public Exception{
    private:
        std::string mTag, mProblem;
    public:
        FileNotOpenException(std::string probString);
};

#endif