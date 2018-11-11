#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->insertButton, SIGNAL(released()), this, SLOT(insert()));
    connect(ui->removeButton, SIGNAL(released()), this, SLOT(remove()));
    connect(ui->print2d, SIGNAL(released()), this, SLOT(print()));
    connect(ui->print1dPREORDER, SIGNAL(released()), this, SLOT(print()));
    connect(ui->print1dINORDER, SIGNAL(released()), this, SLOT(print()));
    connect(ui->print1dPOSTORDER, SIGNAL(released()), this, SLOT(print()));
    connect(ui->colors, SIGNAL(released()), this, SLOT(print()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::insert() {
    QString a = ui->insertEdit->text();
    bool ok;
    int number = a.toInt(&ok);
    if(ok) {
        tree->Insert(number);
    }
    QString printer;
    if(ui->print2d->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint2D(true);
        } else {
            printer = tree->QPrint2D(false);
        }
    } else if(ui->print1dPREORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(PREORDER, true);
        } else {
            printer = tree->QPrint(PREORDER, false);
        }
    } else if(ui->print1dPOSTORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(POSTORDER, true);
        } else {
            printer = tree->QPrint(POSTORDER, false);
        }
    } else {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(INORDER, true);
        } else {
            printer = tree->QPrint(INORDER, false);
        }
    }
    ui->result->setText(printer);
}

void MainWindow::remove() {
    QString a = ui->removeEdit->text();
    bool ok;
    int number = a.toInt(&ok);
    if(ok) {
        tree->Delete(number);
    }
    QString printer;
    if(ui->print2d->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint2D(true);
        } else {
            printer = tree->QPrint2D(false);
        }
    } else if(ui->print1dPREORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(PREORDER, true);
        } else {
            printer = tree->QPrint(PREORDER, false);
        }
    } else if(ui->print1dPOSTORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(POSTORDER, true);
        } else {
            printer = tree->QPrint(POSTORDER, false);
        }
    } else {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(INORDER, true);
        } else {
            printer = tree->QPrint(INORDER, false);
        }
    }
    ui->result->setText(printer);
}

void MainWindow::print() {
    QString printer;
    if(ui->print2d->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint2D(true);
        } else {
            printer = tree->QPrint2D(false);
        }
    } else if(ui->print1dPREORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(PREORDER, true);
        } else {
            printer = tree->QPrint(PREORDER, false);
        }
    } else if(ui->print1dPOSTORDER->isChecked()) {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(POSTORDER, true);
        } else {
            printer = tree->QPrint(POSTORDER, false);
        }
    } else {
        if(ui->colors->isChecked()) {
            printer = tree->QPrint(INORDER, true);
        } else {
            printer = tree->QPrint(INORDER, false);
        }
    }
    ui->result->setText(printer);
}
