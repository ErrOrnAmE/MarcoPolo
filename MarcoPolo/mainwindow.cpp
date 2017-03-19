#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tags.h"
#include <QDesktopServices>
#include <QUrl>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tags = new Tags();
    tags->readConfig();
    ui->setupUi(this);

    this->filterMode();
    this->noneSelectedMode();

    currentPath = "";
    drivesModel = new QFileSystemModel(this);
    drivesModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs);
    drivesModel->setRootPath(currentPath);
    ui->treeView->setModel(drivesModel);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    filesModel = new QFileSystemModel(this);
    filesModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    filesModel->setRootPath(currentPath);
    ui->tableView->setModel(filesModel);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->hideColumn(1);
    ui->tableView->hideColumn(2);
    ui->tableView->hideColumn(3);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    ui->pathEdit->setText(currentPath);

    //Remplissage de la liste des tags
    ui->tagView->setSelectionMode(QAbstractItemView::MultiSelection);
    QStandardItemModel *model = new QStandardItemModel();
    QList<QStandardItem *> *truc = new QList<QStandardItem*>();
    QList<QStandardItem *> *truc3 = new QList<QStandardItem*>();
    model->appendColumn(*truc);
    model->appendColumn(*truc3);
    foreach (QString item, tags->tags.keys()) {
        QStandardItem *line = new QStandardItem();
        QStandardItem *line2 = new QStandardItem();
        QList<QStandardItem *> *truc2 = new QList<QStandardItem*>();
        line->setText(item);
        QPixmap *pix = new QPixmap(15,15);
        QPainter painter(pix);
        painter.setPen(QColor(0,0,0));
        painter.setBrush(QBrush(QColor(0,255,0,255)));
        painter.fillRect(0,0,15,15,QColor(255,255,255));
        painter.drawEllipse(1,1,13,13);
        line->setData(*pix,Qt::DecorationRole);
        //line2->setText(QString::number(42));
        truc2->append(line);
        model->appendRow(*truc2);
    }
   // ui->listView->setModel(model);
    ui->tagView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    currentPath = drivesModel->fileInfo(index).absoluteFilePath();
    ui->pathEdit->setText(currentPath);
    this->noneSelectedMode();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    QItemSelection selected = ui->tableView->selectionModel()->selection();
    if (selected.length() > 1) {
        this->multiSelectedMode();
    } else if (selected.length() == 1) {
        this->oneSelectedMode(index);
    } else {
        this->noneSelectedMode();
    }
}

void MainWindow::on_tagView_clicked(const QModelIndex &index) {
    QModelIndexList templatelist = ui->tagView->selectionModel()->selectedIndexes();
    QStringList stringlist;
    foreach (const QModelIndex &index, templatelist){
        stringlist.append(index.data(Qt::DisplayRole).toString());
    }
    ui->tagsEdit->setText(stringlist.join(", "));
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index) {
    if (filesModel->fileInfo(index).isDir()) {
        currentPath = filesModel->fileInfo(index).absoluteFilePath();
        QModelIndex parent = drivesModel->index(currentPath).parent();
        if (parent != QModelIndex()) {
            ui->treeView->setExpanded(parent,true);
        }
        ui->treeView->setExpanded(drivesModel->index(currentPath),true);
        ui->pathEdit->setText(currentPath);
        this->noneSelectedMode();
    }
}

void MainWindow::on_filterButton_clicked() {
    filterMode();
}

void MainWindow::on_treeButton_clicked() {
    treeMode();
}

void MainWindow::on_pathEdit_textChanged(const QString &text) {
    currentPath = text;
    ui->tableView->setRootIndex(filesModel->setRootPath(currentPath));
    ui->tableView->clearSelection();
}

void MainWindow::on_parentButton_clicked() {
    QModelIndex parent = filesModel->index(currentPath).parent();
    if (parent != QModelIndex()) {
        currentPath = filesModel->fileInfo(parent).absoluteFilePath();
    } else {
        currentPath = "";
    }
    ui->pathEdit->setText(currentPath);
    this->noneSelectedMode();
}

void MainWindow::on_openButton_clicked() {
    QModelIndex file = ui->tableView->selectionModel()->selection().indexes().at(0);
    QFileInfo info = filesModel->fileInfo(file);
    QDesktopServices::openUrl(QUrl::fromUserInput(info.absoluteFilePath()));
}

void MainWindow::filterMode() {
    ui->filterButton->setDefault(true);
    ui->treeButton->setDefault(false);
    ui->tagView->show();
    ui->treeView->hide();
    ui->parentButton->hide();
    ui->clearButton->show();
    ui->pathEdit->hide();
    ui->tagsEdit->show();
}

void MainWindow::treeMode() {
    ui->filterButton->setDefault(false);
    ui->treeButton->setDefault(true);
    ui->tagView->hide();
    ui->treeView->show();
    ui->parentButton->show();
    ui->clearButton->hide();
    ui->pathEdit->show();
    ui->tagsEdit->hide();
}

void MainWindow::noneSelectedMode() {
    ui->noneSelectedInformation->show();
    ui->oneSelectedInformation->hide();
    ui->multiSelectedInformation->hide();
    ui->tagListView->hide();
    ui->openButton->hide();
}

void MainWindow::oneSelectedMode(const QModelIndex &index) {
    QFileInfo info = filesModel->fileInfo(index);
    if (filesModel->fileInfo(index.parent()).absolutePath() == "") {
        ui->nameLabel->setText(info.absolutePath());
    } else {
        ui->nameLabel->setText(info.fileName());
    }
    ui->iconLabel->setPixmap(filesModel->fileIcon(index).pixmap(30));
    ui->noneSelectedInformation->hide();
    ui->oneSelectedInformation->show();
    ui->multiSelectedInformation->hide();
    ui->tagListView->show();
    ui->openButton->show();
}

void MainWindow::multiSelectedMode() {
    ui->noneSelectedInformation->hide();
    ui->oneSelectedInformation->hide();
    QString text = "Éléments séléctionnés: ";
    text.append(QString::number(ui->tableView->selectionModel()->selection().length()));
    ui->countLabel->setText(text);
    ui->multiSelectedInformation->show();
    ui->tagListView->show();
    ui->openButton->show();
}
