#ifndef AOB_CATEGORY_H
#define AB_CATEGORY_H

#include <QMap>

#include "object.h"

namespace ao_builder
{
class Category : public Object
{
public:
    Category();
    virtual ~Category();

public:
    QString m_comment{};
    QString m_xAlteratorCategory{}; //Alterator Object X-Alterator-Category or Category

    QMap<QString, QString> m_commentLocaleStorage{};

    void setLocale(QString locale);
};
} // namespace objectbuilder

#endif // AB_CATEGORY_H
