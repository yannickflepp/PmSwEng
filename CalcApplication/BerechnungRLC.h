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

/**
 * @brief Die BerechnungRLC Klasse
 *
 * Diese Klasse berechnet verschiedene Grössen aus den frei wählbaren
 * Parametern u, f, r, l und c der seriellen RLC-Schaltung.
 */
class BerechnungRLC : public QWidget
{
  Q_OBJECT

 public:
  /**
   * @brief BerechnungRLC Konstruktor
   *
   * Diese Methode erzeugt ein Objekt der Klasse BerechnungRLC.
   *
   * @param parent Pointervariable
   */
  BerechnungRLC(QWidget* parent = nullptr);

  /**
   * @brief ~BerechnungRLC Destruktor
   *
   * Diese Methode ist der Standard Destruktor und löscht das erzeugte Objekt
   * der Methode BerechnungRLC::BerechnungRLC.
   */
  ~BerechnungRLC();

  /**
   * @brief getBlindwiderstand Methode
   *
   * Diese Methode berechnet den Blindwiderstand aus den frei wählbaren
   * Eingangsparametern f, l und c der gegebenen RLC-Schaltung.
   *
   * @param f Gegebene Frequenz in Hertz.
   * @param l Gegebene Induktivität in Henry.
   * @param c Gegebene Kapazität in Farad.
   * @return Der Blindwiderstand wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * 2*\pi*f*l-\frac{1}{2*\pi*f*c}
   * \end{equation}
   */
  static double getBlindwiderstand(double f, double l, double c)
  {
    double x = (2 * M_PI * f * l) - (1 / (2 * M_PI * f * c));
    if (x <= 0)
    {
      return x = x * -1;
    };
    return x;
  }

  /**
   * @brief getImpedanz Methode
   *
   * Diese Methode berechnet die Impedanz aus dem frei wählbaren
   * Eingabeparameter r und dem berechneten Parameter x der gegebenen
   * RLC-Schaltung. Der Parameter x wird in der Methode
   * BerechnungRLC::getBlindwiderstand berechnet.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param x Berechneter Blindwiderstand aus Methode
   *        BerechnungRLC::getBlindwiderstand in Ohm.
   * @return Die Impedanz wird anhand folgender Formel berechnet und
   * zurückgegeben:\n
   * \begin{equation}
   * \sqrt{r^2+x^2}
   * \end{equation}
   */
  static double getImpedanz(double r, double x)
  {
    return qSqrt(qPow(r, 2) + qPow(x, 2));
  }

  /**
   * @brief getStrom Methode
   *
   * Diese Methode berechnet den Strom aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter z der gegebenen
   * RLC-Schaltung. Der Parameter z wird in der Methode
   * BerechnungRLC::getImpedanz berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param z Berechnete Impedanz aus Methode BerechnungRLC::getImpedanz in Ohm.
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
   * RLC-Schaltung. Der Parameter i wird in der Methode BerechnungRLC::getStrom
   * berechnet.
   *
   * @param r Gegebener Widerstand in Ohm.
   * @param i Berechneter Strom aus Methode BerechnungRLC::getStrom in Ampere.
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
   * Diese Methode berechnet die Blindleistung aus den berechneten Parametern x
   * und i der gegebenen RLC-Schaltung. Der Parameter x wird in der Methode
   * BerechnungRLC::getBlindwiderstand und der Parameter i wird in der Methode
   * BerechnungRLC::getStrom berechnet.
   *
   * @param x Berechneter Blindwiderstand aus Methode
   *        BerechnungRLC::getBlindwiderstand in Ohm.
   * @param i Berechneter Strom aus Methode BerechnungRLC::getStrom in Ampere.
   * @return Die Blindleistung wird anhand folgender Formel berechent und
   * zurückgegeben:\n
   * \begin{equation}
   * x*i^2
   * \end{equation}
   */
  static double getBlindLeistung(double x, double i)
  {
    return x * qPow(i, 2);
  }

  /**
   * @brief getScheinLeistung Methode
   *
   * Diese Methode berechnet die Scheinleistung aus dem frei wählbaren
   * Eingabeparameter u und dem berechneten Parameter i der gegebenen
   * RLC-Schaltung. Der Parameter i wird in der Methode BerechnungRLC::getStrom
   * berechnet.
   *
   * @param u Gegebene Spannung in Volt.
   * @param i Berechneter Strom aus Methode BerechnungRLC::getStrom in Ampere.
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
   * Diese Methode berechnet den Phasenwinkel aus den berechneten Parametern p
   * und s der gegebenen RLC-Schaltung. Der Parameter p wird in der Methode
   * BerechnungRLC::getLeistung und der Parameter s in der Methode
   * BerechnungRLC::getScheinLeistung berechnet.
   *
   * @param p Berechnete Leistung aus Methode BerechnungRLC::getLeistung in
   *        Watt.
   * @param s Berechnete Scheinleistung aus Methode
   *        BerechnungRLC::getScheinLeistung in Voltampere.
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
   * @brief error Attribut
   *
   * Dieser Codeabschnitt erzeugt ein Attribut der Klasse Error::Error.
   */
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
