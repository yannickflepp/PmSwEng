#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QMainWindow>
#include <QWidget>
#include <QtMath>
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
    double u = (ui->spannungIn->text()).toDouble(&ok);
    double f = (ui->frequenzIn->text()).toDouble(&ok);
    double r = (ui->widerstandIn->text()).toDouble(&ok);
    double l = (ui->induktivitaetIn->text()).toDouble(&ok);
    if (ok == false)
    {
      error.show();
    }
    double z = qSqrt(qPow(r, 2) + qPow((2 * M_PI * f * l), 2));
    double i = u / z;
    double p = r * qPow(i, 2);
    double q = (2 * M_PI * f * l) * qPow(i, 2);
    double s = u * i;
    double phi = (qAcos((p / s)) / (2 * M_PI)) * 360;

    ui->stromOut->setText(QString::number(i, 'f', 3));
    ui->impedanzOut->setText(QString::number(z, 'f', 3));
    ui->phasenwinkelOut->setText(QString::number(phi, 'f', 3));
    ui->leistungOut->setText(QString::number(p, 'f', 3));
    ui->blindleistungOut->setText(QString::number(q, 'f', 3));
    ui->scheinleistungOut->setText(QString::number(s, 'f', 3));
  }

 private:
  Ui::BerechnungRL* ui;
};

#endif  // BERECHNUNGRL_H
