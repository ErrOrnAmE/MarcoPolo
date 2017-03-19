#ifndef TAGS_H
#define TAGS_H

#include <QJsonObject>

class Tags
{
public:
    Tags();
    void readConfig();
    QJsonObject tags;

private:
};

#endif // TAGS_H
