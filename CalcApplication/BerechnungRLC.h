#ifndef BERECHNUNGRLC_H
#define BERECHNUNGRLC_H

#include <QMainWindow>
#include <QWidget>
#include "ui_BerechnungRLC.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class BerechnungRLC;
}
QT_END_NAMESPACE

class BerechnungRLC : public QWidget
{
  Q_OBJECT

 public:
  BerechnungRLC(QWidget* parent = nullptr);
  ~BerechnungRLC();

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
  Ui::BerechnungRLC* ui;
};

#endif  // BERECHNUNGRL_H
