#include "statusbar.h"
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QStatusBar>

Statusbar::Statusbar(QWidget* parent)
    : QMainWindow(parent) {

  QFrame* frame = new QFrame(this);
  setCentralWidget(frame);

  QHBoxLayout* hbox = new QHBoxLayout(frame);

  okBtn = new QPushButton("OK", frame);
  hbox->addWidget(okBtn, 0, Qt::AlignLeft | Qt::AlignTop);

  aplBtn = new QPushButton("Apply", frame);
  hbox->addWidget(aplBtn, 1, Qt::AlignLeft | Qt::AlignTop);

  statusBar();

  connect(okBtn, &QPushButton::clicked, this, &Statusbar::OnOkPressed);
  connect(aplBtn, &QPushButton::clicked, this, &Statusbar::OnApplyPressed);
}

void Statusbar::OnOkPressed() {
  statusBar()->showMessage("OK button pressed", 2000);
}

void Statusbar::OnApplyPressed() {
  statusBar()->showMessage("Apply button pressed", 2000);
}
