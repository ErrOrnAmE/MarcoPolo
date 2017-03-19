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
    QVBoxLayout *leftPanel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *filterButton;
    QPushButton *treeButton;
    QListView *tagView;
    QTreeView *treeView;
    QVBoxLayout *centerPanel;
    QGridLayout *pathBar;
    QLineEdit *pathEdit;
    QPushButton *parentButton;
    QPushButton *clearButton;
    QLineEdit *tagsEdit;
    QTableView *tableView;
    QVBoxLayout *rightPanel;
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
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("QVBoxLayout#centerPanel {\n"
"	border : 1px solid #264ca4ae\n"
"}\n"
"\n"
"QWidget {\n"
"	background-color : white;\n"
"	border: 0px solide transparent;\n"
"}\n"
"QListWidget#listWidget, QTreeView#treeView {\n"
"	background-color : #334ca4ae;\n"
"}\n"
"QMenuBar {\n"
"	background-color : #1D4ca4ae\n"
"}\n"
"\n"
"QPushButton {\n"
"	border : 0px solid transparent;\n"
"	min-width:20px;\n"
"	padding: 5px 0px 5px 0px;\n"
"	color:#212121\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color : #334ca4ae\n"
"}\n"
"QPushButton#openButton {\n"
"	background-color : #204ca4ae;\n"
"}\n"
"\n"
"QPushButton#filterButton, QPushButton#treeButton {\n"
"	border: 0px solid transparent; }\n"
"QPushButton#filterButton:!focus, QPushButton#treeButton:!focus {\n"
"	background-color : #1D4ca4ae;\n"
"}\n"
"QPushButton#filterButton:default, QPushButton#treeButton:default {\n"
"	background-color : #334ca4ae;\n"
"	color:white;\n"
"	font-weight: bold;\n"
"	border-top: 1px solid #4ca4ae;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color : #2"
                        "64ca4ae;\n"
"}\n"
"\n"
"QTreeView::item:hover {background-color : #404ca4ae;}\n"
"QTreeView::item:selected {background-color : #804ca4ae; color:white}\n"
"QTableView::item:hover {background-color : #404ca4ae;}\n"
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
" QScrollBar::sub-line:vertical {\n"
"     background: #FAFAFA;\n"
"     height: 20px;\n"
"     subcontrol-position: top;\n"
"     subcontrol-origin: margin;\n"
" }\n"
" QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"     width: 3px;\n"
"     height: 3px;\n"
"     background: #4c"
                        "a4ae;\n"
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
        centralWidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftPanel = new QVBoxLayout();
        leftPanel->setSpacing(0);
        leftPanel->setObjectName(QStringLiteral("leftPanel"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filterButton = new QPushButton(centralWidget);
        filterButton->setObjectName(QStringLiteral("filterButton"));
        filterButton->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/ic_filter.png"), QSize(), QIcon::Normal, QIcon::Off);
        filterButton->setIcon(icon);
        filterButton->setCheckable(false);
        filterButton->setFlat(false);

        horizontalLayout_2->addWidget(filterButton);

        treeButton = new QPushButton(centralWidget);
        treeButton->setObjectName(QStringLiteral("treeButton"));
        treeButton->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/ic_arbo.png"), QSize(), QIcon::Normal, QIcon::Off);
        treeButton->setIcon(icon1);

        horizontalLayout_2->addWidget(treeButton);


        leftPanel->addLayout(horizontalLayout_2);

        tagView = new QListView(centralWidget);
        tagView->setObjectName(QStringLiteral("tagView"));
        tagView->setEnabled(true);
        tagView->setAutoFillBackground(false);
        tagView->setViewMode(QListView::ListMode);
        tagView->setStyleSheet(QStringLiteral(""));

        leftPanel->addWidget(tagView);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setEnabled(true);
        treeView->setAutoFillBackground(false);
        treeView->setStyleSheet(QStringLiteral(""));

        leftPanel->addWidget(treeView);


        horizontalLayout->addLayout(leftPanel);

        centerPanel = new QVBoxLayout();
        centerPanel->setSpacing(0);
        centerPanel->setObjectName(QStringLiteral("centerPanel"));
        pathBar = new QGridLayout();
        pathBar->setSpacing(0);
        pathBar->setObjectName(QStringLiteral("pathBar"));
        pathEdit = new QLineEdit(centralWidget);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setStyleSheet(QStringLiteral(""));
        pathEdit->setEnabled(true);

        pathBar->addWidget(pathEdit, 0, 1, 1, 1);

        parentButton = new QPushButton(centralWidget);
        parentButton->setObjectName(QStringLiteral("parentButton"));
        parentButton->setMaximumSize(QSize(30, 25));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/ic_subdirectory.png"), QSize(), QIcon::Normal, QIcon::Off);
        parentButton->setIcon(icon2);

        pathBar->addWidget(parentButton, 0, 0, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setMaximumSize(QSize(25, 25));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/ic_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon3);

        pathBar->addWidget(clearButton, 0, 3, 1, 1);

        tagsEdit = new QLineEdit(centralWidget);
        tagsEdit->setObjectName(QStringLiteral("tagsEdit"));
        tagsEdit->setStyleSheet(QStringLiteral(""));

        pathBar->addWidget(tagsEdit, 0, 2, 1, 1);


        centerPanel->addLayout(pathBar);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setShowGrid(false);
        tableView->verticalHeader()->setVisible(false);
        tableView->verticalHeader()->setDefaultSectionSize(23);

        centerPanel->addWidget(tableView);


        horizontalLayout->addLayout(centerPanel);

        rightPanel = new QVBoxLayout();
        rightPanel->setSpacing(0);
        rightPanel->setObjectName(QStringLiteral("rightPanel"));
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


        rightPanel->addWidget(noneSelectedInformation);

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


        rightPanel->addWidget(oneSelectedInformation);

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


        rightPanel->addWidget(multiSelectedInformation);

        tagListView = new QListView(centralWidget);
        tagListView->setObjectName(QStringLiteral("tagListView"));

        rightPanel->addWidget(tagListView);

        openButton = new QPushButton(centralWidget);
        openButton->setObjectName(QStringLiteral("openButton"));

        rightPanel->addWidget(openButton);


        horizontalLayout->addLayout(rightPanel);

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
        filterButton->setText(QString());
        treeButton->setText(QString());
        parentButton->setText(QString());
        clearButton->setText(QString());
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
