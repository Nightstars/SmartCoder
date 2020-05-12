#include "smartcoder.h"


SmartCoder::SmartCoder(QWidget *parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);
	// 设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	// 初始化标题栏;
	initTitleBar();
	//设置窗体大小
	resize(1200, 780);
	//设置窗体背景

	#pragma region 设置窗体背景
	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/skins/Resources/skins/skin7.png").scaled(// 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));             // 使用平滑的缩放方式
	this->setPalette(palette);
#pragma endregion
}
void SmartCoder::initTitleBar()
{
	// 设置标题栏跑马灯效果，可以不设置;
	//m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon(":/Resources/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("SmartCoder"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}
