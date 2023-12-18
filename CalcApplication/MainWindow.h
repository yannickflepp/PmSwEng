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

/**
 * @brief Die MainWindow Klasse
 */
class MainWindow : public QMainWindow
{
  Q_OBJECT

 public:
  /**
   * @brief MainWindow Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse MainWindow.
   *
   * @param parent Gull???
   */
  MainWindow(QWidget* parent = nullptr);

  /**
   * @brief ~MainWindow Destruktor
   *
   * Diese Methode löscht das erzeugte Objekt aus der Methode
   * MainWindow::MainWindow.
   */
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
