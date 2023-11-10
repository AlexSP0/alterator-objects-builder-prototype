#ifndef OBJECTITEM_H
#define OBJECTITEM_H

#include <memory>
#include <QStandardItem>

#include "object.h"

namespace model
{
class ObjectItem : public QStandardItem
{
public:
    enum class ItemType
    {
        None = QStandardItem::UserType + 1,
        Legacy,
        Category,
        Application
    };

public:
    ObjectItem();
    ~ObjectItem() override = default;

    Object *getObject();

    void setObject(std::unique_ptr<Object> obj);
    void setType(ItemType type);

    ItemType getType();

public:
    ObjectItem(const ObjectItem &) = delete;
    ObjectItem(ObjectItem &&)      = delete;
    ObjectItem &operator=(const ObjectItem &) = delete;
    ObjectItem &operator=(ObjectItem &&) = delete;

private:
    std::unique_ptr<Object> m_object;
    ItemType m_type;
};
} // namespace model

#endif // OBJECTITEM_H
