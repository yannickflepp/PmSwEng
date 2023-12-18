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

class Error : public QWidget
{
  Q_OBJECT

 public:
  Error(QWidget* parent = nullptr);
  ~Error();

 private:
  Ui::Error* ui;
};

#endif  // BERECHNUNGRL_H
