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
    void on_listView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QFileSystemModel *drivesModel;
    QFileSystemModel *filesModel;
};

#endif // MAINWINDOW_H
