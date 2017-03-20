#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QStandardItemModel>
#include "tags.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    void addTagsToFile();
    void filterFiles();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_tableView_clicked(const QModelIndex &index);
    void on_filterView_clicked(const QModelIndex &index);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_filterButton_clicked();
    void on_treeButton_clicked();
    void on_pathEdit_textChanged(const QString &text);
    void on_parentButton_clicked();
    void on_openButton_clicked();
    void on_tagView_clicked(const QModelIndex &index);
    void on_newTag_returnPressed();
    void on_clearButton_clicked();
    void deleteTag();

private:
    Tags *tags;
    QFileInfo current;
    QFileSystemModel *drivesModel;
    QFileSystemModel *filesModel;
    QStandardItemModel *filterModel;
    QString currentPath;
    void filterMode();
    void treeMode();
    void noneSelectedMode();
    void oneSelectedMode(const QModelIndex &index);
    void multiSelectedMode();
};

#endif // MAINWINDOW_H
