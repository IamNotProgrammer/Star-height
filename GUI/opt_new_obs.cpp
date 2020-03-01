#include "opt_new_obs.h"
#include "ui_opt_new_obs.h"

Opt_new_obs::Opt_new_obs(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Opt_new_obs)
{
	ui->setupUi(this);
}

Opt_new_obs::~Opt_new_obs()
{
	delete ui;
}
