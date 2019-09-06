/* Lab_1:  maxarray
 * File:   maxarray.cpp
 * Author: Arman Belyalov
 * Class:  COSC-2436-005, T/Th 9:00
 * Created on August 29, 2019, 9:23 PM 
 */

#include <iostream>
#include <vector>
using namespace std;


/*******************************************************************************
 * This template function recursively defines the largest value in a provided  *
 *                   vector of integers, doubles and chars.                    *
 ******************************************************************************/
template <typename ElementType>
ElementType maxArray(const vector <ElementType> &paramArray, int first, int last) {
    int size = paramArray.size();    
    int middle = (first + last) / 2;    
    
    if (size == 1) return paramArray[0]; // Base case that returns the single value remaining after the recursive calls.
    else if (first > last) return -1; // Returns -1 if all the values are equal.
    else {
        int rightSideSize = size - middle; // Size of the right half of the splitted array.
        int leftSideSize = size - rightSideSize; // The same indicator about the left half.
        vector <ElementType> rightSide(rightSideSize); // Temporary vector that keeps the right half of the splitted original array.
        vector <ElementType> leftSide(leftSideSize); // The same but the left side.
        
        // This loop copies values from the original container to the temporary
        // vector that holds the values from the right side:
        for (int i=0; i<rightSideSize; i++){
            rightSide[i] = paramArray[middle];
            middle++;            
        }
        // This loop similarly copies the values from the left side:
        for (int i=0; i<leftSideSize; i++){
            leftSide[i] = paramArray[i];
        }
        
        return max(maxArray(leftSide, first, leftSideSize),\
                maxArray(rightSide, first, rightSideSize));
    }
}

template <typename ElementType>
void displayVectorContent(const vector<ElementType> &paramVector){
    for (int i=0; i<paramVector.size(); i++){
        if (i == paramVector.size()-1){
            cout << paramVector[i] << endl;
        } else {
            cout << paramVector[i] << ", ";
        }
    }
}

/*******************************************************************************
 *                                  MAIN                                       *
 ******************************************************************************/
int main(int argc, char* argv[]) {
    
    // Testing block for ints:
    vector <int> num { 10, 15, 65, 4, 88, 93, 6 };
    int vectorSize = num.size();
    int start = 0,
        end = vectorSize-1;
    cout << "Ints Vector Content: ";
    displayVectorContent(num);
    cout << "Max Int Value: " <<  maxArray(num, start, end) << endl;
    
    // Testing block for doubles:
    vector <double> doubles {55.3, 12.6, 17.4, 36.6, 28.55, 64.08};
    vectorSize = doubles.size(); 
    end = vectorSize-1;
    cout << "\nDoubles Vector Content: ";
    displayVectorContent(doubles);
    cout << "Max Double Value: " <<  maxArray(doubles, start, end) << endl;
        
    // Testing block for chars:
    vector <char> chars { 'a', 'b', 'h', 'A', 'K', 'R'}; 
    vectorSize = chars.size(); 
    end = vectorSize-1;
    cout << "\nChars Vector Content: ";
    displayVectorContent(chars);
    cout << "Max Char Value: " <<  maxArray(chars, start, end) << endl;
    
    return 0;
}
