#include <string>
#include <iostream>
#include <cstdint>

/**
  * Computes kth (0 to s.size()! - 1) permutation
  * of string s
  */
std::string nth_permutation(uint64_t k, const std::string &s) {
    uint64_t factorial = 1;
    for (uint64_t i = 1; i <= s.size(); ++i) {
        factorial *= i;
    }

    std::string s_copy = s;
    std::string res;
    for (uint64_t j = 0; j < s.size(); ++j) {
        // compute how many permutations on the rest
        // of the string s[j + 1 .. s.size() - 1]
        factorial /= s.size() - j;
       
        // store character 
        uint64_t l = k / factorial;
        res += s_copy[l];

        // remove already used character
        s_copy.erase(s_copy.begin() + l);

        // compute new value of k
        k = k % factorial;
    }

    return res;
}

int main() {
    std::string s = "abc";
    uint64_t fact = 1;
    for (uint64_t i = 1; i <= s.size(); ++i) {
        fact *= i;
    }
    for (uint64_t i = 0; i < fact; ++i) {
        std::cout << i << " " << nth_permutation(i, s) << std::endl;
    }
    return 0;
}
