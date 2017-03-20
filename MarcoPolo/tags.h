#ifndef TAGS_H
#define TAGS_H

#include <QJsonObject>
#include <QListView>

class Tags
{
public:
    Tags();
    void readConfig();
    void writeConfig();
    void listTags(QListView *listView);
    QJsonObject tags;

    void addTag(QString name);
    void removeTag(QString name);
    void removeTags(QListView *listView);

private:
    QPixmap drawCircle(QString color);
};

#endif // TAGS_H
