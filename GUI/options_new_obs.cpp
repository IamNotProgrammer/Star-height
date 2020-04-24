#include "options_new_obs.h"
#include "ui_options_new_obs.h"
#include <string>
#include <QStatusBar>
#include <QMessageBox>

Options_new_obs::Options_new_obs(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Options_new_obs)
{
	ui->setupUi(this);
}

Options_new_obs::~Options_new_obs()
{
	delete ui;
}


void Options_new_obs::f()
	{

	QString country = ui -> co -> text() ;
	QString city = ui -> ci -> text() ;
	QString lon, lat, alt ;

	lon = ui -> lo -> text() ;
	lat = ui -> la -> text() ;
	alt = ui -> al -> text() ;

	if ( ( lon.contains(",") or lon.contains(".") ) == false)
		lon.append(".0") ;

	if ( ( lat.contains(",") or lat.contains(".") ) == false)
		lat.append(".0") ;

	std::string com = "echo \"" + city.toStdString() + "," + lat.toStdString() + ","
					  + lon.toStdString() + "," + alt.toStdString() +
					  "\" >> /usr/local/Data/Observatories/" + country.toStdString() ;

	system( com.c_str() ) ;

	std::string com_2 = "sort -o /usr/local/Data/Observatories/" + country.toStdString() +
						" /usr/local/Data/Observatories/" + country.toStdString() ;

	system( com_2.c_str() ) ;

	}


void Options_new_obs::on_buttonBox_accepted()
{

	QString country = ui -> co -> text() ;
	QString city = ui -> ci -> text() ;

	if ( (city.size() < 2) or (country.size() < 2) )
		QMessageBox::warning(this, "Too short expresion", "Name of city or country is too short. It has to be at least 2 characters long") ;

	else
		{

		QMessageBox::StandardButton reply;
		reply = QMessageBox::question(this, "Add observatory", "Are you sure you want to add this location?", QMessageBox::Yes|QMessageBox::No);

		if (reply == QMessageBox::Yes)
			{

			f() ;
			ui -> statusbar -> showMessage("Location added", 2000) ;

			}

		}

}


void Options_new_obs::on_buttonBox_rejected()
{
	Options_new_obs::close() ;
}
