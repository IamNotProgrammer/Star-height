#include "azimuth.h"
#include "ui_azimuth.h"

Azimuth::Azimuth(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Azimuth)
{
	ui->setupUi(this);

}

Azimuth::~Azimuth()
{
	delete ui;
}
