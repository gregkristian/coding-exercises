/* Description
Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        size_t length = max(a.length(), b.length()) + 1;
                
        vector<int> aa(length, 0); //Vector with size=length and all 0
        vector<int> bb(length, 0);
        vector<int> carry(length, 0); // TODO remove this?
        vector<int> res(length, 0);
        
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
        
        // PRINTOUTS
        // Define lambda fun to print
        /*
        auto print = [](const int& n) { std::cout << " " << n; };
        
        cout << endl << "carry ";
        for_each(carry.cbegin(), carry.cend(), print); // const --> const
        cout << endl << "aa    ";
        for_each(aa.cbegin(), aa.cend(), print);
        cout << endl << "bb    ";       
        for_each(bb.cbegin(), bb.cend(), print);
        cout << endl << "res   ";
        for_each(res.cbegin(), res.cend(), print);
        
        // Lambda and for_each above is basically similar as:
        // for (auto i: res) {
        //    cout << i << " ";
        // }

        // Write to string*/
        std::stringstream ret_ss;
        for (auto n: res) {
            ret_ss << n;
        }
        return ret_ss.str();
    }
};