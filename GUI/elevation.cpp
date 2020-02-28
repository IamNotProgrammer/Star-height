#include "elevation.h"
#include "ui_elevation.h"
#include <QPixmap>

Elevation::Elevation(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Elevation)
{
	ui->setupUi(this);

	QPixmap image("/usr/local/Data/Images/elevation.png") ;

	ui -> picture -> setPixmap(image) ;
	ui -> picture -> setScaledContents(true) ;

}

Elevation::~Elevation()
{
	delete ui;
}
