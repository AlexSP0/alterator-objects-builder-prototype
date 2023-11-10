#include "objectitem.h"

namespace model
{
ObjectItem::ObjectItem()
    : m_object(nullptr)
    , m_type(ItemType::None)
{}

Object *ObjectItem::getObject()
{
    return m_object.get();
}

void ObjectItem::setObject(std::unique_ptr<Object> obj)
{
    if (obj)
    {
        m_object = std::move(obj);
    }
}

void ObjectItem::setType(ItemType type)
{
    m_type = type;
}

ObjectItem::ItemType ObjectItem::getType()
{
    return m_type;
}

} // namespace model
