#include "Error.h"
#include "QDebug"
#include "ui_Error.h"

Error::Error(QWidget* parent) : QWidget(parent), ui(new Ui::Error)
{
  ui->setupUi(this);
  connect(ui->buttonCloseError, &QPushButton::pressed, this, &Error::close);
}

Error::~Error()
{
  delete ui;
}
