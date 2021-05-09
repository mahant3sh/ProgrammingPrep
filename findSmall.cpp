/* Design an API, "findSmall", for any range-based data set. 
 * CLI>$ g++ --std=c++11 findSmall.cpp 
 * CLI>$ ./a.out
 *  Smallest is 5
 *  Smallest in array is 1
 *  Smallest in the set is 222
 *  Smallest in char set is m
 * CLI>$  
 */
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <list>
using namespace std;

template<typename Iterator, typename T>
bool findSmall(Iterator begin, Iterator end, T &minVal){
    if (begin == end){
        return false;
    }
    minVal = *begin;
    for (auto it = begin; it != end; it++){
        if (*it < minVal){
            minVal = *it;
        }
    }
    return true;
}

int main() 
{
    // Use the API for vector
    std::vector<int> ivec {23, 12, 5, 34, 76, 87};
    int minVal;
    bool ret = false;
    ret = findSmall(ivec.begin(), ivec.end(), minVal);
    if (!ret) {
        cout << "Range is empty" << endl;
    }
    cout << "Smallest is " << minVal << endl;

    // Use the same API for array
    std::array<int, 5> arr {343, 1, 32, 6, 7};
    ret = findSmall(arr.begin(), arr.end(), minVal);
    cout << "Smallest in array is "<< minVal << endl;

    // Use the same API for set
    std::set<int> sset = {345, 567, 887, 222, 909};
    ret = findSmall(sset.begin(), sset.end(), minVal);
    cout << "Smallest in the set is " << minVal << endl;

    // Use the same API for chars
    std::list<char> clist = {'z', 'x', 'u', 'm', 'n'};
    char minChar;
    ret = findSmall(clist.begin(), clist.end(), minChar);
    cout << "Smallest in char set is " << minChar << endl;
    return 0;
    
}
