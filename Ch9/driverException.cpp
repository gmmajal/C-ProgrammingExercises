#include "Exception.hpp"
#include "OutOfRangeException.hpp"
#include "FileNotOpenException.hpp"
#include <fstream>
#include <iostream>

void ReadFile(const std::string& fileName, double x[], double y[]){
    std::ifstream read_file(fileName.c_str());
    if (read_file.is_open() == false){
        throw (FileNotOpenException("File can't be read"));
    }
    for (int i=0; i<6; i++){
        read_file >> x[i] >> y[i];
    }
    read_file.close();
    std::cout << fileName <<" read successfully\n";
 }

void IncrementByOne(double x[]){
    for(int i=0;i<=6;++i){
            if(i<0 || i>5){
                throw(OutOfRangeException("Index is out of range"));
            }
            x[i] = x[i] + 1.0;
    }
}

int main(int argc, char* argv[]){
    double x[6],y[6];
    /* 
     * actual file name is taken to be testFile.txt.
     * The user of course is free to rename the file being 
     * read at the appropriate location.
    */
    std::string myFileName="File.txt"; 
    try{
        ReadFile(myFileName,x,y);
        IncrementByOne(x);
    }catch(Exception& e){
        e.PrintDebug(); 
        if(e.getMTag()=="FILE"){
            std::cout << "Couldn't open "<< myFileName<<"\n";
            std::cout << "Give alternative location below\n";
            std::string file_name;
            std::cin >> file_name;
            ReadFile(file_name, x, y);
            try{
                IncrementByOne(x);
            }catch(Exception & e1){
                std::cout<<"The index being accessed was out of range. Please check if the index value being accessed is in the integer range [0,5]\n";    
            }
        }else{
            std::cout<<"The index being accessed was out of range. Please check if the index value being accessed is in the integer range [0,5]\n";
            try{
                ReadFile(myFileName,x,y);
            }catch(Exception& e2){
                std::cout << "Couldn't open "<< myFileName<<"\n";
                std::cout << "Give alternative location below\n";
                std::string file_name;
                std::cin >> file_name;
                ReadFile(file_name, x, y);
            }
        }
    }
    return 0;
}