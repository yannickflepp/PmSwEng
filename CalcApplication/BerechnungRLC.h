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
  static double getBlindwiderstand(double f, double l, double c)
  {
    double x = (2 * M_PI * f * l) - (1 / (2 * M_PI * f * c));
    if (x <= 0)
    {
      return x = x * -1;
    };
    return x;
  }
  static double getImpedanz(double r, double x)
  {
    return qSqrt(qPow(r, 2) + qPow(x, 2));
  }
  static double getStrom(double u, double z)
  {
    return u / z;
  }
  static double getLeistung(double r, double i)
  {
    return r * qPow(i, 2);
  }
  static double getBlindLeistung(double x, double i)
  {
    return x * qPow(i, 2);
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
  void onPbPressedRLC()
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

    double x = getBlindwiderstand(f, l, c);
    double z = getImpedanz(r, x);
    double i = getStrom(u, z);
    double p = getLeistung(r, i);
    double q = getBlindLeistung(x, i);
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
  Ui::BerechnungRLC* ui;
};

#endif  // BERECHNUNGRL_H
