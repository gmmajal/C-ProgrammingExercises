#include <iostream>

int main(int argc, char *argv[]){
    int carArray[5]={34, 58, 57, 32, 43};
    double avg = (double)(carArray[0]+carArray[1]+carArray[2]+carArray[3]+carArray[4])/5;
    std::cout<<"The average for the five days is: "<<avg;
    return 0;
}