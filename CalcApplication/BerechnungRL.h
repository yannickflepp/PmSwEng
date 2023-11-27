#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QMainWindow>
#include <QWidget>
#include "Error.h"
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
  Error error;

 private slots:
  void onPbPressed()
  {
    bool ok = false;
    double spannung = (ui->spannungIn->text()).toDouble(&ok);
    double frequenz = (ui->frequenzIn->text()).toDouble(&ok);
    double widerstand = (ui->widerstandIn->text()).toDouble(&ok);
    double induktivitaet = (ui->induktivitaetIn->text()).toDouble(&ok);
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
  Ui::BerechnungRL* ui;
};

#endif  // BERECHNUNGRL_H
