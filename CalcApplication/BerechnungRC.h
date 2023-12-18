#ifndef BERECHNUNGRC_H
#define BERECHNUNGRC_H

#include <QMainWindow>
#include <QWidget>
#include <QtMath>
#include "Error.h"
#include "ui_BerechnungRC.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class BerechnungRC;
}
QT_END_NAMESPACE

/**
 * @brief Die BerechnungRC Klasse
 *
 * Diese Klasse berechnet verschiedene Grössen aus den frei wählbaren
 * Parametern u, f, r und c der seriellen RC-Schaltung.
 */
class BerechnungRC : public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief BerechnungRC Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRC.
   *
   * @param parent Gull???
   */
  BerechnungRC(QWidget* parent = nullptr);

  /**
   * @brief ~BerechnungRC Destruktor
   *
   * Diese Methode löscht das erzeugte Objekt aus der Methode
   * BerechnungRC::BerechnungRC.
   */
  ~BerechnungRC();

  /**
   * @brief getImpedanz Methode
   *
   * Diese Methode berechnet die Impedanz aus den frei wählbaren
   * Eingabeparametern r, f und c der gegebenen RC-Schaltung.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param f Gegebene Frequenz in Hertz.
   * @param c Gegebene Kapazität in Farad.
   * @return Die Gesamtimpedanz wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \sqrt{r^2+\left(\frac{1}{2*\pi*f*c}\right)^2}
   * \end{equation}
   */
  static double getImpedanz(double r, double f, double c)
  {
    return qSqrt(qPow(r, 2) + qPow(1 / (2 * M_PI * f * c), 2));
  }

  /**
   * @brief getStrom Methode
   *
   * Diese Methode berechnet den Strom aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter z der gegebenen
   * RC-Schaltung. Der Parameter z wird in der Methode BerechnungRC::getImpedanz
   * berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param z Berechnete Impedanz aus Methode BerechnungRC::getImpedanz in Ohm.
   * @return Der Strom wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \frac{u}{z}
   * \end{equation}
   */
  static double getStrom(double u, double z)
  {
    return u / z;
  }

  /**
   * @brief getLeistung Methode
   *
   * Diese Methode berechnet die Leistung aus dem frei wählbaren
   * Eingabeparameter r und dem berechneten Parameter i der gegebenen
   * RC-Schaltung. Der Parameter i wird in der Methode BerechnungRC::getStrom
   * berechnet.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param i Berechneter Strom aus Methode BerechnungRC::getStrom in Ampere.
   * @return Die Leistung wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * r*i^2
   * \end{equation}
   */
  static double getLeistung(double r, double i)
  {
    return r * qPow(i, 2);
  }

  /**
   * @brief getBlindLeistung Methode
   *
   * Diese Methode berechnet die Blindleistung aus den frei wählbaren
   * Eingabeparametern f, c und dem berechneten Parameter i der gegebenen
   * RC-Schaltung. Der Parameter i wird in der Methode BerechnungRC::getStrom
   * berechnet.
   *
   * @param f Gegebene Frequenz in Hertz.
   * @param c Gegebene Kapazität in Farad.
   * @param i Berechneter Strom aus Methode BerechnungRC::getStrom in Ampere.
   * @return Die Blindleistung wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \frac{1}{2*\pi*f*c}*i^2
   * \end{equation}
   */
  static double getBlindLeistung(double f, double c, double i)
  {
    return (1 / (2 * M_PI * f * c)) * qPow(i, 2);
  }

  /**
   * @brief getScheinLeistung Methode
   *
   * Diese Methode berechnet die Scheinleistung aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter i der gegebenen
   * RC-Schaltung. Der Parameter i wird in der Methode BerechnungRC::getStrom
   * berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param i Berechneter Strom aus Methode BerechnungRC::getStrom in Ampere.
   * @return Die Scheinleistung wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * u*i
   * \end{equation}
   */
  static double getScheinLeistung(double u, double i)
  {
    return u * i;
  }

  /**
   * @brief getPhasenWinkel Methode
   *
   * Diese Methode berechnet den Phasenwinkel aus den berechneten Parameter p
   * und s der gegebenen RC-Schaltung. Der Parameter p wird in der Methode
   * BerechnungRC::getLeistung und der Parameter s in der Methode
   * BerechnungRC::getScheinLeistung berechnet.
   *
   * @param p Berechnete Leistung aus Methode BerechnungRC::getLeistung in Watt.
   * @param s Berechnete Scheinleistung aus Methode
   *        BerechnungRC::getScheinLeistung in Voltampere.
   * @return Der Phasenwinkel wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \arccos\left(\frac{p}{s}*\frac{1}{2*\pi}\right)*360
   * \end{equation}
   */
  static double getPhasenWinkel(double p, double s)
  {
    return (qAcos((p / s)) / (2 * M_PI)) * 360;
  }

  /**
   * @brief error Methode
   *
   * Gull???
   */
  Error error;

 private slots:
  void onPbPressedRC()
  {
    bool ok = false;
    double u = (ui->spannungIn->text()).toDouble(&ok);
    double f = (ui->frequenzIn->text()).toDouble(&ok);
    double r = (ui->widerstandIn->text()).toDouble(&ok);
    double c = (ui->kapazitaetIn->text()).toDouble(&ok);
    if (ok == false)
    {
      error.show();
    }

    double z = getImpedanz(r, f, c);
    double i = getStrom(u, z);
    double p = getLeistung(r, i);
    double q = getBlindLeistung(f, c, i);
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
  Ui::BerechnungRC* ui;
};

#endif  // BERECHNUNGRL_H
