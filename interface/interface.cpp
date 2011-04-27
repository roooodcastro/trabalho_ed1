#include "interface.h"

Interface::Interface(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	setGeometry(500, 400, 360, 120);

	ui.pushButtonConvert->setEnabled(false);
	ui.pushButtonEvaluate->setEnabled(false);

	QRegExp regex("^( +)?[0-9\(\)]([0-9\+\*\/\(\)\$\. -]+)?$");
	QValidator* validator = new QRegExpValidator(regex, this);

	ui.lineEditExpression->setValidator(validator);
	
	connect(ui.lineEditExpression, SIGNAL(textEdited(QString)), this, SLOT(validate()));
	connect(ui.pushButtonConvert, SIGNAL(clicked(bool)), this, SLOT(setConversion()));
	connect(ui.pushButtonEvaluate, SIGNAL(clicked(bool)), this, SLOT(evaluate()));
}

void Interface::validate()
{
	if ( ui.lineEditExpression->text() == "" )
	{
		ui.labelValidation->setText("Digite a expressão desejada:");
		ui.pushButtonConvert->setEnabled(false);
		ui.pushButtonEvaluate->setEnabled(false);
	}
	else
	{
		int validationCode = isValid(ui.lineEditExpression->text().toAscii().data());
		if (validationCode == 0)
		{
			ui.labelValidation->setText("Expressão Válida.");
			ui.pushButtonConvert->setEnabled(true);
			ui.pushButtonEvaluate->setEnabled(true);
		}
		else
		{
			ui.labelValidation->setText("Expressão Inválida.");
			ui.pushButtonConvert->setEnabled(false);
			ui.pushButtonEvaluate->setEnabled(false);
		}
	}
}

Lista Interface::convertExpression()
{
	Lista l;
	int func;
	convert( &l, ui.lineEditExpression->text().toAscii().data());
	return l;
}

void Interface::setConversion()
{
	char* str = (char*) malloc(sizeof(char)*255);
	toStringPosfixExpression(str, ui.lineEditExpression->text().toAscii().data());

	ui.lineEditResult->setText(QString(str));
}

void Interface::evaluate()
{
	int func;
	ui.lineEditResult->setText( QString("%1").arg( eval_posfix( convertExpression()) ) );
}

Interface::~Interface()
{
}
