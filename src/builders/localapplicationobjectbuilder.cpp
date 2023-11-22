#include "localapplicationobjectbuilder.h"

#include <memory>

namespace ao_builder
{
const QString LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME         = "Desktop Entry";
const QString LOCAL_APP_NAME_KEY_NAME                      = "Name";
const QString LOCAL_APP_GENERIC_NAME_KEY_NAME              = "Genericname";
const QString LOCAL_APP_COMMENT_KEY_NAME                   = "Comment";
const QString LOCAL_APP_TRY_EXEC_KEY_NAME                  = "Tryexec";
const QString LOCAL_APP_ICON_KEY_NAME                      = "Icon";
const QString LOCAL_APP_TYPE_KEY_NAME                      = "Type";
const QString LOCAL_APP_CATEGORIES_KEY_NAME                = "Categories";
const QString LOCAL_APP_KEYWORDS_KEY_NAME                  = "Keywords";
const QString LOCAL_APP_EXEC_KEY_NAME                      = "Exec";
const QString LOCAL_APP_MIMETYPE_KEY_NAME                  = "Mimetype";
const QString LOCAL_APP_ALTERATOR_ENTRY_SECTION_NAME       = "Alterator Entry";
const QString LOCAL_APP_ALTERATOR_ENTRY_SECTION_KEY_NAME   = "Exec";
const QString LOCAL_APP_ALTERATOR_ENTRY_SECTION_TYPE_VALUE = "Application";
const QString LOCAL_APP_ALTERATOR_INTERFACE_KEY_NAME       = "Interfaces";
const QString LOCAL_APP_ALTERATOR_ENTRYEXEC_KEY_NAME       = "Exec";

LocalApplicationObjectBuilder::LocalApplicationObjectBuilder() {}

LocalApplicationObjectBuilder::~LocalApplicationObjectBuilder() {}

std::unique_ptr<ao_builder::Object> LocalApplicationObjectBuilder::buildObject(ObjectParserInterface *parser)
{
    auto result = std::make_unique<LocalAppObject>();

    LocalAppObject *object = result.get();

    if (!parseDesktopEntrySection(parser, result.get()) || !parseAlteratorEntrySection(parser, result.get()))
    {
        return nullptr;
    }

    return result;
}

bool LocalApplicationObjectBuilder::parseDesktopEntrySection(ObjectParserInterface *parser,
                                                             LocalAppObject *localApplication)
{
    auto sections = parser->getSections();

    auto desktopEntrySectionIt = sections.find(LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME);
    if (desktopEntrySectionIt == sections.end())
    {
        return false;
    }

    ObjectParserInterface::Section desktopEntrySection = *desktopEntrySectionIt;

    if (!buildNames(parser, desktopEntrySection, localApplication)) // TODO: buildFieldWithLocale
    {
        return false;
    }

    if (!buildFieldWithLocale(parser,
                              desktopEntrySection,
                              LOCAL_APP_GENERIC_NAME_KEY_NAME,
                              localApplication->m_genericName,
                              localApplication->m_genericNameLocaleStorage))
    {}

    localApplication->m_displayName = localApplication->m_id;

    if (!buildFieldWithLocale(parser,
                              desktopEntrySection,
                              LOCAL_APP_COMMENT_KEY_NAME,
                              localApplication->m_displayComment,
                              localApplication->m_commentLocaleStorage))
    {}

    QString tryExec = parser->getValue(LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME, LOCAL_APP_TRY_EXEC_KEY_NAME);
    if (tryExec.isEmpty())
    {}
    localApplication->m_try_Exec = tryExec;

    QString exec = parser->getValue(LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME, LOCAL_APP_EXEC_KEY_NAME);
    if (exec.isEmpty())
    {
        return false;
    }
    localApplication->m_desktopExec = exec;

    QString icon = parser->getValue(LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME, LOCAL_APP_ICON_KEY_NAME);
    if (icon.isEmpty())
    {}
    localApplication->m_icon = icon;

    QString type = parser->getValue(LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME, LOCAL_APP_TYPE_KEY_NAME);
    if (type.isEmpty())
    {}
    localApplication->m_type = type;

    if (!buildFieldWithLocale(parser,
                              desktopEntrySection,
                              LOCAL_APP_KEYWORDS_KEY_NAME,
                              localApplication->m_displayKeywords,
                              localApplication->m_keywordsLocaleStorage))
    {}

    localApplication->m_mimeTypes = parseValuesFromKey(parser,
                                                       LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME,
                                                       LOCAL_APP_MIMETYPE_KEY_NAME,
                                                       ";");

    return true;
}

bool LocalApplicationObjectBuilder::parseAlteratorEntrySection(ObjectParserInterface *parser,
                                                               LocalAppObject *localApplication)
{
    //Parsing Alterator Entry Sections
    QString type = parser->getValue(LOCAL_APP_ALTERATOR_ENTRY_SECTION_NAME, LOCAL_APP_TYPE_KEY_NAME);
    if (type.isEmpty() || type != LOCAL_APP_ALTERATOR_ENTRY_SECTION_TYPE_VALUE)
    {
        return false;
    }

    localApplication->m_type = type;

    QString appName = parser->getValue(LOCAL_APP_ALTERATOR_ENTRY_SECTION_NAME, LOCAL_APP_NAME_KEY_NAME);

    if (appName.isEmpty())
    {
        return false;
    }

    localApplication->m_id = appName;

    QString appInterfaces = parser->getValue(LOCAL_APP_ALTERATOR_ENTRY_SECTION_NAME,
                                             LOCAL_APP_ALTERATOR_INTERFACE_KEY_NAME);
    if (!appInterfaces.isEmpty())
    {
        localApplication->m_interfaces.push_back(appInterfaces);
    }

    QString appExec = parser->getValue(LOCAL_APP_ALTERATOR_ENTRY_SECTION_NAME, LOCAL_APP_ALTERATOR_ENTRYEXEC_KEY_NAME);

    localApplication->m_exec = appExec;

    //Parsing Desktop Entry of application

    return true;
}
} // namespace ao_builder
