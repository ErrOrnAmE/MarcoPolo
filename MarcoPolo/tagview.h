#ifndef TAGVIEW_H
#define TAGVIEW_H

#include<QWidget>
#include<QListView>
#include<QDragEnterEvent>
#include<QDropEvent>
#include<QDebug>
#include<QMimeData>
#include<QStandardItemModel>
#include "mainwindow.h"

class TagView : public QListView {
    public:
        TagView(QWidget * parent = 0) : QListView(parent) {
            setAcceptDrops(true);
            setDropIndicatorShown(true);
        };

        virtual ~TagView() {};

        MainWindow *mainWindow;

    private:
        void dropEvent(QDropEvent* event) {
            mainWindow->addTagsToFile();
        }
    };

#endif // TAGVIEW_H
