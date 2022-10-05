/* Problem description:
An integer N is given. Transform it to the biggest number possible when one '5' in the decimal representation 
of N has been removed. Write a solution:

int solution (int N);

N cointains at least one '5'.
N is built up by at least two decimal numbers.

Example:
-500; 0 is the biggest possible number
1539; 139 is the biggest possible number
1535; 153 is the biggest possible number 
*/

#include <string>
#include <iostream>

int solution(int N)
{
    std::string const S = std::to_string(N);   
    int ret = INT32_MIN;
    for (auto i = S.length() - 1; i != 0; i--) { // NOTE: size_t is unsigned, i >= 0 is always true
        if (S[i] == '5') {
            std::string temp = S;
            temp.erase(i, 1);
            int temp_int = std::stoi(temp);
            ret = temp_int > ret ? temp_int : ret;
        }
    }
    return ret;
}

int main (void)
{  
    std::cout << "input: -500. result: " << solution(-500) << std::endl; 
    std::cout << "input: -515. result: " << solution(-515) << std::endl; 
    std::cout << "input: 1539. result: " << solution(1539) << std::endl; 
    std::cout << "input: 1535. result: " << solution(1535) << std::endl; 
    return 0;
}