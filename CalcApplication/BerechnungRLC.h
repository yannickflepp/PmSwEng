#ifndef BERECHNUNGRLC_H
#define BERECHNUNGRLC_H

#include <QMainWindow>
#include <QWidget>
#include "Error.h"
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
  Error error;

 private slots:
  void onPbPressed()
  {
    bool ok = false;
    double spannung = (ui->spannungIn->text()).toDouble(&ok);
    double frequenz = (ui->frequenzIn->text()).toDouble(&ok);
    double widerstand = (ui->widerstandIn->text()).toDouble(&ok);
    double induktivitaet = (ui->induktivitaetIn->text()).toDouble(&ok);
    double kapazitaet = (ui->kapazitaetIn->text()).toDouble(&ok);
    if (ok == false)
    {
      error.show();
    }
    ui->stromOut->setText(QString::number(spannung / 2, 'f', 5));
    ui->impedanzOut->setText(QString::number(frequenz / 2, 'f', 5));
    ui->phasenwinkelOut->setText(QString::number(induktivitaet / 2, 'f', 5));
    ui->leistungOut->setText(QString::number(widerstand / 2, 'f', 5));
    ui->blindleistungOut->setText(QString::number(spannung / 2, 'f', 5));
    ui->scheinleistungOut->setText(QString::number(spannung / 2, 'f', 5));
  }

 private:
  Ui::BerechnungRLC* ui;
};

#endif  // BERECHNUNGRL_H
