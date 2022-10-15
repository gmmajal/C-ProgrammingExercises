#include <iostream>
#include <cassert>

int main(int argc, char* argv[]){
    int num;
    int sum=0;
    while(num!=-1){
        std::cout << "Enter your integer, then hit RETURN\n. Note that if you want to stop then enter -1 and hit RETURN\n. If you want to reset the sum type -2 and hit RETURN\n";
        std::cin >> num;
        if (num==-2){
            sum=0.0;
        }else if(num==-1){
            break;
        }
        else{
            sum+=num;
            assert(sum<100);
        }
    }
    std::cout<<"The sum of the entered numbers is "<<sum;
    
    return 0;
}