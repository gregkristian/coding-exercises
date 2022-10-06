/* 
 * Code to multiply binary number, formated in string
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>

std::string addBinary(std::string a, std::string b) {
        std::size_t length = std::max(a.length(), b.length()) + 1;
                
        std::vector<int> aa(length, 0); //Vector with size=length and all 0
        std::vector<int> bb(length, 0);
        std::vector<int> carry(length, 0); // TODO remove this?
        std::vector<int> res(length, 0);
        
        //Change string to vector of int. TODO: change to vector bool
        int pos = length - 1;
        for (int i = a.size()-1; i >= 0; i--) {
            aa[pos] = (a[i] == '1');
            pos--;
        }
        pos = length - 1;

        for (int i = b.size()-1; i >= 0; i--) {
            bb[pos] = (b[i] == '1');
            pos--;
        }
        
        // Add
        for (int i = aa.size()-1; i >= 0; i--) {
            res[i] = !(!aa[i] != !bb[i]) != !carry[i];
            if (i>0) {
                carry[i-1] = ((!aa[i] != !bb[i]) && carry[i]) || (aa[i] && bb[i]);
            }
        }
        
        // Remove first bit if 0 (no carry)
        if (res[0] == 0) {
            res.erase(res.begin());
        }

        // Write to string*/
        std::stringstream ret_ss;
        for (auto n: res) {
            ret_ss << n;
        }
        return ret_ss.str();
    }

// Implementation of https://en.wikipedia.org/wiki/Binary_multiplier
// TODO avoid using string
std::string binary_multiplier(std::string &A, std::string &B) {
    std::string res = "";

    for (size_t i = B.length(); i != 0; i--) {
        if (B[i - 1] == '0') {
            A.append("0");
            continue;
        } else {
            res = addBinary(A, res);
            A.append("0");
        }
    }


    return res;
}

int main()
{
    std::string A = "1011";
    std::string B = "1110";
    
    std::string result = binary_multiplier(A, B);

    std::cout << "Result: " << result;
    
    return 0;
}