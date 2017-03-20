#ifndef TAGS_H
#define TAGS_H

#include <QJsonObject>
#include <QListView>

class Tags
{
public:
    Tags();
    void readConfig();
    void listTags(QListView *listView);
    QJsonObject tags;

private:
    QPixmap drawCircle(QString color);
};

#endif // TAGS_H
