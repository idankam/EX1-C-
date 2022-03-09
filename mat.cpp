#include<iostream>
#include<string>
#include"mat.hpp"

using namespace std;

namespace ariel { 
    std::string mat(int mat_length, int mat_breadth, char symbole_1, char symbole_2){

        if(mat_length < 1 || mat_breadth < 1){
            throw std::invalid_argument("length / breadth must be at least 1.");
        }

        if(mat_length%2 == 0 || mat_breadth%2 == 0){
            throw std::invalid_argument("length / breadth odd.");
        }

        if(symbole_1 == ' ' || symbole_1 == '\t' || symbole_1 == '\n' || symbole_1 == '\r'){
            throw std::invalid_argument("Illegal input at symbol 1, can't be a space or something similar.");
        }
        
        if(symbole_2 == ' ' || symbole_2 == '\t' || symbole_2 == '\n' || symbole_2 == '\r'){
            throw std::invalid_argument("Illegal input at symbol 2, can't be a space or something similar.");
        }

        return "not implemented yet";
    };
};