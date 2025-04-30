/********************************************************************************
** Form generated from reading UI file 'pdfviewer.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PDFVIEWER_H
#define UI_PDFVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pdfviewer
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pdfviewer)
    {
        if (pdfviewer->objectName().isEmpty())
            pdfviewer->setObjectName("pdfviewer");
        pdfviewer->resize(800, 600);
        actionOpen = new QAction(pdfviewer);
        actionOpen->setObjectName("actionOpen");
        actionExport = new QAction(pdfviewer);
        actionExport->setObjectName("actionExport");
        centralwidget = new QWidget(pdfviewer);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(listWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMinimumSize(QSize(400, 300));

        verticalLayout->addWidget(graphicsView);

        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);


        horizontalLayout->addLayout(verticalLayout);

        pdfviewer->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pdfviewer);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        pdfviewer->setMenuBar(menubar);
        statusbar = new QStatusBar(pdfviewer);
        statusbar->setObjectName("statusbar");
        pdfviewer->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport);

        retranslateUi(pdfviewer);

        QMetaObject::connectSlotsByName(pdfviewer);
    } // setupUi

    void retranslateUi(QMainWindow *pdfviewer)
    {
        pdfviewer->setWindowTitle(QCoreApplication::translate("pdfviewer", "PDF Viewer", nullptr));
        actionOpen->setText(QCoreApplication::translate("pdfviewer", "Open PDF", nullptr));
        actionExport->setText(QCoreApplication::translate("pdfviewer", "Export Page", nullptr));
        menuFile->setTitle(QCoreApplication::translate("pdfviewer", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pdfviewer: public Ui_pdfviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PDFVIEWER_H
