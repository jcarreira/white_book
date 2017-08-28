#include <string>
#include <vector>
#include <iostream>

std::vector<int> compute_prefix(const std::string& p) {
   int m = p.size();

   std::vector<int> pi(m);
   int k = 0;

   pi[0] = 0;
   for (int q = 1; q < m; q++) {
      while(k > 0 && p[k] != p[q])
         k = pi[k - 1];
      if (p[k] == p[q])
         k++;
      pi[q] = k;
   }
   return pi;
}

void kmp_match(const std::string& s, const std::string& p) {
   std::vector<int> pi = compute_prefix(p);
   int q = 0;
   int n = s.size();
   int m = p.size();

   for(int i = 0; i < n; i++) {
      while (q > 0 && p[q] != s[i])
         q = pi[q - 1];
      if (p[q] == s[i])
         q++;
      if (q == m) {
         std::cout << "Match pos "
            << (i - m + 1)
            << std::endl;
      }
   }
}

int main() {
   std::string s = "catdigdogcatdocatdog";

   kmp_match(s, "cat");

   return 0;
}
