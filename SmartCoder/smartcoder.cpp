#include "smartcoder.h"


SmartCoder::SmartCoder(QWidget *parent)
	: BaseWindow(parent)
{
	ui.setupUi(this);
	// �����ޱ߿�
	this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	// ��ʼ��������;
	initTitleBar();
	//���ô����С
	resize(1200, 780);
	//���ô��屳��

	#pragma region ���ô��屳��
	this->setAutoFillBackground(true); // ���Ҫ����, ���������ʾ��������ͼ.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/skins/Resources/skins/skin7.png").scaled(// ���ű���ͼ.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));             // ʹ��ƽ�������ŷ�ʽ
	this->setPalette(palette);
#pragma endregion
}
void SmartCoder::initTitleBar()
{
	// ���ñ����������Ч�������Բ�����;
	//m_titleBar->setTitleRoll();
	m_titleBar->setTitleIcon(":/Resources/titleicon.png");
	m_titleBar->setTitleContent(QStringLiteral("SmartCoder"));
	m_titleBar->setButtonType(MIN_MAX_BUTTON);
	m_titleBar->setTitleWidth(this->width());
}
