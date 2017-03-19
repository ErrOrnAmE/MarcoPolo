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
    QAction *actionQuit;
    QAction *actionAjouter;
    QAction *actionSupprimer;
    QAction *actionDocumentation;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QPushButton *treeButton;
    QListView *tagView;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QLineEdit *pathEdit;
    QPushButton *parentButton;
    QPushButton *clearButton;
    QLineEdit *tagsEdit;
    QTableView *tableView;
    QVBoxLayout *verticalLayout_3;
    QWidget *noneSelectedInformation;
    QVBoxLayout *noneSelectedInfo;
    QLabel *label_4;
    QWidget *oneSelectedInformation;
    QVBoxLayout *oneSelectedInfo;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *iconLabel;
    QLabel *nameLabel;
    QWidget *multiSelectedInformation;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QLabel *countLabel;
    QListView *tagListView;
    QPushButton *openButton;
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
        MainWindow->setStyleSheet(QLatin1String("QPushButton { border: 1px solid #4ca4ae; padding: 5px 0px 5px 0px;}\n"
"QPushButton:!focus {background-color : white; color:#212121}\n"
"QPushButton:default {background-color : #4ca4ae; color:white}\n"
"QPushButton:hover {background-color : #804ca4ae; color:white}\n"
"\n"
"QTreeView::item:hover {background-color : #404ca4ae; color:white} \n"
"QTreeView::item:selected {background-color : #804ca4ae; color:white} \n"
"QTableView::item:hover {background-color : #404ca4ae; color:white}\n"
"QTableView::item:selected {background-color : #804ca4ae; color:white}\n"
"\n"
" QScrollBar:vertical {\n"
"     background: #FAFAFA;\n"
"     width: 15px;\n"
"     margin: 22px 0 22px 0;\n"
" }\n"
" QScrollBar::handle:vertical {\n"
"     background: #804ca4ae;\n"
"     border: 1px solid #4ca4ae;\n"
"     min-height: 20px;\n"
" }\n"
" QScrollBar::add-line:vertical {\n"
"     background: #FAFAFA;\n"
"     height: 20px;\n"
"     subcontrol-position: bottom;\n"
"     subcontrol-origin: margin;\n"
" }\n"
"\n"
" QScrollBar::sub-line:ver"
                        "tical {\n"
"     background: #FAFAFA;\n"
"     height: 20px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     width: 3px;\n"
"     height: 3px;\n"
"     background: #4ca4ae;\n"
" }\n"
"\n"
" QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"     background: none;\n"
" }"));
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QStringLiteral("actionFile"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionAjouter = new QAction(MainWindow);
        actionAjouter->setObjectName(QStringLiteral("actionAjouter"));
        actionSupprimer = new QAction(MainWindow);
        actionSupprimer->setObjectName(QStringLiteral("actionSupprimer"));
        actionDocumentation = new QAction(MainWindow);
        actionDocumentation->setObjectName(QStringLiteral("actionDocumentation"));
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
        filterButton->setAutoFillBackground(false);
        filterButton->setCheckable(false);
        filterButton->setFlat(false);

        horizontalLayout_2->addWidget(filterButton);

        treeButton = new QPushButton(centralWidget);
        treeButton->setObjectName(QStringLiteral("treeButton"));

        horizontalLayout_2->addWidget(treeButton);


        verticalLayout->addLayout(horizontalLayout_2);

        tagView = new QListView(centralWidget);
        tagView->setObjectName(QStringLiteral("tagView"));
        tagView->setEnabled(true);
        tagView->setAutoFillBackground(false);
        tagView->setViewMode(QListView::ListMode);

        verticalLayout->addWidget(tagView);

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
        pathEdit->setEnabled(true);

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
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        noneSelectedInformation = new QWidget(centralWidget);
        noneSelectedInformation->setObjectName(QStringLiteral("noneSelectedInformation"));
        noneSelectedInfo = new QVBoxLayout(noneSelectedInformation);
        noneSelectedInfo->setSpacing(6);
        noneSelectedInfo->setContentsMargins(11, 11, 11, 11);
        noneSelectedInfo->setObjectName(QStringLiteral("noneSelectedInfo"));
        label_4 = new QLabel(noneSelectedInformation);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        noneSelectedInfo->addWidget(label_4);


        verticalLayout_3->addWidget(noneSelectedInformation);

        oneSelectedInformation = new QWidget(centralWidget);
        oneSelectedInformation->setObjectName(QStringLiteral("oneSelectedInformation"));
        oneSelectedInfo = new QVBoxLayout(oneSelectedInformation);
        oneSelectedInfo->setSpacing(6);
        oneSelectedInfo->setContentsMargins(11, 11, 11, 11);
        oneSelectedInfo->setObjectName(QStringLiteral("oneSelectedInfo"));
        oneSelectedInfo->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(oneSelectedInformation);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        oneSelectedInfo->addWidget(label);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        iconLabel = new QLabel(oneSelectedInformation);
        iconLabel->setObjectName(QStringLiteral("iconLabel"));

        horizontalLayout_3->addWidget(iconLabel);

        nameLabel = new QLabel(oneSelectedInformation);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setWordWrap(true);

        horizontalLayout_3->addWidget(nameLabel);

        horizontalLayout_3->setStretch(1, 1);

        oneSelectedInfo->addLayout(horizontalLayout_3);


        verticalLayout_3->addWidget(oneSelectedInformation);

        multiSelectedInformation = new QWidget(centralWidget);
        multiSelectedInformation->setObjectName(QStringLiteral("multiSelectedInformation"));
        verticalLayout_6 = new QVBoxLayout(multiSelectedInformation);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(10, 10, 10, 10);
        label_5 = new QLabel(multiSelectedInformation);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_5);

        countLabel = new QLabel(multiSelectedInformation);
        countLabel->setObjectName(QStringLiteral("countLabel"));

        verticalLayout_6->addWidget(countLabel);


        verticalLayout_3->addWidget(multiSelectedInformation);

        tagListView = new QListView(centralWidget);
        tagListView->setObjectName(QStringLiteral("tagListView"));

        verticalLayout_3->addWidget(tagListView);

        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        verticalLayout_3->addWidget(openButton);


        horizontalLayout->addLayout(verticalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

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
        menuFile->addAction(actionQuit);
        menuTag->addAction(actionAjouter);
        menuTag->addAction(actionSupprimer);
        menuAide->addAction(actionDocumentation);

        retranslateUi(MainWindow);

        filterButton->setDefault(false);
        treeButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Marco Polo", Q_NULLPTR));
        actionFile->setText(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        actionQuit->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        actionSupprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        actionDocumentation->setText(QApplication::translate("MainWindow", "Documentation", Q_NULLPTR));
        filterButton->setText(QApplication::translate("MainWindow", "Filter", Q_NULLPTR));
        treeButton->setText(QApplication::translate("MainWindow", "Tree", Q_NULLPTR));
        parentButton->setText(QApplication::translate("MainWindow", "^_", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Selectionnez un fichier ou un dossier", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "INFORMATIONS", Q_NULLPTR));
        iconLabel->setText(QApplication::translate("MainWindow", "Icon", Q_NULLPTR));
        nameLabel->setText(QApplication::translate("MainWindow", "Nom de l'element", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "INFORMATIONS", Q_NULLPTR));
        countLabel->setText(QApplication::translate("MainWindow", "\303\211l\303\251ments s\303\251l\303\251ctionn\303\251s: X", Q_NULLPTR));
        openButton->setText(QApplication::translate("MainWindow", "Ouvrir", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        menuTag->setTitle(QApplication::translate("MainWindow", "Tags", Q_NULLPTR));
        menuAide->setTitle(QApplication::translate("MainWindow", "Aide", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
