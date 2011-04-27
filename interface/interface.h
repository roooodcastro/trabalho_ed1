#ifndef INTERFACE_H
#define INTERFACE_H

#include <QtGui/QWidget>
#include "ui_interface.h"
#include "../engine/posfix.h"

class Interface : public QWidget
{
	Q_OBJECT

public:
	Interface(QWidget *parent = 0);
	~Interface();

private:
	Ui::InterfaceClass ui;
	Lista convertExpression();

private slots:
	void validate();
	void setConversion();
	void evaluate();
	
	
};

#endif // INTERFACE_H
