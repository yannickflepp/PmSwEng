#include <QApplication>
#include <QtWidgets>
#include "BerechnungRL.h"
#include "MainWindow.h"
#include "ui_BerechnungRL.h"

// Test

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);
  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
}
