#ifndef AZIMUTH_H
#define AZIMUTH_H

#include <QDialog>

namespace Ui {
class Azimuth;
}

class Azimuth : public QDialog
{
	Q_OBJECT

public:
	explicit Azimuth(QWidget *parent = nullptr);
	~Azimuth();

private:
	Ui::Azimuth *ui;
};

#endif // AZIMUTH_H
