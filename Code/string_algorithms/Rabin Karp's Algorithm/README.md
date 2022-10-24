## Rabin Karp's Algorithm

### Problem Description
In this problem your goal is to implement the Rabin–Karp’s algorithm for searching the given pattern
in the given text.

### Input format
There are two strings in the input: the pattern 𝑃 and the text 𝑇.

### Output format
Print all the positions of the occurrences of 𝑃 in 𝑇 in the ascending order. Use 0-based
indexing of positions in the the text 𝑇.

### Sample input and output
1. 
> Input
```text
aba
abacaba
```
> Output
```text
0 4
```
2. 
> Input
```text
Test
testTesttesT
```
> Output
```text
4
```
3. 
> Input
```text
aaaaa
baaaaaaa
```
> Output
```text
1 2 3
```
### Implementation
1. Function named `pre_compute_hash` will help to precompute the hash value of all substring of length equals length of `pattern P` in O(n) time.
2. Now we need to iterate over each substring (of length equals length of `pattern P`) of `text T`. If the hash value of pattern and substring is equal then check if both strings are equal or not using `are_equal` function else there is no need to check for substring.
3. Store the index of matched substring and print it using function `print_occurrences`.

### Complexity

- Time Complexity :
    - Best Case : O(length of text T + length of pattern P)
    - Worst Case : O(length of text T * length of pattern P)
- Space Complexity : O(length of Text T)
  
### Improvements
- If you caluculate hash value of each substring of `text T` at step `2` itself instead of calculating in other function you can save auxiliary space. But for sake of understanding, it is implemented like that.