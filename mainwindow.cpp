#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateRenderArea();
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

void MainWindow::updateRenderArea(){updateStepCount();
                                    updateIntervalLength();
                                    updateScale();
                                    this->ui->renderArea->repaint();}

void MainWindow::updateScale(){this->ui->spinScale->setValue(this->ui->renderArea->getScale());}
void MainWindow::updateIntervalLength(){this->ui->spinIntervalLength->setValue(this->ui->renderArea->getIntervalLength());}
void MainWindow::updateStepCount(){this->ui->spinStep->setValue(this->ui->renderArea->getStepCount());}




void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
}

void MainWindow::on_spinIntervalLength_valueChanged(double intervalLength)
{
    this->ui->renderArea->setIntervalLength(intervalLength);
}



void MainWindow::on_spinStep_valueChanged(int stepCount)
{
    this->ui->renderArea->setStepCount(stepCount);
}

void MainWindow::on_backgroundColorBtn_clicked()
{
    QColor bgColor = QColorDialog::getColor(ui->renderArea->getBackgrounColor(),this,"Select Color");
    ui->renderArea->setBackgroundColor(bgColor);
    repaint();
}

void MainWindow::on_shapeColorBtn_clicked()
{
    QColor bgColor = QColorDialog::getColor(ui->renderArea->getShapeColor(),this,"Select Color");
    ui->renderArea->setShapeColor(bgColor);
    repaint();
}
