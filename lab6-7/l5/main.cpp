#include <QFileInfo>
#include <QTextStream>

int main(int argc, char *argv[]) {

  QTextStream out(stdout);

  // Размер файла

  if (argc != 2) {

    qWarning("Usage: file_size file");
    return 1;
  }

  QString filename = argv[1];

  if (!QFile(filename).exists()) {
    qWarning("The file does not exist");
    return 1;
  }

  QFileInfo fileinfo(filename);

  qint64 size = fileinfo.size();

  QString str = "The size is: %1 bytes";
  out << str.arg(size) << Qt::endl;

  return 0;
}
