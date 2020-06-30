#ifndef AZIMUTH_H
#define AZIMUTH_H

#include <QMainWindow>

namespace Ui {
class Azimuth;
}

class Azimuth : public QMainWindow
{
	Q_OBJECT

public:
	explicit Azimuth(QWidget *parent = nullptr);
	~Azimuth();

private:
	Ui::Azimuth *ui;
};

#endif // AZIMUTH_H
