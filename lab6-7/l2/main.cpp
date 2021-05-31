#include <QTextStream>

int main() {

  QTextStream out(stdout);
  QString     a = "Arg: %1";

  a.append(". That's it.");
  QString b = "Getting arg 5 - ";
  a.prepend(b.replace(12, 1, "1"));

  out << a << Qt::endl;

  out << "The a string has " << a.count() << " characters" << Qt::endl;

  out << a.toLower() << Qt::endl;

  a.clear();
  if (a.isEmpty()) {
    out << "The string is empty" << Qt::endl;
  }

  QString field1 = "Name: ";
  QString field2 = "Occupation: ";
  QString field3 = "Residence: ";
  QString field4 = "Marital status: ";

  // Вычисляем размер самой широкой строки
  int width = field4.size();

  out << field1.rightJustified(width, ' ') << "Robert\n";
  out << field2.rightJustified(width, ' ') << "programmer\n";
  out << field3.rightJustified(width, ' ') << "New York\n";
  out << field4.rightJustified(width, ' ') << "single\n";

  return 0;
}
