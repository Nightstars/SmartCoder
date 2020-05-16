#pragma once
#include <QtWidgets/QWidget>
#include <QLabel>
class utils
{
	public:
		//设置Label文本内容
		void setIcon(QLabel *qlabel, QString filePath, QSize IconSize);
		//设置Label文本内容
		void setLabelContent(QLabel* qlabel,QString labelContent, int labelFontSize = 9);
		// 加载样式文件;
		void loadStyleSheet(QWidget*obj,const QString& sheetName);
};

