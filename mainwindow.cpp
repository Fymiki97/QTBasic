#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFile>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化颜色槽函数
    connect(ui->radioBlack,SIGNAL(clicked()),this, SLOT(SetTextColor()));
    connect(ui->radioRed,SIGNAL(clicked()),this, SLOT(SetTextColor()));
    connect(ui->radioBlue,SIGNAL(clicked()),this, SLOT(SetTextColor()));
    // 初始化字体槽函数

    connect(ui->isUnderLine, SIGNAL(clicked()),this, SLOT(on_chkBoxUnder_clicked()));
    connect(ui->isItalic, SIGNAL(clicked()),this, SLOT(on_chkItalic_clicked()));
    connect(ui->isBold, SIGNAL(clicked()),this, SLOT(on_chkBold_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::SetTextColor()
{

    QPalette palette = ui->plainTextEdit->palette();

    if(ui->radioBlack->isChecked()) //黑
        palette.setColor(QPalette::Text,Qt::black);
    else if (ui->radioRed->isChecked())//红
        palette.setColor(QPalette::Text,Qt::red);
    else if(ui->radioBlue->isChecked()) //蓝
        palette.setColor(QPalette::Text,Qt::blue);

    ui->plainTextEdit->setPalette(palette);
    return 0;
}

void MainWindow::on_chkBoxUnder_clicked() {
    QFont font=ui->plainTextEdit->font();
    font.setUnderline(ui->isUnderLine->isChecked());
    ui->plainTextEdit->setFont(font);
}

void MainWindow::on_chkItalic_clicked() {
    QFont font=ui->plainTextEdit->font();
    font.setItalic(ui->isItalic->isChecked());
    ui->plainTextEdit->setFont(font);
}

void MainWindow::on_chkBold_clicked() {
    QFont font=ui->plainTextEdit->font();
    font.setBold(ui->isBold->isChecked());
    ui->plainTextEdit->setFont(font);
}

