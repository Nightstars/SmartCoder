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
	//setAttribute(Qt::WA_TranslucentBackground, true);

	/*#pragma region 设置圆角窗体
		QBitmap bmp(this->size());
		bmp.fill();
		QPainter p(&bmp);
		p.setRenderHint(QPainter::Antialiasing);
		p.setPen(Qt::NoPen);
		p.setBrush(Qt::black);
		p.drawRoundedRect(bmp.rect(), 7, 7);
		setMask(bmp);
	#pragma endregion*/

	

	#pragma region 设置窗体背景
	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	QPalette palette = this->palette();
	palette.setBrush(backgroundRole(),
	QBrush(QPixmap(":/skins/Resources/skins/skins11.png").scaled(// 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));             // 使用平滑的缩放方式
	this->setPalette(palette);
	#pragma endregion

	initControl();
}
void SmartCoder::initTitleBar()
{
	// 设置标题栏跑马灯效果，可以不设置;
	//m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon(":/icons/Resources/icons/icon.png", {18,18});
	m_titleBar->setTitleContent(QStringLiteral("SmartCoder"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}

void SmartCoder::initControl()
{
	myutils.setIcon(ui.mianlabel_icon, ":/imgs/Resources/imgs/gencode.png", { 40,40 });
	myutils.setLabelContent(ui.mianlabel_txt, QStringLiteral("代码生成"));
	ui.mainframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.pluginlabel_icon, ":/imgs/Resources/imgs/plugin.png", { 40,40 });
	myutils.setLabelContent(ui.pluginlabel_txt, QStringLiteral("插件中心"));
	ui.pluginframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.disassemlabel_icon, ":/imgs/Resources/imgs/disassem.png", { 40,40 });
	myutils.setLabelContent(ui.disassemlabel_txt, QStringLiteral("反汇编"));
	ui.disassemframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.netlabel_icon, ":/imgs/Resources/imgs/net.png", { 40,40 });
	myutils.setLabelContent(ui.netlabel_txt, QStringLiteral("内网穿透"));
	ui.netframe_verticalLayout->setAlignment(Qt::AlignHCenter);
	myutils.setIcon(ui.minelabel_icon, ":/imgs/Resources/imgs/mine.png", { 40,40 });
	myutils.setLabelContent(ui.minelabel_txt, QStringLiteral("我的"));
	ui.mineframe_verticalLayout->setAlignment(Qt::AlignHCenter);
}
