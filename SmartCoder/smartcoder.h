#pragma once

#include <QtWidgets/QWidget>
#include "ui_smartcoder.h"
#include "basewindow.h"
#include "utils.h"
#include <QBitmap>
#include <QPainter>
#include <QMouseEvent>
#include <Windows.h>
#include <QMessageBox>
#include <QFileDialog>
#include <numeric> // for std::accumulate
#include <string>  // for std::string
#include <vector>  // for std::vector
#include <iostream>

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
private slots:
	void onPushButton_disassemblyClicked();
	void onPushButton_selectdllfileClicked();
	void onPushButton_changedlloutputpathClicked();
};
