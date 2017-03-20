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

void Tags::listTags(QListView *listView, QJsonArray linkedTags) {
    QStandardItemModel *model = new QStandardItemModel();
    for (auto item : linkedTags) {
        QStandardItem *line = new QStandardItem();
        QString name = item.toObject().keys().at(0);
        line->setText(name);
        line->setData(drawCircle(item.toObject().value(name).toObject().value(QString("color")).toString()),Qt::DecorationRole);
        model->appendRow(line);
    }
    listView->setModel(model);
}

void Tags::listTags(QListView *to, QListView *from) {
    QStandardItemModel *model = new QStandardItemModel();
    for (auto e : from->selectionModel()->selection()) {
        QJsonObject item = tags.value(e.topLeft().data().toString()).toObject();
        QStandardItem *line = new QStandardItem();
        QString name = e.topLeft().data().toString();
        line->setText(name);
        line->setData(drawCircle(item.value(QString("color")).toString()),Qt::DecorationRole);
        model->appendRow(line);
    }
    to->setModel(model);
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

    if (tags.contains(name))
        return;

    QString colors[8] = {"red","blue","green","yellow","purple","cyan","lime","grey"};

    int number = 8;
    int randomValue = qrand() % number;

    QJsonObject o;

    //qInfo() << QJsonValue(QString(colors[randomValue]));
    //QJsonValue color(QString(colors[randomValue]));
    o.insert(QString("color"),QJsonValue(QString(colors[randomValue])));

    QJsonArray files;
    o.insert(QString("files"),files);

    tags.insert(name,o);

    writeConfig();
}

void Tags::addTags(QListView *listView, QString path) {
    for(auto e : listView->selectionModel()->selection()) {
        qInfo() << e.topLeft().data().toString();
        QJsonObject tag = tags.value(e.topLeft().data().toString()).toObject();

        qInfo() << tag;

        QJsonArray files = tag.value("files").toArray();

        qInfo() << files;

        if(!files.contains(QJsonValue(path)))
            files.append(path);

        qInfo() << files;

        tag.insert("files",files);

        tags.insert(e.topLeft().data().toString(),tag);
    }
}

void Tags::removeTag(QString name) {
    tags.remove(name);
}

void Tags::removeTags(QListView *listView) {
    for(auto e : listView->selectionModel()->selection()) {
        removeTag(e.topLeft().data().toString());
    }
}

void Tags::removeTags(QListView *listView, QString path) {
    for (auto e : listView->selectionModel()->selection()) {
        QJsonObject tag = tags.value(e.topLeft().data().toString()).toObject();

        QJsonArray files = tag.value("files").toArray();

        files.removeAt(files.toVariantList().indexOf(path));

        tag.insert("files",files);

        tags.insert(e.topLeft().data().toString(),tag);
    }
}

QJsonArray Tags::listFileTags(QString path) {
    QJsonArray linkedTags;
    for (auto e : tags.keys()) {
        if (tags.value(e).toObject().value(QString("files")).toArray().contains(path)) {
            QJsonObject i;
            i.insert(e,tags.value(e));
            linkedTags.append(i);
        }
    }
    return linkedTags;
}

QStringList Tags::listFiles(QListView *listView) {
    QStringList files;
    for (auto e : listView->selectionModel()->selection()) {
        QJsonArray tagFiles = tags.value(e.topLeft().data().toString()).toObject().value("files").toArray();
        for (auto f : tagFiles) {
            if (!files.contains(f.toString()))
                files.append(f.toString());
        }
    }
    return files;
}
