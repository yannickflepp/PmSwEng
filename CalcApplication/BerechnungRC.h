// Fabrice Kohler 14.11.23
#ifndef BERECHNUNGRC_H
#define BERECHNUNGRC_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui
{
class BerechnungRC;
}
QT_END_NAMESPACE

class BerechnungRC : public QWidget
{
  Q_OBJECT

 public:
  BerechnungRC(QWidget* parent = nullptr);
  ~BerechnungRC();

 private:
  Ui::BerechnungRC* ui;
};

#endif  // BERECHNUNGRC_H
