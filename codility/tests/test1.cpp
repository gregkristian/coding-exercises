/* Problem desription:
Take two integers as input, return the number of bits set to one in the product of the two integers.
Write a solution: int solution (int A, int B);

Example: A = 3, B = 7
Answer is 3 (3*7=21, and is written in binary; "1 0 1 0 1". Three bits are set to '1').
*/

#include <iostream>
#include <algorithm>
#include <bit>

int solution(int A, int B)
{
    unsigned int C = A*B;
    return std::popcount(C); //C++ 20
}

int main (void)
{
    std::cout << solution(100000000, 100000000) << std::endl; // Expect 3
    std::cout << solution(20, 31) << std::endl; // Expect 3
    return 0;
}