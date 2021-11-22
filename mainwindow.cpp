#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cubespline.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(11);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "x" << "A" << "B" << "C" << "D");
    ui->tableWidget->setVerticalHeaderLabels(QStringList() << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9" << "10" << "11");

    form = new Form;

    connect(form, &Form::signal, this, &MainWindow::slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showForm()
{
    form->show();
}

void MainWindow::slot(double x1, double x2, double x3, double x4, double x5, double x6, double x7,
                      double x8, double x9, double x10, double x11, double x12,
                      double y1, double y2, double y3, double y4, double y5, double y6, double y7,
                      double y8, double y9, double y10, double y11, double y12,
                      double Ox1, double Ox2, double Oy1, double Oy2)
{
    ui->widget->clearGraphs();
    ui->widget->replot();
    x.clear();
    y.clear();
    x_point.clear();
    y_point.clear();
    h=0.001;

    ui->widget->xAxis->setRange(Ox1, Ox2);
    ui->widget->yAxis->setRange(Oy1, Oy2);


    std::map<double, double> p;

    p[x1] = y1;
    p[x2] = y2;
    p[x3] = y3;
    p[x4] = y4;
    p[x5] = y5;
    p[x6] = y6;
    p[x7] = y7;
    p[x8] = y8;
    p[x9] = y9;
    p[x10] = y10;
    p[x11] = y11;
    p[x12] = y12;
    CubeSpline s(p);
    s.build();

    x_begin = p.begin()->first;
    x_end = (--p.end())->first;
    X = x_begin;

    for (X = x_begin; X < x_end; X+=h)
    {
        x.push_back(X);
        y.push_back(s.f(X));
    }


    std::vector<std::vector<double>> coeff = s.get();
    for (int i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        x_point.push_back(coeff[i][0]);
        y_point.push_back(s.f(coeff[i][0]));
        for (int j = 0; j < ui->tableWidget->columnCount(); j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(tr("%1").arg(coeff[i + 1][j]));
            ui->tableWidget->setItem(i, j, item);
        }
    }

    QCPGraph *graph1 = ui->widget->addGraph();
    graph1->addData(x,y);
    QCPGraph *graph2 = ui->widget->addGraph();
    graph2->addData(x_point, y_point);
    graph2->setLineStyle((QCPGraph::LineStyle)0);

    for (auto i = p.begin(); i != p.end(); i++)
    {
        graph2->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, QPen(Qt::black, 1.5), QBrush(Qt::white), 9));
    }

    ui->widget->replot();
}

