#ifndef OPT_NEW_OBS_H
#define OPT_NEW_OBS_H

#include <QDialog>

namespace Ui {
class Opt_new_obs;
}

class Opt_new_obs : public QDialog
{
	Q_OBJECT

public:
	explicit Opt_new_obs(QWidget *parent = nullptr);
	~Opt_new_obs();

private:
	Ui::Opt_new_obs *ui;
};

#endif // OPT_NEW_OBS_H
