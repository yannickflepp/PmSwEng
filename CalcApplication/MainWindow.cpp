#include "MainWindow.h"
#include "BerechnungRC.h"
#include "BerechnungRL.h"
#include "ui_BerechnungRC.h"
#include "ui_BerechnungRL.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->buttonRL, &QPushButton::pressed, this,
          &MainWindow::onPbRLPressed);
  connect(ui->buttonRC, &QPushButton::pressed, this,
          &MainWindow::onPbRCPressed);
  connect(ui->buttonRLC, &QPushButton::pressed, this,
          &MainWindow::onPbRLCPressed);
}

MainWindow::~MainWindow()
{
  delete ui;
}
