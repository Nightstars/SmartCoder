#pragma once

#include <QtWidgets/QWidget>
#include "ui_smartcoder.h"
#include "basewindow.h"
#include "utils.h"
#include <QBitmap>
#include <QPainter>

class SmartCoder : public BaseWindow
{
	Q_OBJECT

public:
	SmartCoder(QWidget *parent = Q_NULLPTR);

private:
	Ui::SmartCoderClass ui;
	void initTitleBar();
	 // ��ʼ���ؼ�;
	void initControl();
	utils myutils;
};
