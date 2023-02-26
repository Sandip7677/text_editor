#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include<QFileDialog>
#include<QTextStream>
#include<QMessageBox>
#include<QFont>
#include<QFontDialog>
#include<QTextFormat>
#include<QTextCharFormat>
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
    about_text += "<p style='color:#ff0000; font-weight:bold; font-size:20px;'>PERSONAL INFO:</p>";
    about_text += "<p>Name: Anuj Kumar</p><p>DOB: 15-04-2002</p><p>Contact: 6203330169</p><p>Email: anujmehta3578@gmail.com</p><p>Github: https://github.com/Sandip7677</p><p>GFG: https://auth.geeksforgeeks.org/user/anujkumar20/</p>";
    about_text += "<p style='color:#ff0000; font-weight:bold; font-size:20px;'>EDUCATION:</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>MATRICULATION:</p>";
    about_text += "<p>A A GURIYADAMAR HIGH SCHOOL PHOKHRAHA PALAMU</p><p><pre>2017             86 %</pre>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>INTERMEDIATE:</p>";
    about_text += "<p>MANAVDEVI DEDICATED INTER COLLEGE PALAMU</p><p><pre>2017 - 2019           84.2%</pre>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>B.TECH:</p>";
    about_text += "<p>GOVERNMENT ENGINEERING COLLEGE DUMKA</p><p><pre>2020 - Present        9.93SGPA IN 2ND SEMESTER</pre>";
    about_text += "<p style='color:#ff0000; font-weight:bold; font-size:20px;'>INTERNSHIP:</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>Web Development:</p>";
    about_text += "<p>HashHackCode, Virtual</p><p>Feb 2023 - Present</p><p>Mentoring college and school students on frontend development concept by creative learning</p>";
    about_text += "<p style='color:#ff0000; font-weight:bold; font-size:20px;'>PROJECTS:</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>Super_market_billing:</p>";
    about_text += "<p>C++ project to implement Super Market Billing using C++,OOPS and DSA.</p><p>Github link: https://github.com/Sandip7677/Super_Mproject</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:16px;'>Hospital Management:</p>";
    about_text += "<p>Front-end website for hospital using HTML and CSS.</p><p>Github link: https://github.com/Sandip7677/Super_Mproject</p>";
    about_text += "<p style='color:#ff0000; font-weight:bold; font-size:20px;'>SKILLS:</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>c++</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>DSA</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>OOPS</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>HTML</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>CSS</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>JavaScript</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>Git</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>Github</p>";
    about_text += "<p style='color:#ffaa00; font-family:sans-serif; font-size:14px;'>English Proficiency</p>";
    QMessageBox::about(this,"Resume",about_text);
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionfont_style_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok){
        ui->textEdit->setFont(font);
    }
    else return;
}


void MainWindow::on_actionbold_triggered(bool isBold)
{
    QTextCharFormat fmt;
    fmt.setFontWeight(isBold ? QFont::Normal : QFont::Bold);
    QTextCursor cursor = ui->textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionUnbold_triggered(bool isBold)
{
    QTextCharFormat fmt;
    fmt.setFontWeight(isBold ? QFont::Bold : QFont::Normal);
    QTextCursor cursor = ui->textEdit->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(fmt);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actionSupScript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSubScript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}

