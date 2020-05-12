#pragma once

#include <QtWidgets/QWidget>
#include "ui_smartcoder.h"
#include "basewindow.h"

class SmartCoder : public BaseWindow
{
	Q_OBJECT

public:
	SmartCoder(QWidget *parent = Q_NULLPTR);

private:
	Ui::SmartCoderClass ui;
	void initTitleBar();
};
