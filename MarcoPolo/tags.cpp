#include "tags.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>

Tags::Tags()
{

}

void Tags::readConfig() {
   QFile loadFile(QStringLiteral("tags.json"));

   if (!loadFile.open(QIODevice::ReadOnly)) {
       qInfo("Couldn't open save file.");
   }

   QByteArray data = loadFile.readAll();

   QJsonDocument loadDoc(QJsonDocument::fromJson(data));

   tags = loadDoc.object().value(QString("tags")).toObject();

   qInfo() << tags.keys();
}

void Tags::listTags(QListView *listView) {
    QStandardItemModel *model = new QStandardItemModel();
    foreach (QString item, tags.toVariantMap()) {
        QStandardItem *line = new QStandardItem();
        line->setText(item);
        line->setData(drawCircle(QString("green")),Qt::DecorationRole);
        model->appendRow(line);
    }
    listView->setModel(model);
}

QPixmap Tags::drawCircle(QString color) {
    QPixmap *pix = new QPixmap(15,15);
    QPainter painter(pix);
    painter.setPen(QColor(255,255,255));
    painter.setBrush(QBrush(QColor(color)));
    painter.fillRect(0,0,15,15,QColor(255,255,255));
    painter.drawEllipse(1,1,13,13);
    return *pix;
}
