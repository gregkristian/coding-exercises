/*
 * Problem Description
 *
 * Write a function int solution(vector<int> &A);
 * that, given an array A consisting of N integers, returns the number of distinct values in array A.
 * 
 * For example, given array A consisting of six elements such that:
 * A[0] = 2    A[1] = 1    A[2] = 1
 * A[3] = 2    A[4] = 3    A[5] = 1
 * the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
 * 
 * Write an efficient algorithm for the following assumptions:
 * N is an integer within the range [0..100,000];
 * each element of array A is an integer within the range [−1,000,000..1,000,000].
 */

// Result: Correctness 100%, Performance 100%. Overall 100%
#include <bitset>
#include <cstddef>

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)

    const int abs_index = 1000 * 1000;
    const std::size_t bs_size = 1 + (abs_index * 2); // Value range [-1,000,000..1,000,000]

    std::bitset<bs_size> bs;

    for (auto a : A)
    {
        bs[a + abs_index] = true; // NOTE: Careful since value starts from -1,000,000
    }

    return bs.count();
}