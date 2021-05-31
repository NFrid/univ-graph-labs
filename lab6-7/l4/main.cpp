#include <QList>
#include <QSet>
#include <QTextStream>
#include <algorithm>

int main() {

  QTextStream out(stdout);

  // Контейнер QVector

  QVector<int> vals = { 1, 2, 3, 4, 5 };

  out << "The size of the vector is: " << vals.size() << Qt::endl;

  out << "The first item is: " << vals.first() << Qt::endl;
  out << "The last item is: " << vals.last() << Qt::endl;

  vals.append(6);
  vals.prepend(0);

  out << "Elements: ";

  for (int val : vals) {
    out << val << " ";
  }

  // Контейнер QList

  QList<QString> authors = { "Balzac", "Tolstoy",
    "Gulbranssen", "London" };

  for (int i = 0; i < authors.size(); ++i) {

    out << authors.at(i) << Qt::endl;
  }

  authors << "Galsworthy"
          << "Sienkiewicz";

  out << "***********************" << Qt::endl;

  std::sort(authors.begin(), authors.end());

  out << "Sorted:" << Qt::endl;
  for (QString author : authors) {

    out << author << Qt::endl;
  }

  // Контейнер QStringList

  QString string = "coin, book, cup, pencil, clock, bookmark";

  QStringList itms = string.split(",");

  QStringListIterator it(itms);

  while (it.hasNext()) {
    out << it.next().trimmed() << Qt::endl;
  }

  // Контейнер QSet

  QSet<QString> cols1 = { "yellow", "red", "blue" };
  QSet<QString> cols2 = { "blue", "pink", "orange" };

  out << "There are " << cols1.size() << " values in the set" << Qt::endl;

  cols1.insert("brown");

  out << "There are " << cols1.size() << " values in the set" << Qt::endl;

  cols1.unite(cols2);

  out << "There are " << cols1.size() << " values in the set" << Qt::endl;

  for (QString val : cols1) {
    out << val << Qt::endl;
  }

  QList<QString> lcols = cols1.values();
  std::sort(lcols.begin(), lcols.end());

  out << "*********************" << Qt::endl;
  out << "Sorted:" << Qt::endl;

  for (QString val : lcols) {
    out << val << Qt::endl;
  }

  // Контейнер QMap

  QMap<QString, int> items = { { "coins", 5 }, { "books", 3 } };

  items.insert("bottles", 7);

  QList<int> values = items.values();
  out << "Values:" << Qt::endl;
  for (int val : values) {
    out << val << Qt::endl;
  }

  QList<QString> keys = items.keys();
  out << "Keys:" << Qt::endl;
  for (QString key : keys) {
    out << key << Qt::endl;
  }

  QMapIterator<QString, int> ite(items);

  out << "Pairs:" << Qt::endl;

  while (ite.hasNext()) {
    ite.next();
    out << ite.key() << ": " << ite.value() << Qt::endl;
  }

  return 0;
}
