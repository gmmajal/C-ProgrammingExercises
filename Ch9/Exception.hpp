#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF
#include <string>

class Exception{
    private:
        std::string mTag, mProblem;
    public:
        Exception(std::string tagString, std::string probString);

        //getter methods added in order to distinguish exceptions in the driver code
        std::string getMTag(); 
        std::string getMProblem();
        void PrintDebug() const;
};
#endif //EXCEPTIONDEF
