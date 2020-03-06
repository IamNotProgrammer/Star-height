#ifndef OPTIONS_NEW_OBS_H
#define OPTIONS_NEW_OBS_H

#include <QMainWindow>

namespace Ui {
class Options_new_obs;
}

class Options_new_obs : public QMainWindow
{
	Q_OBJECT

public:
	explicit Options_new_obs(QWidget *parent = nullptr);
	~Options_new_obs();

private slots:
	void on_buttonBox_accepted();

	void on_buttonBox_rejected();

	void f() ;

private:
	Ui::Options_new_obs *ui;
};

#endif // OPTIONS_NEW_OBS_H
