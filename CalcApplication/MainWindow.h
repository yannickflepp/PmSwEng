#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BerechnungRC.h"
#include "BerechnungRL.h"
#include "BerechnungRLC.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
  BerechnungRL berechnungRL;
  BerechnungRC berechnungRC;
  BerechnungRLC berechnungRLC;

 public slots:
  void onPbRLPressed()
  {
    berechnungRL.show();
  }
  void onPbRCPressed()
  {
    berechnungRC.show();
  }
  void onPbRLCPressed()
  {
    berechnungRLC.show();
  }

 private:
  Ui::MainWindow* ui;
};
#endif  // MAINWINDOW_H
