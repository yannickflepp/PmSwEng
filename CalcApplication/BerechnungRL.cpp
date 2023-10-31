#include "BerechnungRL.h"
#include "ui_BerechnungRL.h"

BerechnungRL::BerechnungRL(QWidget* parent)
    : QWidget(parent), ui(new Ui::BerechnungRL)
{
  ui->setupUi(this);
}

BerechnungRL::~BerechnungRL()
{
  delete ui;
}
