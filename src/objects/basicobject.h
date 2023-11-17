#ifndef AB_BASICOBJECT_H
#define AB_BASICOBJECT_H

#include <QString>

#include "object.h"

namespace objectbuilder
{
class BasicObject : public Object
{
public:
    BasicObject();
    virtual ~BasicObject();

    virtual void setLocale(QString locale) override;

public:
    QString m_categoryId{};

    bool m_isLegacy{false};
};

} // namespace objectbuilder

#endif // BASICOBJECT_H
