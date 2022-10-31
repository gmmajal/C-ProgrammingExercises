#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

void appendKeyToVec(std::vector<std::string>& v, std::map<std::string, int>m){
    for (const auto& item: m){
        v.push_back(item.first);
    }
}

void appendNumberToVec(std::vector<int>&v, std::map<std::string,int>m){
	for(const auto& item: m){
		v.push_back(item.second);
	}
}

int main(int argc, char* argv[]){
    std::map<std::string, int> pB1 = {{"John Doe",123567},{"Xi Phi",591806},{"Alpha Gamma",794610}};
    std::map<std::string, int> pB2 = {{"Chi Pi",123568},{"Eta Zeta",123568},{"Beta Theta",894610},{"Mu Nu",123568},{"Epsilon Psi",894610}};
    std::map<std::string, std::tuple<int, std::string>>pB3 = {{"Sigma Tau",std::make_tuple(290156,"sigt@gmail.com")},{"Delta Omicron",std::make_tuple(331470,"variant@gmail.com")}};
    std::multimap<int,std::string> rpB2;
    
    std::cout<<"Printing via range based for loop\n";
    for (const auto& entry  : pB1){
        std::cout<<"[ "<<entry.first<<", "<<entry.second<<" ]\n";
    }
    std::cout<<"\n Printing via for_each\n";
    auto item = [](const std::pair<const std::string,int> &entry){std::cout<<"[ "<<entry.first<<", "<<entry.second<<" ]"<<"\n";};
    std::for_each(pB1.begin(),pB1.end(),item);
    
    std::cout<<"\nCopying all strings to a vector\n";
    std::vector <std::string> vec1;
    std::vector<int> vec2;
    appendKeyToVec(vec1, pB1);
    std::cout<<"Entries inside the vector "<<"\n";
    for (const auto& entry: vec1){
            std::cout<< entry <<"\n";
    }
    std::cout<<"\nFinding duplicates entries in the phonebook\n";
    std::set<int> s;
    appendNumberToVec(vec2,pB2);
    int j=0;
    int count = 0;
    for(auto i:vec2){ 
    	auto elem = s.insert(i);
	if(!elem.second){
		std::cout<<"Vector element at index "<<j<<" is a duplicate entry\n";
		++count;	
	}
	++j;
    }
    std::cout<<"In total there were "<<count<<" duplicate entries in the vector\n";
    std::cout<<"\n The reverse map will look as follows \n";
    for (const auto& i : pB2){
    	rpB2.insert( std::pair<int,std::string>(i.second,i.first));
    }
    for (const auto& i : rpB2){
	    std::cout<<"[ "<<i.first<<", "<<i.second<<"]\n";
    }
    std::cout<<"\n Printing map with name, phone number and email\n";
    for(const auto entry:pB3){
	    std::cout<<"[ "<<entry.first<<", "<<std::get<0>(entry.second)<<", "<<std::get<1>(entry.second)<<" ]\n";
    }
    
    return 0;
}
