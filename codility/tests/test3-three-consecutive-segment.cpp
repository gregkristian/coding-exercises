/**
 * Problem description:
 * There is a road with holes in it. The road is represented as string S. The index in the string represents road segments. Each road segment is either ok, represented by '.',
 * or needs fixing, represented by 'X'. The road fixing tool fixes three consecutive segments during one operation. What is the minimum number of operations needed to fix the road? 
 * 
 * Write a solution;
 * int solution (string &S);
 * 
 * Example:
 * S = "XXXX" - 2 operations are needed (Ex., the first operation fixes index 0, 1, 2, the second index 3)
 * S = "X.X.X...X" - 3 operations are needed (Ex., the first opertion fixes index 0, 1, 2, the second index 3, 4, 5, the third 6, 7, 8)
 */

#include <string>
#include <iostream>
#include <vector>

int solution(std::string &S)
{
    int idx = 0, ret = 0;
    while (idx < S.length()) { // Iterator may not be used since it's incrementing by 3. Risk of undef behavior past S.end()
        if (S[idx] == 'X') {
            ++ret;
            idx += 3;
        } else {
            ++idx;
        }
    }

    return ret;
}

int main (void)
{  
    std::vector<std::string> inputs = {"XXXX", "X.X.X...X"};
    std::cout << "input: XXXX result: " << solution(inputs[0]) << std::endl; 
    std::cout << "input: X.X.X...X result: " << solution(inputs[1]) << std::endl; 

    return 0;
}