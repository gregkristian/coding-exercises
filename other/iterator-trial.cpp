#include <iostream>
#include <vector>

/* Iterator trial
*/

using namespace std;

void print_element(vector<int>::iterator input) {
    cout << "print_element " << *input << endl;
}

int main()
{
    std::vector<int> aaa = {0,1,2,3,4,5,6,7};
    vector<int>::iterator pointer_to_element = aaa.begin() + 2;
    
    print_element(pointer_to_element);
    
    aaa.insert(aaa.end(), 8);
    aaa.insert(aaa.end(), 9);
    aaa.insert(aaa.begin(), -1);
    aaa.insert(aaa.begin(), -2);

    cout << "aaa[2] " << aaa[2] << endl;
    print_element(pointer_to_element);
    print_element(aaa.begin() + 4);
    
    return 0;
}