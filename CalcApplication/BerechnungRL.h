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

/**
 * @brief Die BerechnungRL Klasse
 *
 * Diese Klasse berechnet verschiedene Grössen aus den frei wählbaren
 * Parametern u, f, r und l der seriellen RL-Schaltung.
 */
class BerechnungRL : public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief BerechnungRL Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRL.
   *
   * @param parent Pointervariable
   */
  BerechnungRL(QWidget* parent = nullptr);

  /**
   * @brief ~BerechnungRL Destruktor
   *
   * Diese Methode ist der Standard Destruktor und löscht das erzeugte Objekt
   * der Methode BerechnungRL::BerechnungRL.
   */
  ~BerechnungRL();

  /**
   * @brief getImpedanz Methode
   *
   * Diese Methode berechnet die Impedanz aus den frei wählbaren
   * Eingabeparametern r, f und l der gegebenen RL-Schaltung.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param f Gegebene Frequenz in Hertz.
   * @param l Gegebene Induktivität in Henry.
   * @return Die Gesamtimpedanz wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \sqrt{r^2+\left(2*\pi*f*l\right)^2}
   * \end{equation}
   */
  static double getImpedanz(double r, double f, double l)
  {
    return qSqrt(qPow(r, 2) + qPow((2 * M_PI * f * l), 2));
  }

  /**
   * @brief getStrom Methode
   *
   * Diese Methode berechnet den Strom aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter z der gegebenen
   * RL-Schaltung. Der Parameter z wird in der Methode BerechnungRL::getImpedanz
   * berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param z Berechnete Impedanz aus Methode BerechnungRL::getImpedanz in Ohm.
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
   * RL-Schaltung. Der Parameter i wird in der Methode BerechnungRL::getStrom
   * berechnet.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param i Berechneter Strom aus Methode BerechnungRL::getStrom in Ampere.
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
   * Eingabeparametern f, l und dem berechneten Parameter i der gegebenen
   * RL-Schaltung. Der Parameter i wird in der Methode BerechnungRL::getStrom
   * berechnet.
   *
   * @param f Gegebene Frequenz in Hertz.
   * @param l Gegebene Induktivität in Henry.
   * @param i Berechneter Strom aus Methode BerechnungRL::getStrom in Ampere.
   * @return Die Blindleistung wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * 2*\pi*f*l*i^2
   * \end{equation}
   */
  static double getBlindLeistung(double f, double l, double i)
  {
    return (2 * M_PI * f * l) * qPow(i, 2);
  }

  /**
   * @brief getScheinLeistung Methode
   *
   * Diese Methode berechnet die Scheinleistung aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter i der gegebenen
   * RL-Schaltung. Der Parameter i wird in der Methode BerechnungRL::getStrom
   * berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param i Berechneter Strom aus Methode BerechnungRL::getStrom in Ampere.
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
   * und s der gegebenen RL-Schaltung. Der Parameter p wird in der Methode
   * BerechnungRL::getLeistung und der Parameter s in der Methode
   * BerechnungRL::getScheinLeistung berechnet.
   *
   * @param p Berechnete Leistung aus Methode BerechnungRL::getLeistung in Watt.
   * @param s Berechnete Scheinleistung aus Methode
   *        BerechnungRL::getScheinLeistung in Voltampere.
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
   * @brief error Objekt
   *
   * Dieser Codeabschnitt erzeugt ein Objekt der Klasse Error::Error.
   */
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
