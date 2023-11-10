#include "object.h"
#include <QRegularExpression>

namespace model
{
void Object::setLocale(QString locale)
{
    setFieldLocale(locale, m_displayName, &m_nameLocaleStorage);
    setFieldLocale(locale, m_comment, &m_commentLocaleStorage);
}

void Object::setFieldLocale(QString locale, QString &field, QMap<QString, QString> *storage)
{
    auto nameIt = storage->find(locale);
    if (nameIt != storage->end())
    {
        field = *nameIt;
    }
    else
    {
        QRegularExpression regex(locale + "_[A-Z]{2}");
        for (auto &fullLoc : storage->keys())
        {
            QRegularExpressionMatch match = regex.match(fullLoc);
            if (match.hasMatch())
            {
                field = storage->value(fullLoc, field);
            }
        }
    }
}

} // namespace model
