// C++ program for implementation of KMP pattern searching algorithm
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void computeLPSArray(string pat, int M, vector<int> lps)
{
	// length of the previous longest prefix suffix
	int len = 0;
	lps[0] = 0; 

	int i = 1;
	while (i < M) 
    {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			// Consider the example AAACAAAA and i = 7. The idea is similar to search step.
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}


void KMPSearch(string str, string pat)
{
	int M = pat.length();
	int N = str.length();

	// lps will hold the longest prefix suffix values for pattern
    vector<int> lps(M);

    // Preprocess the pattern (calculate lps array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for str
	int j = 0; // index for pat
	while (i < N) 
    {
		if (pat[j] == str[i]) {
			j++;
			i++;
		}

		if (j == M) {
            cout << "Pattern found at index "<< i - j << endl;
            j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != str[i]) 
        {
			// Do not match lps[0..lps[j-1]] characters, they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}


signed main()
{
    string str, pat;
    // cin >> str >> pat;
    str = "ABABDABACDABABCABAB";
	pat = "ABABCABAB";
	KMPSearch(str, pat);
}
