#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "cubespline.h"
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showForm();

private:
    Form *form;
    Ui::MainWindow *ui;
    double x_begin, x_end, h, X;
    int N;
    QVector<double> x,y;
    QVector<double> x_point, y_point;

public slots:
    void slot(double x1, double x2, double x3, double x4, double x5, double x6, double x7,
    double x8, double x9, double x10, double x11, double x12,
    double y1, double y2, double y3, double y4, double y5, double y6, double y7,
    double y8, double y9, double y10, double y11, double y12,
              double Ox1, double Ox2, double Oy1, double Oy2);
};
#endif // MAINWINDOW_H
