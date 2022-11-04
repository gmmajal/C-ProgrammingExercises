#include <iostream>
#include <new>

/*
 * Two delete statements have been added so any
 * potential user can safely play around with the 
 * size of the array, so even if it is not a bad 
 * allocation exception the memory is appropriately 
 * deallocated at the end of the program.
 */

int main(int argc, char* argv[]){
	double* p_x;
	try{
		p_x = new double[10000000000];	
	}catch(const std::bad_alloc& e){
		std::cout<<"Allocation failed "<<e.what()<<"\n";
		delete[] p_x;
	}
	delete[] p_x;
	return 0;
}
