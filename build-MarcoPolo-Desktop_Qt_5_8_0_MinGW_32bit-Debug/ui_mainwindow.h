/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QPushButton *treeButton;
    QListWidget *listWidget;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLineEdit *pathEdit;
    QPushButton *parentButton;
    QPushButton *clearButton;
    QLineEdit *tagsEdit;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListView *listView_2;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTag;
    QMenu *menuAide;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(948, 404);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setStyleSheet(QStringLiteral(""));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMaximumSize(QSize(100000, 100000));
        centralWidget->setAutoFillBackground(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setCheckable(false);
        filterButton->setFlat(false);

        horizontalLayout_2->addWidget(filterButton);

        treeButton = new QPushButton(centralWidget);
        treeButton->setObjectName(QStringLiteral("treeButton"));

        horizontalLayout_2->addWidget(treeButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setEnabled(true);
        listWidget->setAutoFillBackground(false);

        verticalLayout->addWidget(listWidget);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEnabled(true);
        treeView->setAutoFillBackground(false);

        verticalLayout->addWidget(treeView);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pathEdit = new QLineEdit(centralWidget);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));

        gridLayout_2->addWidget(pathEdit, 0, 1, 1, 1);

        parentButton = new QPushButton(centralWidget);
        parentButton->setObjectName(QStringLiteral("parentButton"));
        parentButton->setMaximumSize(QSize(30, 25));

        gridLayout_2->addWidget(parentButton, 0, 0, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setMaximumSize(QSize(25, 25));

        gridLayout_2->addWidget(clearButton, 0, 3, 1, 1);

        tagsEdit = new QLineEdit(centralWidget);
        tagsEdit->setObjectName(QStringLiteral("tagsEdit"));

        gridLayout_2->addWidget(tagsEdit, 0, 2, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setShowGrid(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(23);

        verticalLayout_5->addWidget(tableView);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_6->addWidget(label_2);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_6->addWidget(label_3);


        verticalLayout_3->addLayout(verticalLayout_6);

        listView_2 = new QListView(centralWidget);
        listView_2->setObjectName(QStringLiteral("listView_2"));

        verticalLayout_3->addWidget(listView_2);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(1, 2);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 948, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuTag = new QMenu(menuBar);
        menuTag->setObjectName(QStringLiteral("menuTag"));
        menuAide = new QMenu(menuBar);
        menuAide->setObjectName(QStringLiteral("menuAide"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTag->menuAction());
        menuBar->addAction(menuAide->menuAction());

        retranslateUi(MainWindow);

        filterButton->setDefault(false);
        treeButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Marco Polo", Q_NULLPTR));
        actionFile->setText(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        filterButton->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        treeButton->setText(QApplication::translate("MainWindow", "Tree", Q_NULLPTR));
        parentButton->setText(QApplication::translate("MainWindow", "^_", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "INFORMATIONS", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Type: Dossier / Fichier", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom de l'element", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ouvrir", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuTag->setTitle(QApplication::translate("MainWindow", "Tag", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
