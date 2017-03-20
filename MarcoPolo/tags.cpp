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
#include <string>

using namespace std;

Tags::Tags()
{

}

/*!
 * \brief Read the json file with the tags and associations
 */
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

/*!
 * \brief Write the json file with the tags and associations
 */
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

/*!
 * \brief List tags into given QListView
 * \param QListView listView
 */
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

/*!
 * \brief List tags corresponding to given search into given QListView
 * \param QListView listView
 * \param QString search
 */
void Tags::listTags(QListView *listView, QString search) {
    QStandardItemModel *model = new QStandardItemModel();
    for (auto item : tags.keys()) {
        if(item.contains(search, Qt::CaseInsensitive)){
            QStandardItem *line = new QStandardItem();
            line->setText(item);
            line->setData(drawCircle(tags.value(item).toObject().value(QString("color")).toString()),Qt::DecorationRole);
            model->appendRow(line);
        }
    }
    listView->setModel(model);
}

/*!
 * \brief List tags corresponding to givent tags into given QListView
 * \param QListView listView
 * \param QString linkedTags
 */
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

/*!
 * \brief Draw a circle icon with given color
 * \param QString color
 * \return QPixmap
 */
QPixmap Tags::drawCircle(QString color) {
    QPixmap *pix = new QPixmap(15,15);
    QPainter painter(pix);
    painter.setPen(QColor(77,164,174));
    painter.setBrush(QBrush(QColor(color)));
    painter.fillRect(0,0,15,15,QColor(219,237,239));
    painter.drawEllipse(1,1,13,13);
    return *pix;
}

/*!
 * \brief Create a tag with given name
 * \param QString name
 */
void Tags::addTag(QString name) {

    if (tags.contains(name))
        return;

    QString colors[26] = {
        "#4ca4ac",
        "#ed87bb",
        "#ff7373",
        "#890045",
        "#c38ed7",
        "#488957",
        "#ffd700",
        "#536283",
        "#eb2629",
        "#1da1db",
        "#24cc8c",
        "#2988df",
        "#ff9c20",
        "#a832c9",
        "#ee33c0",
        "#db0939",
        "#db3939",
        "#db6939",
        "#db9939",
        "#dbc939",
        "#ffdd8d",
        "#ddb6ff",
        "#c2bdfb",
        "#8f9cff",
        "#ff6080"
    };

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

/*!
 * \brief Associate tags to a file
 * \param QListView listView
 * \param QString path
 */
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

/*!
 * \brief Delete a tag
 * \param QString name
 */
void Tags::removeTag(QString name) {
    tags.remove(name);
}

/*!
 * \brief Delete tags
 * \param QListView listView
 */
void Tags::removeTags(QListView *listView) {
    for(auto e : listView->selectionModel()->selection()) {
        removeTag(e.topLeft().data().toString());
    }
}

/*!
 * \brief Dissociate tags from a file
 * \param QListView listView
 * \param QString path
 */
void Tags::removeTags(QListView *listView, QString path) {
    for (auto e : listView->selectionModel()->selection()) {
        QJsonObject tag = tags.value(e.topLeft().data().toString()).toObject();

        QJsonArray files = tag.value("files").toArray();

        files.removeAt(files.toVariantList().indexOf(path));

        tag.insert("files",files);

        tags.insert(e.topLeft().data().toString(),tag);
    }
}

/*!
 * \brief List tags associated to a file
 * \param QString path
 * \return QJsonArray
 */
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

/*!
 * \brief List files associated with filtered tags
 * \param QListView listView
 * \return QStringList
 */
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
