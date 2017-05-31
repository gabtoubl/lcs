#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int tag = 0;

void printSubSequences(vector<vector<int> > &table, string &x, string &y,
                       size_t i, size_t j, string z, string z2) {
  size_t m = x.length() + 1, n = y.length() + 1;
  if (i != 0 && j != 0 && x[i-1] == y[j-1])
    printSubSequences(table, x, y, i-1, j-1, x[i-1]+z, x[i-1]+z2);
  else if (i != 0 && table[j][i-1] == table[j][i])
    printSubSequences(table, x, y, i-1, j, (m > n ? '_' + z : z), z2);
  else if (j != 0 && table[j-1][i] == table[j][i])
    printSubSequences(table, x, y, i, j-1, (n > m ? '_' + z : z), z2);
  if (i == 0 && j == 0) {
    cout << ">" << ++tag << endl;
    cout << z2 << endl;
  }
}

void findSubSequences(string x, string y) {
  size_t m = x.length() + 1, n = y.length() + 1;
  vector<vector<int> > table(n);

  for (size_t i = 0; i < m; ++i)
    table[0].push_back(0);
  for (size_t j = 1; j < n; ++j) {
    table[j].push_back(0);
    for (size_t i = 1; i < m; ++i) {
      if (x[i-1] == y[j-1])
        table[j].push_back(table[j-1][i-1]+1);
      else
        table[j].push_back(max(table[j][i-1], table[j-1][i]));
    }
  }
  printSubSequences(table, x, y, m-1, n-1, "", "");
}

int main(int ac, char **av) {
  ifstream file;
  vector<string> content;
  string line;

  if (ac != 2)
    return 1;
  file.open(av[1]);
  if (!file.is_open())
    return 1;
  while (getline(file, line)) {
    getline(file, line);
    content.push_back(line);
  }
  for (size_t i = 0; i < content.size(); ++i) {
    for (size_t j = i + 1; j < content.size(); ++j) {
      if (i != j)
	findSubSequences(content[i], content[j]);
    }
  }
  file.close();
  return 0;
}
