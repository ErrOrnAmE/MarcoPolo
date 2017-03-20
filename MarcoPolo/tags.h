#ifndef TAGS_H
#define TAGS_H

#include <QJsonObject>
#include <QListView>
#include <QStringList>

class Tags
{
public:
    Tags();
    void readConfig();
    void writeConfig();
    void listTags(QListView *listView);
    void listTags(QListView *listView, QString search);
    void listTags(QListView *listView, QJsonArray linkedTags);
    void listTags(QListView *to, QListView *from);
    QJsonObject tags;

    void addTag(QString name);
    void addTags(QListView *listView, QString path);
    void removeTag(QString name);
    void removeTags(QListView *listView);
    void removeTags(QListView *listView, QString path);

    QJsonArray listFileTags(QString path);
    QStringList listFiles(QListView *listView);

private:
    QPixmap drawCircle(QString color);
};

#endif // TAGS_H
