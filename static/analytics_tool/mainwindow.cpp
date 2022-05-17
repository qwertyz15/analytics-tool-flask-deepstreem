#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    analyticsWidget = new AnalyticsMainWindow();
    ui->centralWidget->layout()->addWidget(analyticsWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


