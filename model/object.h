#ifndef OBJECT_H
#define OBJECT_H

#include <QMap>
#include <QString>

namespace model
{
class Object
{
public:
    virtual ~Object() = default;

    QString m_id{};
    QString m_displayName{};
    QString m_comment{};
    QString m_type{};
    QString m_icon{};

    std::vector<QString> m_interfaces{};

    QMap<QString, QString> m_nameLocaleStorage{};
    QMap<QString, QString> m_commentLocaleStorage{};

    virtual void setLocale(QString locale);

private:
    void setFieldLocale(QString locale, QString &field, QMap<QString, QString> *storage);
};

} // namespace model

#endif
