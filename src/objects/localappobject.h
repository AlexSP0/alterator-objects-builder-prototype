#ifndef AB_LOCAL_APPLICATION_H
#define AB_LOCAL_APPLICATION_H

#include <vector>
#include <QMap>
#include <QString>

#include "basicobject.h"

namespace objectbuilder
{
class LocalAppObject : public BasicObject
{
public:
    LocalAppObject();
    virtual ~LocalAppObject();

    virtual void setLocale(QString locale) override;

public:
    QString m_genericName{};            //Desktop Entry Section
    QString m_displayComment{};         //Desktop Entry Section
    QString m_try_Exec{};               //Desktop Entry Section
    QString m_desktopExec{};            //Desktop Entry Section
    QString m_displayKeywords{};        //Desktop Entry Section
    std::vector<QString> m_mimeTypes{}; //Desktop Entry Sections
    bool isTerminal{false};

    QString m_exec{};                    //Alterator Entry Section
    std::vector<QString> m_interfaces{}; //Alterator Entry Section

    QMap<QString, QString> m_genericNameLocaleStorage{}; //Translations for m_genericName
    QMap<QString, QString> m_commentLocaleStorage{};     //Traslations for m_displayComment
    QMap<QString, QString> m_keywordsLocaleStorage{};    //Translations for m_displayKeywords
};
} // namespace objectbuilder

#endif // AB_LOCAL_APPLICATION_H
