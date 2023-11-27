#include "BerechnungRC.h"
#include "QDebug"
#include "ui_BerechnungRC.h"

BerechnungRC::BerechnungRC(QWidget* parent)
    : QWidget(parent), ui(new Ui::BerechnungRC)
{
  ui->setupUi(this);
  connect(ui->calculate, &QPushButton::pressed, this,
          &BerechnungRC::onPbPressed);
}

BerechnungRC::~BerechnungRC()
{
  delete ui;
}
