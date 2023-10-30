#ifndef BERECHNUNGRL_H
#define BERECHNUNGRL_H

#include <QWidget>

namespace Ui {
class BerechnungRL;
}

class BerechnungRL : public QWidget
{
    Q_OBJECT

  public:
    explicit BerechnungRL(QWidget *parent = nullptr);
    ~BerechnungRL();

  private:
    Ui::BerechnungRL *ui;
};

#endif // BERECHNUNGRL_H
