#pragma once

#include <QtWidgets/QWidget>
#include "ui_smartcoder.h"
#include "basewindow.h"
#include "utils.h"
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>

class SmartCoder : public BaseWindow
{
	Q_OBJECT

public:
	SmartCoder(QWidget *parent = Q_NULLPTR);
	bool eventFilter(QObject* obj, QEvent* event);	// 添加事件过滤器声明
private:
	Ui::SmartCoderClass ui;
	void initTitleBar();
	 // 初始化控件;
	void initControl();
	utils myutils;
	//初始化信号与槽
	void initConnections();

};
