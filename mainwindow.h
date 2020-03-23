#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_astBtn_clicked();

    void on_cycBtn_clicked();

    void on_huyginBtn_clicked();

    void on_hypoBtn_clicked();

    void on_lineBtn_clicked();

private:
    Ui::MainWindow *ui;
    void updateRenderArea();
};
#endif // MAINWINDOW_H
