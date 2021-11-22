#include "form.h"
#include "ui_form.h"
#include <QMessageBox>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}


void Form::on_pushButton_clicked()
{
    if (ui->lineEditX1->text() == "" || ui->lineEditX2->text() == "" || ui->lineEditX3->text() == "" || ui->lineEditX4->text() == "" ||
            ui->lineEditX5->text() == "" || ui->lineEditX6->text() == "" || ui->lineEditX7->text() == "" || ui->lineEditX8->text() == "" ||
            ui->lineEditX9->text() == "" || ui->lineEditX10->text() == "" || ui->lineEditX11->text() == "" || ui->lineEditX12->text() == "" ||
            ui->lineEditY1->text() == "" || ui->lineEditY2->text() == "" || ui->lineEditY3->text() == "" || ui->lineEditY4->text() == "" ||
            ui->lineEditY5->text() == "" || ui->lineEditY6->text() == "" || ui->lineEditY7->text() == "" || ui->lineEditY8->text() == "" ||
            ui->lineEditY9->text() == "" || ui->lineEditY10->text() == "" || ui->lineEditY11->text() == "" || ui->lineEditY12->text()  == "" ||
            ui->lineEditOx1->text()== "" || ui->lineEditOx2->text()== "" || ui->lineEditOy1->text()== "" || ui->lineEditOy2->text()== "" )
        QMessageBox::information(NULL, "Ошибка", "Некоторые поля пустые");
    else {
    emit signal(ui->lineEditX1->text().toDouble(), ui->lineEditX2->text().toDouble(), ui->lineEditX3->text().toDouble(), ui->lineEditX4->text().toDouble(),
                ui->lineEditX5->text().toDouble(), ui->lineEditX6->text().toDouble(), ui->lineEditX7->text().toDouble(), ui->lineEditX8->text().toDouble(),
                ui->lineEditX9->text().toDouble(), ui->lineEditX10->text().toDouble(), ui->lineEditX11->text().toDouble(), ui->lineEditX12->text().toDouble(),
                ui->lineEditY1->text().toDouble(), ui->lineEditY2->text().toDouble(), ui->lineEditY3->text().toDouble(), ui->lineEditY4->text().toDouble(),
                ui->lineEditY5->text().toDouble(), ui->lineEditY6->text().toDouble(), ui->lineEditY7->text().toDouble(), ui->lineEditY8->text().toDouble(),
                ui->lineEditY9->text().toDouble(), ui->lineEditY10->text().toDouble(), ui->lineEditY11->text().toDouble(), ui->lineEditY12->text().toDouble(),
                ui->lineEditOx1->text().toDouble(), ui->lineEditOx2->text().toDouble(), ui->lineEditOy1->text().toDouble(), ui->lineEditOy2->text().toDouble());

}
}
