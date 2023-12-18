#ifndef ERROR_H
#define ERROR_H

#include <QMainWindow>
#include <QWidget>
#include "ui_Error.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class Error;
}
QT_END_NAMESPACE

/**
 * @brief Die Error Klasse
 *
 * Diese Klasse
 */
class Error : public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief Error Konstrukteur
   *
   * Diese Methode erzeugt ein Objekt der Klasse Error.
   *
   * @param parent Gull???
   */
  Error(QWidget* parent = nullptr);

  /**
   * @brief ~BerechnungRC Destrukteur
   *
   * Diese Methode löscht das erzeugte Objekt aus der Methode Error.
   */
  ~Error();

 private:
  Ui::Error* ui;
};

#endif  // BERECHNUNGRL_H
