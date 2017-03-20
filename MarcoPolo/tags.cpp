#include "tags.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QDebug>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QPainter>
#include <QJsonArray>

Tags::Tags()
{

}

void Tags::readConfig() {
   QFile loadFile(QStringLiteral("tags.json"));

   if (!loadFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
       qInfo("Couldn't open save file.");
   }

   QByteArray data = loadFile.readAll();

   loadFile.close();

   QJsonDocument loadDoc(QJsonDocument::fromJson(data));

   tags = loadDoc.object().value(QString("tags")).toObject();

   qInfo() << tags.keys();
}

void Tags::writeConfig() {
    QFile loadFile(QStringLiteral("tags.json"));

    if (!loadFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qInfo("Couldn't open save file.");
    }

    QJsonObject x;
    x.insert(QString("tags"),tags);
    QJsonDocument doc(x);
    loadFile.write(doc.toJson());

    loadFile.close();
}

void Tags::listTags(QListView *listView) {
    QStandardItemModel *model = new QStandardItemModel();
    for (auto item : tags.keys()) {
        QStandardItem *line = new QStandardItem();
        line->setText(item);
        line->setData(drawCircle(tags.value(item).toObject().value(QString("color")).toString()),Qt::DecorationRole);
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

void Tags::addTag(QString name) {

    QString colors[8] = {"red","blue","green","yellow","purple","cyan","lime","grey"};

    int number = 8;
    int randomValue = qrand() % number;

    QJsonObject o;

    QJsonValue color(QString(colors[randomValue]));
    o.insert(QString("color"),color);

    QJsonArray files;
    o.insert(QString("files"),files);

    tags.insert(name,o);

    writeConfig();
}

void Tags::removeTag(QString name) {
    tags.remove(name);
}

void Tags::removeTags(QListView *listView) {
    for(auto e : listView->selectionModel()->selection()) {
        removeTag(e.topLeft().data().toString());
    }
}
