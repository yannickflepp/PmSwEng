#ifndef BERECHNUNGRLC_H
#define BERECHNUNGRLC_H

#include <QMainWindow>
#include <QWidget>
#include <QtMath>
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
    double u = (ui->spannungIn->text()).toDouble(&ok);
    double f = (ui->frequenzIn->text()).toDouble(&ok);
    double r = (ui->widerstandIn->text()).toDouble(&ok);
    double l = (ui->induktivitaetIn->text()).toDouble(&ok);
    double c = (ui->kapazitaetIn->text()).toDouble(&ok);
    if (ok == false)
    {
      error.show();
    }
    double x = (2 * M_PI * f * l) - (1 / (2 * M_PI * f * c));
    if (x <= 0)
    {
      x = x * -1;
    };
    double z = qSqrt(qPow(r, 2) + qPow(x, 2));
    double i = u / z;
    double p = r * qPow(i, 2);
    double q = x * qPow(i, 2);
    double s = u * i;
    double phi = (qAcos((p / s)) / (2 * M_PI)) * 360;

    ui->stromOut->setText(QString::number(i, 'f', 2));
    ui->impedanzOut->setText(QString::number(z, 'f', 2));
    ui->phasenwinkelOut->setText(QString::number(phi, 'f', 2));
    ui->leistungOut->setText(QString::number(p, 'f', 2));
    ui->blindleistungOut->setText(QString::number(q, 'f', 2));
    ui->scheinleistungOut->setText(QString::number(s, 'f', 2));
  }

 private:
  Ui::BerechnungRLC* ui;
};

#endif  // BERECHNUNGRL_H
