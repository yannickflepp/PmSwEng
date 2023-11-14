// Fabrice Kohler 14.11.23
#include "BerechnungRC.h"
#include "ui_BerechnungRC.h"

BerechnungRC::BerechnungRC(QWidget* parent)
    : QWidget(parent), ui(new Ui::BerechnungRC)
{
  ui->setupUi(this);
}

BerechnungRC::~BerechnungRC()
{
  delete ui;
}
