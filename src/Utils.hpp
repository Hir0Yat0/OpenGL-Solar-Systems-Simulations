#ifndef UTILS_HPP
#define UTILS_HPP

#include<iostream>
#include<vector>

#include "Vec3D.hpp"

namespace Utils
{
    
#define DBGEXPR(EXPR) {std::cerr << #EXPR << ": " << EXPR << "\n";}
#define DBGEXPROUT(EXPR) {std::cout << #EXPR << ": " << EXPR << "\n";}

template<class T>
inline void printVector(const std::vector<T> & vec){
    std::cout << "[";
    for (const auto &data : vec){
        std::cout << data << ", ";
    }
    std::cout << "]\n";
}
template<class T>
inline void printVectorErr(const std::vector<T> & vec){
    std::cerr << "[";
    for (const auto &data : vec){
        std::cerr << data << ", ";
    }
    std::cerr << "]\n";
}

}; // namespace Utils


#endif // UTILS_HPP
