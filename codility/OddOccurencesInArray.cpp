/* Problem:

A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired 
with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:
 A[0] = 9 A[1] = 3 A[2] = 9 A[3] = 3 A[4] = 9 A[5] = 7 A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.

Write a function:
int solution(vector<int> &A);
that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
For example, given array A above, the function should return 7.

Write an efficient algorithm for the following assumptions:
N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.

Copyright 2009–2022 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.*/

/* Solution:
Use XOR to extract the single element/number that doesn't have pair. The other pair will return 0 when XOR'ed
*/

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  auto it = A.begin() + 1;
  int res = *(it - 1);
  while (it != A.end()) {
  res = res ^ *it;
  ++it;
  }
  return res;
}
