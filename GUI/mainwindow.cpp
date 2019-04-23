#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_dec_deg_textChanged(const QString &arg1)
{
    d_d = arg1.toFloat() ;
    d = d_d ;
}

void MainWindow::on_dec_min_textChanged(const QString &arg1)
{
    d_m = arg1.toFloat() / 60 ;
    d = d_d + d_m ;
}

void MainWindow::on_dec_sec_textChanged(const QString &arg1)
{
    d_s = arg1.toFloat() / 3600 ;
    d = d_d + d_m + d_s ;
}

void MainWindow::on_lon_textChanged(const QString &arg1)
{
    l = arg1.toFloat() ;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if (index == 1)
        l = - abs(l) ;

    else
        l = abs(l) ;
}

void MainWindow::on_lat_textChanged(const QString &arg1)
{
    phi = arg1.toFloat() ;
}

void MainWindow::on_LT_timeChanged(const QTime &time)
{
    H = time.hour() ;
    M = time.minute() ;
    LMST = H + float( M ) / 60 ;
}

void MainWindow::on_time_zone_valueChanged(int arg1)
{
    UT = LMST - arg1 ;
}


void MainWindow::on_pushButton_clicked()
{
    if (d <= phi )
        max_height = 90 - phi + d ;

    else
        max_height = 90 - d + phi ;

    ui -> max_h_deg->setText(QString::number( int( max_height ) ) ) ;
    ui -> max_h_m ->setText(QString::number( int( (max_height - int( max_height )) * 60 ) ) ) ;
}
