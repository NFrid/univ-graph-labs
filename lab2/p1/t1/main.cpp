#include <iostream>
#include <string.h>

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

int main(int argc, char *argv[]) {
  if (argc > 1) {
    if (!strcmp(argv[1], "-h"))
      printf("The basic summator. Enter 2 numbers or execute it without any args to enter 'interactive shell'.\n");
    else {
      writeAnswer(atoi(argv[1]) + atoi(argv[2]));
    }
    return 0;
  }

  int x = readNumber();
  int y = readNumber();
  writeAnswer(x + y);
  return 0;
}
