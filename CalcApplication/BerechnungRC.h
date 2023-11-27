#ifndef BERECHNUNGRC_H
#define BERECHNUNGRC_H

#include <QMainWindow>
#include <QWidget>
#include "ui_BerechnungRC.h"

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

 private slots:
  void onPbPressed()
  {
    double spannung = (ui->spannungIn->text()).toDouble();
    double frequenz = (ui->frequenzIn->text()).toDouble();
    QString widerstand = ui->widerstandIn->text();
    ui->stromOut->setText(QString::number(spannung / 2, 'f', 5));
    ui->impedanzOut->setText(widerstand);
    ui->phasenwinkelOut->setText(widerstand);
    ui->leistungOut->setText(widerstand);
    ui->blindleistungOut->setText(widerstand);
    ui->scheinleistungOut->setText(widerstand);
  }

 private:
  Ui::BerechnungRC* ui;
};

#endif  // BERECHNUNGRL_H
