#include "MainWindow.h"
#include "BerechnungRL.h"
#include "ui_BerechnungRL.h"
#include "ui_MainWindow.h"
#include "BerechnungRC.h"
#include "ui_BerechnungRC.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->buttonRL, &QPushButton::pressed, this, &MainWindow::onPbPressed);
  connect(ui->buttonRC, &QPushButton::pressed, this, &MainWindow::onPbPressed);
}

MainWindow::~MainWindow()
{
  delete ui;
}
