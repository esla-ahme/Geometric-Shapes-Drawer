#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_astBtn_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    updateRenderArea();

}

void MainWindow::on_cycBtn_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    updateRenderArea();
}

void MainWindow::on_huyginBtn_clicked()
{
   this->ui->renderArea->setShape(RenderArea::HuygensCycloid);
    updateRenderArea();
}

void MainWindow::on_hypoBtn_clicked()
{
    this->ui->renderArea->setShape(RenderArea::HypoCycloid);
    updateRenderArea();
}
void MainWindow::on_lineBtn_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Line);
    updateRenderArea();
}

void MainWindow::updateRenderArea(){this->ui->renderArea->repaint();}



