#include "azimuth.h"
#include "ui_azimuth.h"

Azimuth::Azimuth(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Azimuth)
{
	ui->setupUi(this);
}

Azimuth::~Azimuth()
{
	delete ui;
}
