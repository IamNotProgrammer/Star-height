#include "azimuth.h"
#include "ui_azimuth.h"
#include <QPixmap>

Azimuth::Azimuth(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Azimuth)
{
	ui->setupUi(this);

	QPixmap image("/usr/local/Data/Images/azimuth.png") ;

	ui -> picture -> setPixmap(image) ;
	ui -> picture -> setScaledContents(true) ;

}

Azimuth::~Azimuth()
{
	delete ui;
}
