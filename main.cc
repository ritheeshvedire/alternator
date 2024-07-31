#include <iostream>
#include <vector>
#include <set>
#include "alternator.h"

int main() {
    std::vector<std::string> vec1 = {"vec1", "vec2", "vec3", "vec4"};
    std::set<std::string> set1 = {"s1", "s2", "s3"};

    // instantiate alternator class
    alternator<std::vector<std::string>, std::set<std::string>> alt(vec1, set1);

    for (auto it = alt.begin(); it!= alt.end() ; ++it){

        std::cout << *it <<", ";
    }
    std::cout<<std::endl;

}