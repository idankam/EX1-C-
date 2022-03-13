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

        int rows = mat_breadth, cols = mat_length;
        char** matrix = new char*[rows];
        for (int i = 0; i < rows; ++i)
            matrix[i] = new char[cols];
        
        char symbol = symbole_1;
        int first_row = 0, last_row = rows-1, first_col = 0, last_col = cols-1;

        while (first_row <= last_row && first_col <= last_col)
        {
            // fill up and down rows
            for (int i = first_col; i <= last_col; i++)
            {
                matrix[first_row][i] = symbol;
            }
            for (int i = first_col; i <= last_col; i++)
            {
                matrix[last_row][i] = symbol;
            }

            // fill left and right rows
            for (int i = first_row+1; i <= last_row-1; i++)
            {
                matrix[i][first_col] = symbol;
            }
            for (int i = first_row+1; i <= last_row-1; i++)
            {
                matrix[i][last_col] = symbol;
            }

            // update values for next iteration
            first_row++; last_row--; first_col++; last_col--;
            if (symbole_1 == symbol) symbol = symbole_2;
            else symbol = symbole_1;
            
        }
        
        std:string answer = "";

        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                answer += matrix[i][j];
            }
            answer += "\n";
        }

        for (int i = 0; i < rows; ++i)
            delete [] matrix[i];
        delete [] matrix;

        return answer;
    };
};