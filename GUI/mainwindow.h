#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    #define PI 3.1415926536 // it will be usefull to change into radians
// every comment to variable is in order i.e. int a, b ; // explained a, explained b
    int year = 2019 ; // current year
    int mon2 = 5 ; // current month
    int day2 = 1 ; // current day

    int H, M, L_H, L_M ; // hour and minute to clock: local hour, local minute, LST hour, LST minute

    float d, a, l, phi ; // coordinates: declination, rectastence, longitude, latitude
    float UT, LST, LMST, t, CT ; // time: Greenwich time, local siderial time, local time, hour angle, changing time (in function)


};

#endif // MAINWINDOW_H
