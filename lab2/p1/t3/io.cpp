#include <iostream>

using namespace std;

int readNumber() {
  cout << "Enter a number: ";
  int num;
  cin >> num;
  return num;
}

void writeAnswer(int ans) {
  cout << "Ans: " << ans << endl;
}
