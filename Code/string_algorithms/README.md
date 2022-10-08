# String algorithms

## Manacher's Algorithm

### Statement:
`
Given string  with length n. Find all the pairs (i,j) such that substring s[i..j] is a palindrome. String  s is a palindrome when  reverse of s = oroginal string s.
`
### Implementation of Manacher's algorithm
For calculating , we get the following code. Things to note:

- i is the index of the center letter of the current palindrome.
- If i exceeds r, d1[i] is initialized to 0.
- If i does not exceed r, d1[i] is either initialized to the d1[j], where j is the mirror position of i in (l,r), or d1[i] is restricted to the size of the "outer" palindrome.
The while loop denotes the trivial algorithm. We launch it irrespective of the value of k.
If the size of palindrome centered at i is x, then d1[i] stores x+1/2.
 
### Time Complexity : O(n)

