#include <iostream>
#include <fstream>

int main(int argc, char* argv[]){
    std::ifstream read_file("x_and_y.dat");
    if (!read_file.is_open()){
        return 1;
    }
   
    int number_of_rows = 0;
    double dummy1, dummy2, dummy3, dummy4;
    while(!read_file.eof()){
        
        read_file >> dummy1 >> dummy2;
        read_file >> dummy3 >> dummy4;
        if(read_file.eof()){
            break;
        }
        number_of_rows++;
        bool chk = read_file.fail();
        std::cout<<"The value of the fail bit is "<<chk<<"\n";
    }
    std::cout << "Number of rows = "<< number_of_rows << "\n";
    read_file.close();
    return 0;
}