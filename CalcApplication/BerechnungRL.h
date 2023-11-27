#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QMainWindow>
#include <QWidget>
#include "ui_BerechnungRL.h"

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

 private slots:
  void onPbPressed()
  {
    double spannung = (ui->spannungIn->text()).toDouble();
    double frequenz = (ui->frequenzIn->text()).toDouble();
    double widerstand = (ui->widerstandIn->text()).toDouble();
    double induktivitaet = (ui->induktivitaetIn->text()).toDouble();
    ui->stromOut->setText(QString::number(spannung / 2, 'f', 5));
    ui->impedanzOut->setText(QString::number(frequenz / 2, 'f', 5));
    ui->phasenwinkelOut->setText(QString::number(induktivitaet / 2, 'f', 5));
    ui->leistungOut->setText(QString::number(widerstand / 2, 'f', 5));
    ui->blindleistungOut->setText(QString::number(spannung / 2, 'f', 5));
    ui->scheinleistungOut->setText(QString::number(spannung / 2, 'f', 5));
  }

 private:
  Ui::BerechnungRL* ui;
};

#endif  // BERECHNUNGRL_H
