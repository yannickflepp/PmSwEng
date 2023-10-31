#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class BerechnungRL;
}
QT_END_NAMESPACE

class BerechnungRL : public QWidget
{
  Q_OBJECT

 public:
  BerechnungRL(QWidget* parent = nullptr);
  ~BerechnungRL();

 private:
  Ui::BerechnungRL* ui;
};

#endif  // BERECHNUNGRL_H
