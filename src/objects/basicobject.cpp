#include "basicobject.h"

namespace objectbuilder
{
BasicObject::BasicObject()
    : Object()
{}

BasicObject::~BasicObject() {}

void BasicObject::setLocale(QString locale)
{
    Object::setLocale(locale);
}

} // namespace objectbuilder
