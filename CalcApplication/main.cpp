#include "MainWindow.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  QDialog mainWindow;
  QVBoxLayout* mainLayout = new QVBoxLayout;
  mainWindow.setLayout(mainLayout);
  QLabel* label = new QLabel("Electronics Calculator");
  mainLayout->addWidget(label);
  QHBoxLayout* bottomLayout = new QHBoxLayout;
  mainLayout->addLayout(bottomLayout);
  QPushButton* calc1Button = new QPushButton("Calc_1");
  bottomLayout->addWidget(calc1Button);
  QPushButton* calc2Button = new QPushButton("Calc_2");
  bottomLayout->addWidget(calc2Button);
  QPushButton* calc3Button = new QPushButton("Calc_3");
  bottomLayout->addWidget(calc3Button);
  mainWindow.show();
  return app.exec();
}
