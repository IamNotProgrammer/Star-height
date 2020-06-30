#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>

namespace Ui {
class View;
}

class View : public QMainWindow
{
	Q_OBJECT

public:
	explicit View(QWidget *parent = nullptr);
	~View();

private slots:

private:
	Ui::View *ui;
};

#endif // VIEW_H
