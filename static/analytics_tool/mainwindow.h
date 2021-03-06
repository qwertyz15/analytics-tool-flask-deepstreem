#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Analytics/analyticsmainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    AnalyticsMainWindow *analyticsWidget;



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
