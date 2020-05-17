#include "smartcoder.h"

#pragma region 界面
SmartCoder::SmartCoder(QWidget *parent)
	: BaseWindow(parent)
{
#pragma endregion

#pragma region 全局配置
	ui.setupUi(this);
	// 设置无边框
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	// 初始化标题栏;
	initTitleBar();
	//设置窗体大小
	resize(1200, 780);
	ui.main_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.plugin_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.disassem_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.net_label_widget->installEventFilter(this);    // 安装事件过滤器
	ui.mine_label_widget->installEventFilter(this);    // 安装事件过滤器
#pragma endregion

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

#pragma region 初始化
	//初始化控件
	initControl();
	//初始化事件绑定
	initConnections();
#pragma endregion
}
#pragma region 初始化标题栏
void SmartCoder::initTitleBar()
{
	// 设置标题栏跑马灯效果，可以不设置;
	//m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon(":/icons/Resources/icons/icon.png", {18,18});
	m_titleBar->setTitleContent(QStringLiteral("SmartCoder"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}
#pragma endregion

#pragma region 初始化控件
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
	//加载样式表
	myutils.loadStyleSheet(this, "myapp");
}
#pragma endregion

#pragma region 事件绑定
void SmartCoder::initConnections()
{
	
}
#pragma endregion

#pragma region 主功能按钮点击事件

#pragma endregion

#pragma region 事件过滤器
bool SmartCoder::eventFilter(QObject* obj, QEvent* event)
{
	if (obj == ui.main_label_widget)//指定某个QLabel
	{
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.plugin_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.disassem_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.net_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else if (obj == ui.mine_label_widget) {
		if (event->type() == QEvent::MouseButtonPress) //鼠标点击
		{
			QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event); // 事件转换

			if (mouseEvent->button() == Qt::LeftButton)
			{
				ui.main_label_widget->setStyleSheet("QWidget#main_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#main_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.plugin_label_widget->setStyleSheet("QWidget#plugin_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#plugin_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.disassem_label_widget->setStyleSheet("QWidget#disassem_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#disassem_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.net_label_widget->setStyleSheet("QWidget#net_label_widget{background-color: rgb(255, 255, 255,0);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#net_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				ui.mine_label_widget->setStyleSheet("QWidget#mine_label_widget{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}QWidget#mine_label_widget:hover{background-color: rgb(255, 255, 255,80);border-top-left-radius: 5px;border-top-right-radius: 5px;}");
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		// pass the event on to the parent class
		return QWidget::eventFilter(obj, event);
	}
}
#pragma endregion

