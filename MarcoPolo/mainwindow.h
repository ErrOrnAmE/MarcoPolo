#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_tableView_clicked(const QModelIndex &index);
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_filterButton_clicked();
    void on_treeButton_clicked();
    void on_pathEdit_textChanged(const QString &text);
    void on_parentButton_clicked();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *drivesModel;
    QFileSystemModel *filesModel;
    QString currentPath;
    void filterMode();
    void treeMode();
    void noneSelectedMode();
    void oneSelectedMode();
    void multiSelectedMode();
};

#endif // MAINWINDOW_H
