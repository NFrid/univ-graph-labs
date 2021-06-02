#include <QApplication>
#include <QFrame>
#include <QGridLayout>
#include <QIcon>
#include <QPushButton>
#include <QWidget>

class Cursors : public QWidget {

  public:
  Cursors(QWidget* parent = 0);
};

Cursors::Cursors(QWidget* parent)
    : QWidget(parent) {

  QFrame* frame1 = new QFrame(this);
  frame1->setFrameStyle(QFrame::Box);
  frame1->setCursor(Qt::SizeAllCursor);

  QFrame* frame2 = new QFrame(this);
  frame2->setFrameStyle(QFrame::Box);
  frame2->setCursor(Qt::WaitCursor);

  QFrame* frame3 = new QFrame(this);
  frame3->setFrameStyle(QFrame::Box);
  frame3->setCursor(Qt::PointingHandCursor);

  QGridLayout* grid = new QGridLayout(this);
  grid->addWidget(frame1, 0, 0);
  grid->addWidget(frame2, 0, 1);
  grid->addWidget(frame3, 0, 2);

  setLayout(grid);
}

class MyButton : public Cursors {

  public:
  MyButton(QWidget* parent = 0);
};

MyButton::MyButton(QWidget* parent)
    : Cursors(parent) {

  QPushButton* quitBtn = new QPushButton("Quit", this); // создаем новую кнопку
  quitBtn->setGeometry(50, 40, 75, 30);                 // изменяем размеры кнопки в пикселях и помещаем на форму окна

  connect(quitBtn, &QPushButton::clicked, qApp, &QApplication::quit);
}

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  MyButton window;

  window.resize(250, 150);
  window.move(300, 300);
  window.setWindowTitle("Lesson 6");
  window.setWindowIcon(QIcon("icon.png"));

  window.setToolTip("QWidget");

  window.show();

  return app.exec();
}
