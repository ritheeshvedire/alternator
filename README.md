# Alternator iterator
Short C++ program to implemennt an "alternator" class that takes as input - two containers ( with each supporting a forward iterator) and alternatively returns an element for each container.

## Usage
```
std::vector<std::string> vec1 = {"vec1", "vec2", "vec3", "vec4"};
std::set<std::string> set1 = {"s1", "s2", "s3"};

    
alternator<std::vector<std::string>, std::set<std::string>> alt(vec1, set1);

for (auto it = alt.begin(); it!= alt.end() ; ++it){

     std::cout << *it <<std::endl;
}
```

## how to run
change the example in main.cc and do the below:
```
clang++ -std=c++20 main.cc -o test_alternator
```


## TODO
Currently, only Containers supporting the same datatype are supported.
alternator supporting any container (that has forward iteraor) and each with a dfferent datatype would be cool.