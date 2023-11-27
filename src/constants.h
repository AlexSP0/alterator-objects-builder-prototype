#ifndef AOB_CONSTANTS_H
#define AOB_CONSTANTS_H

#include <QString>
namespace ao_builder
{
//Service name
const char *const DBUS_SERVICE_NAME = "ru.basealt.alterator";

//Methods names
const char *const DBUS_GET_OBJECTS_METHOD_NAME         = "GetObjects";
const char *const DBUS_OBJECT_METHOD_INFO_DEFAULT_NAME = "Info";
const char *const DBUS_OBJECT_METHOD_LIST_DEFAULT_NAME = "List";
const char *const DBUS_RUN_LEGACY_OBJECTS_METHOD_NAME  = "Run";
const char *const DBUS_INFO_METHOD_NAME_FOR_OBJECT     = "Info";
const char *const DBUS_CATEGORY_LIST_METHOD_NAME       = "List";
const char *const DBUS_CATEGORY_INFO_METHOD_NAME       = "Info";
const char *const DBUS_LOCAL_APP_GET_LIST_OF_FILES     = "List";
const char *const DBUS_LOCAL_APP_GET_DESKTOP_FILE      = "Info";

//DBus objects paths
const char *const DBUS_ALTERATOR_MANAGER_PATH = "/ru/basealt/alterator";
const char *const DBUS_CATEGORY_OBJECT_PATH   = "/ru/basealt/alterator/global";
const char *const DBUS_LOCAL_APP_OBJECT_PATH  = "/ru/basealt/alterator/global";

//Names of DBus interfaces
const char *const DBUS_MANAGER_INTERFACE_NAME          = "ru.basealt.alterator.manager";
const char *const DBUS_CATEGORY_OBJECT_INTERFACE_NAME  = "ru.basealt.alterator.categories";
const char *const DBUS_LOCAL_APP_OBJECT_INTERFACE_NAME = "ru.basealt.alterator.applications";
const char *const DBUS_LEGACY_OBJECT_INTERFACE_NAME    = "ru.basealt.alterator.legacy";
const char *const DBUS_OBJECT_INTERFACE_NAME           = "ru.basealt.alterator.object";

//Names of DBus interfaces
const char *const DBUS_CATEGORIES_OBJECTS_INTERFACE_NAME = "category";
const char *const DBUS_LOCAL_APPS_INTERFACE_NAME         = "application";
const char *const DBUS_LEGACY_OBJECTS_INTERFACE_NAME     = "legacy";
const char *const DBUS_OBJECTS_INTERFACE_NAME            = "object";

//Sections names in object info
const char *const ALTERATOR_ENTRY_SECTION_NAME    = "Alterator Entry";
const char *const DESKTOP_ENTRY_SECTION_NAME      = "Desktop Entry";
const char *const ALTERATOR_ENTRY_TYPE_KEY_NAME   = "Type";
const char *const ALTERATOR_ENTRY_OBJECT_KEY_NAME = "Name";

//
const char *const KEY_TYPE_VALUE_FOR_APPLICATION_OBJECT = "Application";
const char *const KEY_TYPE_VALUE_FOR_CATEGORY_OBJECT    = "Category";
const char *const KEY_TYPE_VALUE_FOR_OBJECT             = "Object";

//Objects fields names

//Local applications keys and values
const QString LOCAL_APP_DESKTOP_ENTRY_SECTION_NAME         = "Desktop Entry";
const QString LOCAL_APP_NAME_KEY_NAME                      = "Name";
const QString LOCAL_APP_GENERIC_NAME_KEY_NAME              = "Genericname";
const QString LOCAL_APP_COMMENT_KEY_NAME                   = "Comment";
const QString LOCAL_APP_TRY_EXEC_KEY_NAME                  = "Tryexec";
const QString LOCAL_APP_ICON_KEY_NAME                      = "Icon";
const QString LOCAL_APP_CATEGORIES_KEY_NAME                = "Categories";
const QString LOCAL_APP_KEYWORDS_KEY_NAME                  = "Keywords";
const QString LOCAL_APP_EXEC_KEY_NAME                      = "Exec";
const QString LOCAL_APP_MIMETYPE_KEY_NAME                  = "Mimetype";
const QString LOCAL_APP_ALTERATOR_ENTRY_SECTION_KEY_NAME   = "Exec";
const QString LOCAL_APP_ALTERATOR_ENTRY_SECTION_TYPE_VALUE = "Application";
const QString LOCAL_APP_ALTERATOR_INTERFACE_KEY_NAME       = "Interfaces";
const QString LOCAL_APP_ALTERATOR_ENTRYEXEC_KEY_NAME       = "Exec";

//Category keys and values
const QString CATEGORY_COMMENT_KEY_NAME              = "Comment";
const QString CATEGORY_ICON_KEY_NAME                 = "Icon";
const QString CATEGORY_TYPE_KEY_VALUE                = "Category";
const QString CATEGORY_X_ALTERATOR_CATEGORY_KEY_NAME = "X-alterator-category";

} // namespace ao_builder

#endif // AB_CONSTANTS_H
