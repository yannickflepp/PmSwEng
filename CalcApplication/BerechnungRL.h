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
  static double getImpedanz(double r, double f, double l)
  {
    return qSqrt(qPow(r, 2) + qPow((2 * M_PI * f * l), 2));
  }
  static double getStrom(double u, double z)
  {
    return u / z;
  }
  static double getLeistung(double r, double i)
  {
    return r * qPow(i, 2);
  }
  static double getBlindLeistung(double f, double l, double i)
  {
    return (2 * M_PI * f * l) * qPow(i, 2);
  }
  static double getScheinLeistung(double u, double i)
  {
    return u * i;
  }
  static double getPhasenWinkel(double p, double s)
  {
    return (qAcos((p / s)) / (2 * M_PI)) * 360;
  }
  Error error;

 private slots:
  void onPbPressedRL()
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

    double z = getImpedanz(r, f, l);
    double i = getStrom(u, z);
    double p = getLeistung(r, i);
    double q = getBlindLeistung(f, l, i);
    double s = getScheinLeistung(u, i);
    double phi = getPhasenWinkel(p, s);

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
