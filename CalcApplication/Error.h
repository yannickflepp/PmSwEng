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
 * Diese Klasse erzeugt ein Meldefenster bei ungültigen Eingabeparametern und
 * unterbricht die Berechnungen.
 */
class Error : public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief Error Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse Error.
   *
   * @param parent Pointervariable
   */
  Error(QWidget* parent = nullptr);

  /**
   * @brief ~Error Destruktor
   *
   * Diese Methode ist der Standard Destruktor und löscht das erzeugte Objekt
   * der Methode Error::Error.
   */
  ~Error();

 private:
  Ui::Error* ui;
};

#endif  // BERECHNUNGRL_H
