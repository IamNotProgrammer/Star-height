#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define PI 3.1415926536 // it will be usefull to change into radians

#include <QMainWindow>
#include <QPixmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_dec_deg_textChanged(const QString &arg1);

    void on_dec_min_textChanged(const QString &arg1);

    void on_dec_sec_textChanged(const QString &arg1);

    void on_lon_textChanged(const QString &arg1);

    void on_lat_textChanged(const QString &arg1);

    void on_LT_timeChanged(const QTime &time);

    void on_time_zone_valueChanged(int arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_Date_dateChanged(const QDate &date);

    void on_ra_h_textChanged(const QString &arg1);

    void on_ra_m_textChanged(const QString &arg1);

    void on_ra_s_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

// every comment to variable is in order i.e. int a, b ; // explained a, explained b
    int year = 2019 ; // current year
    int mon2 = 5 ; // current month
    int day2 = 1 ; // current day

    int H = 0, M = 0, L_H = 0, L_M = 0 ; // hour and minute to clock: local hour, local minute, LST hour, LST minute

                                        // dec - declination, re - rectastence
    double d_d = 0, d_m = 0, d_s = 0 ; // dec degree, dec minute, dec second
    double re_h = 0, re_m = 0, re_s = 0 ; // ra hour, ra minute, ra second
    double d = 0, a = 0, l = 0, phi = 0 ; // coordinates: dec, rectastence, longitude, latitude

	// Galactic coordinates //

	double aG = 3.366033414 ; // Galactic constants (radians)
	double dG = 0.473479222 ;
	double theta = 2.145568156 ;

	double L, B ; // Galactic coordinates

    double UT = 0, LST = 0, LMST = 0, t = 0, t_r ; // time: Greenwich time, local siderial time, local time, hour angle
    double max_height = 0 ;
    double h, A ; // coordinates: hegight, Azimuth ;
    double ch, CT ; //changing height, changing time (in function)

    std::string height ;

};

#endif // MAINWINDOW_H
