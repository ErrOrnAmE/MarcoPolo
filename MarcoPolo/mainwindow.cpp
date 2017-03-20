#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tags.h"
#include <QDesktopServices>
#include <QUrl>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>
#include <QShortcut>
#include <QJsonArray>
#include <QDebug>

/*!
 * \brief Constructor of MainWindow. Create the UI
 * \param QWidget parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    tags = new Tags();
    tags->readConfig();
    ui->setupUi(this);

    ui->tagListView->mainWindow = this;

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
    ui->tableView->setAcceptDrops(true);

    filterModel = new QStandardItemModel(this);
    filterModel->setHorizontalHeaderLabels(QStringList(QString("name")));
    ui->filterView->setModel(filterModel);
    ui->filterView->hideColumn(1);

    ui->pathEdit->setText(currentPath);

    ui->tagView->setSelectionMode(QAbstractItemView::MultiSelection);
    tags->listTags(ui->tagView);

    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Delete),ui->tagView);
    connect(shortcut, SIGNAL(activated()), this, SLOT(deleteTag()));

    this->filterMode();
    this->noneSelectedMode();
}

/*!
 * \brief Destructor of MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief Filter files to show thoses that have the checked tags
 */
void MainWindow::filterFiles() {
    filterModel->clear();
    filterModel->setHorizontalHeaderLabels(QStringList(QString("Name")));

    for (auto e : tags->listFiles(ui->tagView)) {
        qInfo() << filesModel->fileInfo(filesModel->index(e)).fileName();
        QList<QStandardItem*> row;
        QStandardItem *item = new QStandardItem(filesModel->fileInfo(filesModel->index(e)).fileName());
        item->setIcon(filesModel->fileIcon(filesModel->index(e)).pixmap(23));
        row.append(item);
        row.append(new QStandardItem(filesModel->fileInfo(filesModel->index(e)).absoluteFilePath()));
        filterModel->appendRow(row);
    }
    ui->filterView->hideColumn(1);
}

/*!
 * \brief Associate a tag to a file
 */
void MainWindow::addTagsToFile() {
    tags->addTags(ui->tagView,current.absoluteFilePath());
    tags->writeConfig();
    tags->listTags(ui->tagListView, tags->listFileTags(current.absoluteFilePath()));
}

/*!
 * \brief Delete a tag
 */
void MainWindow::deleteTag() {
    if (ui->tagView->hasFocus()) {
        tags->removeTags(ui->tagView);
        tags->writeConfig();
        tags->listTags(ui->tagView);
    } else {
        tags->removeTags(ui->tagListView, current.absoluteFilePath());
        tags->writeConfig();
        tags->listTags(ui->tagListView,tags->listFileTags(current.absoluteFilePath()));
    }
}

/*!
 * \brief Go through filetree
 * \param QModelIndex index
 */
void MainWindow::on_treeView_clicked(const QModelIndex &index) {
    currentPath = drivesModel->fileInfo(index).absoluteFilePath();
    ui->pathEdit->setText(currentPath);
    this->noneSelectedMode();
}

/*!
 * \brief Select files
 * \param QModelIndex index
 */
void MainWindow::on_tableView_clicked(const QModelIndex &index) {
    QItemSelection selected = ui->tableView->selectionModel()->selection();
    if (selected.length() > 1) {
        this->multiSelectedMode(selected.length());
    } else if (selected.length() == 1) {
        this->oneSelectedMode(index);
    } else {
        this->noneSelectedMode();
    }
}

/*!
 * \brief Select filtered files
 * \param QModelIndex index
 */
void MainWindow::on_filterView_clicked(const QModelIndex &index) {
    QItemSelection selected = ui->filterView->selectionModel()->selection();
    if (selected.length() > 1) {
        this->multiSelectedMode(selected.length());
    } else if (selected.length() == 1) {
        this->oneSelectedMode(filesModel->index(index.sibling(index.row(),index.column()+1).data().toString()));
    } else {
        this->noneSelectedMode();
    }
}

/*!
 * \brief Select tags
 * \param QModelIndex index
 */
void MainWindow::on_tagView_clicked(const QModelIndex &index) {
    QModelIndexList templatelist = ui->tagView->selectionModel()->selectedIndexes();
    QStringList stringlist;
    foreach (const QModelIndex &index, templatelist){
        stringlist.append(index.data(Qt::DisplayRole).toString());
    }
    ui->tagsEdit->setText(stringlist.join(", "));
    filterFiles();

    if (stringlist.length() > 0) {
        ui->filterView->show();
        ui->tableView->hide();
    } else {
        ui->filterView->hide();
        ui->tableView->show();
    }
}

/*!
 * \brief Open directory
 * \param QModelIndex index
 */
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

/*!
 * \brief Set filter mode
 */
void MainWindow::on_filterButton_clicked() {
    filterMode();
}

/*!
 * \brief Set tree mode
 */
void MainWindow::on_treeButton_clicked() {
    treeMode();
}

/*!
 * \brief Change root of fileSystemModel
 * \param text
 */
void MainWindow::on_pathEdit_textChanged(const QString &text) {
    currentPath = text;
    ui->tableView->setRootIndex(filesModel->setRootPath(currentPath));
    ui->tableView->clearSelection();
}

/*!
 * \brief Change list of filtered tags
 * \param text
 */
void MainWindow::on_searchEdit_textChanged(const QString &text) {
     tags->listTags(ui->tagView, text);
}

/*!
 * \brief Go back in files hierarchy
 */
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

/*!
 * \brief Open a file or a folder
 */
void MainWindow::on_openButton_clicked() {
    QModelIndex file;
    if (ui->tableView->isHidden()) {
        file = filesModel->index(ui->filterView->selectionModel()->selection().indexes().at(1).data().toString());
    } else {
        file = ui->tableView->selectionModel()->selection().indexes().at(0);
    }
    QFileInfo info = filesModel->fileInfo(file);
    QDesktopServices::openUrl(QUrl::fromUserInput(info.absoluteFilePath()));
}

/*!
 * \brief Create a new tag
 */
void MainWindow::on_newTag_returnPressed() {
    tags->addTag(ui->newTag->text());
    ui->newTag->setText("");
    tags->listTags(ui->tagView);
}

/*!
 * \brief Clear tag filtering
 */
void MainWindow::on_clearButton_clicked() {
    ui->tagView->clearSelection();
    ui->tagsEdit->setText("");
    ui->filterView->hide();
    ui->tableView->show();
}

/*!
 * \brief Go into filter mode
 */
void MainWindow::filterMode() {
    ui->filterButton->setDefault(true);
    ui->treeButton->setDefault(false);
    /*ui->filterView->show();
    ui->tableView->hide();*/
    if (ui->tagView->selectionModel()->selection().length()>0) {
        ui->filterView->show();
        ui->tableView->hide();
    } else {
        ui->filterView->hide();
        ui->tableView->show();
    }
    ui->tagView->show();
    ui->treeView->hide();
    ui->addButton->show();
    ui->parentButton->hide();
    ui->clearButton->show();
    ui->pathEdit->hide();
    ui->tagsEdit->show();
    ui->newTag->show();
    ui->filterIcon->show();
    noneSelectedMode();
}

/*!
 * \brief Go into tree mode
 */
void MainWindow::treeMode() {
    ui->filterButton->setDefault(false);
    ui->treeButton->setDefault(true);
    ui->filterView->hide();
    ui->tableView->show();
    ui->tagView->hide();
    ui->addButton->hide();
    ui->treeView->show();
    ui->parentButton->show();
    ui->clearButton->hide();
    ui->pathEdit->show();
    ui->tagsEdit->hide();
    ui->newTag->hide();
    ui->filterIcon->hide();
    noneSelectedMode();
}

/*!
 * \brief Go into none selected mode
 */
void MainWindow::noneSelectedMode() {
    ui->noneSelectedInformation->show();
    ui->oneSelectedInformation->hide();
    ui->multiSelectedInformation->hide();
    ui->tagListView->hide();
    ui->openButton->hide();
}

/*!
 * \brief Go into one selected mode
 * \param index
 */
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

    tags->listTags(ui->tagListView, tags->listFileTags(info.absoluteFilePath()));
    current = info;
}

/*!
 * \brief Go into multi selected mode
 * \param size
 */
void MainWindow::multiSelectedMode(int size) {
    ui->noneSelectedInformation->hide();
    ui->oneSelectedInformation->hide();
    QString text = "Éléments séléctionnés: ";
    text.append(QString::number(size));
    ui->countLabel->setText(text);
    ui->multiSelectedInformation->show();
    ui->tagListView->show();
    ui->openButton->show();
    ui->tagListView->setModel(new QStandardItemModel());
}
