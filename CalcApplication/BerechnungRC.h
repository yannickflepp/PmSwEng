#ifndef BERECHNUNGRC_H
#define BERECHNUNGRC_H

#include <QMainWindow>
#include <QWidget>
#include "Error.h"
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
  Error error;

 private slots:
  void onPbPressed()
  {
    bool ok = false;
    double spannung = (ui->spannungIn->text()).toDouble(&ok);
    double frequenz = (ui->frequenzIn->text()).toDouble(&ok);
    double widerstand = (ui->widerstandIn->text()).toDouble(&ok);
    double induktivitaet = (ui->kapazitaetIn->text()).toDouble(&ok);
    if (ok == false)
    {
      error.show();
    }
    double strom = 0;
    double impedanz = 0;
    double phasenwinkel = 0;
    double leistung = 0;
    double blindleistung = 0;
    double scheinleistung = 0;

    ui->stromOut->setText(QString::number(strom, 'f', 2));
    ui->impedanzOut->setText(QString::number(impedanz, 'f', 2));
    ui->phasenwinkelOut->setText(QString::number(phasenwinkel, 'f', 2));
    ui->leistungOut->setText(QString::number(leistung, 'f', 2));
    ui->blindleistungOut->setText(QString::number(blindleistung, 'f', 2));
    ui->scheinleistungOut->setText(QString::number(scheinleistung, 'f', 2));
  }

 private:
  Ui::BerechnungRC* ui;
};

#endif  // BERECHNUNGRL_H
