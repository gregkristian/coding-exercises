/* Link https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].
We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:
  A[0] = 1
  A[1] = 5
  A[2] = 2
  A[3] = 1
  A[4] = 4
  A[5] = 0
  
There are eleven (unordered) pairs of discs that intersect, namely:
discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.

Write a function:
class Solution { public int solution(int[] A); }
that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.
Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:
N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].
*/

// Solution:
// Result: Task Score:75% Correctness:87% Performance:62%
// Complexity: O(N**2)

int solution(vector<int> &A) {
  // write your code in C++14 (g++ 6.2.0)
  int ret = 0;
  for (unsigned int i = 0; i < A.size(); i++) {
    for (unsigned int j = i + 1; j < A.size(); j++) {
      //cout << "comparing " << i << " and " << j << " -- ";
      //cout << int(j - A[j]) << " " << i + A[i] << " " << j + A[j];
      if (int(j - A[j]) <= int(i + A[i])) {
      //cout << " intersect";
      ++ret;
      }
    //cout << endl;
    }
  }
  return ret;
}
