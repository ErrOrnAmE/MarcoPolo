#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString sPath = "C:/";
    drivesModel = new QFileSystemModel(this);
    drivesModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    drivesModel->setRootPath(sPath);
    ui->treeView->setModel(drivesModel);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    filesModel = new QFileSystemModel(this);
    filesModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    filesModel->setRootPath(sPath);
    ui->listView->setModel(filesModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    QString sPath = drivesModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(filesModel->setRootPath(sPath));
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index) {
    if (filesModel->fileInfo(index).isDir()) {
        QString sPath = filesModel->fileInfo(index).absoluteFilePath();
        ui->listView->setRootIndex(filesModel->setRootPath(sPath));
        //ui->treeView->set
    }
}
