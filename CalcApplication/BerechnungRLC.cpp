#include "BerechnungRLC.h"
#include "QDebug"
#include "ui_BerechnungRLC.h"

BerechnungRLC::BerechnungRLC(QWidget* parent)
    : QWidget(parent), ui(new Ui::BerechnungRLC)
{
  ui->setupUi(this);
  connect(ui->calculate, &QPushButton::pressed, this,
          &BerechnungRLC::onPbPressedRLC);
}

BerechnungRLC::~BerechnungRLC()
{
  delete ui;
}
