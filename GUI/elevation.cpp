#include "elevation.h"
#include "ui_elevation.h"

Elevation::Elevation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Elevation)
{
	ui->setupUi(this);

}

Elevation::~Elevation()
{
	delete ui;
}
