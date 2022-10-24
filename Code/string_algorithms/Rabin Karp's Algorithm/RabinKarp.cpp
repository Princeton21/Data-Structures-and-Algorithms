#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

// Reading the input
Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

// Function used to hash the substring
size_t hash_func(const string& s, int start, int end, ull p, int x) {
    ull hash = 0;
    for (int i = end; i >= start; --i){
        hash = ((hash * x) + s[i]) % p;
    }
    return hash;
}

// Program to check if two strings are equal or not
bool are_equal(const string& s, const string& t, int start, int end){
    if(s.size() != end-start+1){
        return false;
    }

    for(size_t i = 0; i<s.size(); i++){
        if(s.at(i) != t.at(i+start)){
            return false;
        }
    }
    return true;
}

// Program to compute hash value of string
vector<ull> pre_compute_hash(const string& T, int phraseLength, ull prime, int x){
    vector<ull> hash(T.size() - phraseLength + 1);
    
    hash[T.size() - phraseLength] = hash_func(T, T.size() - phraseLength, T.size()-1, prime, x);


    int y = 1;
    for(size_t i=1; i<= phraseLength; i++){
        y = (y * x) % prime;
    }
    for(size_t i = T.size()-phraseLength-1; i!=-1; i--){
        hash[i] = (x * hash[i+1] + T[i] - y * T[i+phraseLength] ) % prime;
    }

    return hash;
}

// Program to print all the occurences of matched string
void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

// Program to get all the occurences
vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    static const size_t x = 1;
    static const ull prime = 1000000007;
    vector<int> ans;

    ull pHash = hash_func(s, 0, s.size()-1, prime, x);

    vector<ull> hash = pre_compute_hash(t, s.size(), prime, x);

    for(size_t i = 0; i<=t.size()- s.size(); i++){
        if(pHash != hash[i]){
            continue;
        }
        if(are_equal(s, t, i, i+ s.size()-1)){
            ans.push_back(i);
        }
    }

    return ans;
}

// Main function
int main() {
    ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
