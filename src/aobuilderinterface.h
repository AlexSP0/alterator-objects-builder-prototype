#ifndef AOB_ALTERATOR_OBJECT_BUILDER_INTERFACE_H
#define AOB_ALTERATOR_OBJECT_BUILDER_INTERFACE_H

#include <memory>
#include <QString>

#include <objects/object.h>

namespace ao_builder
{
class AOBuilderInterface
{
public:
    virtual ~AOBuilderInterface() = default;

public:
    /**
     * @brief getLegacyObjectsPaths Gets list of legacy objects paths on DBus
     * @return List of legacy objects paths on DBus
     */
    virtual QStringList getLegacyObjectsPaths() = 0;

    /**
     * @brief Builds a LegacyObject by getting information from DBus
     * @param path Path to object on the DBus
     * @return unique_ptr with builded LegacyObject or nullptr in case of failure
     */
    virtual std::unique_ptr<Object> buildLegacyObject(QString path) = 0;

    /**
     * @brief getLocalAppsPaths Gets list of Local Application objects paths on DBus
     * @return List of local applications objects paths on DBus
     */

    virtual QStringList getLocalAppsPaths() = 0;
    /**
     * @brief Builds a LocalAppObject by getting information from DBus
     * @param path Path to object on the DBus
     * @return unique_ptr with builded LocalAppObject or nullptr in case of failure
     */
    virtual std::unique_ptr<Object> buildLocalAppObject(QString path) = 0;

    /**
     * @brief getCategoriesList Gets list of object categories on DBus
     * @return List of object categories
     */
    virtual QStringList getCategoriesList() = 0;

    /**
     * @brief buildCategoryObject Builds a CategoryObject by getting information from DBus
     * @param path Path to Category object on the DBus
     * @return unique_ptr with builded CategoryObject or nullptr in case of failure
     */
    virtual std::unique_ptr<Object> buildCategoryObject(QString path) = 0;

    /**
     * @brief getObjectsPaths Builds a LocalAppObject by getting information from DBus
     * @return List of objects paths on DBus
     */
    virtual QStringList getObjectsPaths() = 0;

    /**
     * @brief buildObject
     * @param path Path to object on the DBus
     * @return unique_ptr with builded Object or nullptr in case of failure
     */
    virtual std::unique_ptr<Object> buildObject(QString path) = 0;
};
} // namespace ao_builder

#endif // AOB_ALTERATOR_OBJECT_BUILDER_INTERFACE_H
