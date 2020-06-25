#include "view.h"
#include "mainwindow.h"
#include "ui_view.h"
#include <QtWebKitWidgets/QWebView>
#include <QObject>
#include <QString>
#include <QFile>


View::View(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::View)
{
	ui->setupUi(this);


	QString html = "<link rel=\"stylesheet\" href=\"https://aladin.u-strasbg.fr/AladinLite/api/v2/latest/aladin.min.css\" />"\
	"<script type=\"text/javascript\" src=\"https://code.jquery.com/jquery-1.12.1.min.js\" charset=\"utf-8\"></script>"\
	"<div id=\"aladin-lite-div\" style=\"width:690px;height:420px;\"></div>"\
	"<script type=\"text/javascript\" src=\"https://aladin.u-strasbg.fr/AladinLite/api/v2/latest/aladin.min.js\" charset=\"utf-8\"></script>"\
	"<script type=\"text/javascript\">"\
	"var aladin = A.aladin('#aladin-lite-div', {survey: \"P/DSS2/color\", fov:5, target: \"" ;

	QFile file("/usr/local/Data/Height.txt") ;
	file.open(QIODevice::ReadOnly | QIODevice::Text) ;

	QTextStream in(&file) ;

	QString line ;

	for (int i = 0 ; i < 62; i++)
		{

		in.readLine() ;

		}

	html += in.readLine() ;

	file.close() ;

	html += "\", fullScreen: true})</script>" ;

	ui -> webView -> setHtml(html) ;

}

View::~View()
{
	delete ui;
}
