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
 *
 * Diese Klasse erzeugt Objekte der drei Unterklassen BerechnungRC, BerechnungRL
 * und BerechnungRLC beim Aufruf der jeweiligen Objekte.
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
   * @param parent Pointervariable
   */
  MainWindow(QWidget* parent = nullptr);

  /**
   * @brief ~MainWindow Destruktor
   *
   * Diese Methode ist der Standard Destruktor und löscht das erzeugte Objekt
   * der Methode MainWindow::MainWindow.
   */
  ~MainWindow();

  /**
   * @brief berechnungRL Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRL.
   */
  BerechnungRL berechnungRL;

  /**
   * @brief berechnungRC Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRC.
   */
  BerechnungRC berechnungRC;

  /**
   * @brief berechnungRLC Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRLC.
   */
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
