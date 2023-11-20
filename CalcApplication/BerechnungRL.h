#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QMainWindow>
#include <QWidget>
#include "QDebug"
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

 private slots:
  void onPbPressed()
  {
    QString spannung = ui->spannungIn->text();
    QString frequenz = ui->frequenzIn->text();
    QString widerstand = ui->widerstandIn->text();
    QString induktivitaet = ui->induktivitaetIn->text();
    ui->stromOut->setText(spannung);
  }

 private:
  Ui::BerechnungRL* ui;
};

#endif  // BERECHNUNGRL_H
