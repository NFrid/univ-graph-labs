#include <iostream>

using namespace std;

double getDouble() {
  cout << "Enter a double value: ";
  double d;
  cin >> d;
  return d;
}

char getOp() {
  cout << "Enter one of the following: +, -, *, or /: ";
  char op;
  cin >> op;
  return op;
}

void printRes(double x, char op, double y) {
  double res;
  switch(op) {
    case '+':
      res = x + y;
      break;
    case '-':
      res = x - y;
      break;
    case '*':
      res = x * y;
      break;
    case '/':
      res = x / y;
      break;

    default:
      return;
  }
    printf("%f %c %f = %f\n", x, op, y, res);
}

int main() {
  double x = getDouble();
  double y = getDouble();
  char op = getOp();

  printRes(x, op, y);
  
  return 0;
}
