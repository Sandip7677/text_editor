#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Select a file to open");
    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly |QFile::Text)){
        QMessageBox::warning(this,"..","File can't be opned");
        return;
    }
    QTextStream in(&file);
    QString line=in.readAll();
    ui->textEdit->setText(line);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"..","File can't be saved");
        return;
    }
    QTextStream out(&file);
    QString line=ui->textEdit->toPlainText();
    out<<line;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"save file");
    QFile file(file_name);
    file_name=file_path;
    if(!file.open(QFile::WriteOnly |QFile::Text)){
        QMessageBox::warning(this,"..","File can't be saved");
        return;
    }
    QTextStream out(&file);
    QString line=ui->textEdit->toPlainText();
    out<<line;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_me_triggered()
{
    QString about_text;
    about_text +="Personal-info:\n";
    about_text +="\tName : Anuj Kumar\n";
    about_text +="\tFather's Name : Arjun Prasad\n";
    about_text +="\tD.O.B : 15-04-2002\n";

    QMessageBox::about(this,"Resume",about_text);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

