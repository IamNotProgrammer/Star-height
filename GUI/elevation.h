#ifndef ELEVATION_H
#define ELEVATION_H

#include <QDialog>

namespace Ui {
class Elevation;
}

class Elevation : public QDialog
{
	Q_OBJECT

public:
	explicit Elevation(QWidget *parent = nullptr);
	~Elevation();

private:
	Ui::Elevation *ui;
};

#endif // ELEVATION_H
