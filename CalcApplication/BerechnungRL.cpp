#include "BerechnungRL.h"
#include "QDebug"
#include "ui_BerechnungRL.h"

BerechnungRL::BerechnungRL(QWidget* parent)
    : QWidget(parent), ui(new Ui::BerechnungRL)
{
  ui->setupUi(this);
  connect(ui->calculate, &QPushButton::pressed, this,
          &BerechnungRL::onPbPressed);
}

BerechnungRL::~BerechnungRL()
{
  delete ui;
}
