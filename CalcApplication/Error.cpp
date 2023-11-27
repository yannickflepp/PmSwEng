#include "Error.h"
#include "QDebug"
#include "ui_Error.h"

Error::Error(QWidget* parent) : QWidget(parent), ui(new Ui::Error)
{
  ui->setupUi(this);
}

Error::~Error()
{
  delete ui;
}
