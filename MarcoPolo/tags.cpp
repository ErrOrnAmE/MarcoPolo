#include "tags.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QJsonDocument>
#include <QDebug>

Tags::Tags()
{

}

void Tags::readConfig() {
   QFile loadFile(QStringLiteral("tags.json"));

   if (!loadFile.open(QIODevice::ReadWrite)) {
       qInfo("Couldn't open save file.");
   }

   QByteArray data = loadFile.readAll();

   QJsonDocument loadDoc(QJsonDocument::fromJson(data));

   tags = loadDoc.object().value(QString("tags")).toObject();

   qInfo() << tags.keys();
}
