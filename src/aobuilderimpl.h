#ifndef AOBUILDERIMPL_H
#define AOBUILDERIMPL_H

#include "aobuilderinterface.h"

namespace ao_builder
{
class AOBuilderImpl : public AOBuilderInterface
{
public:
    AOBuilderImpl();

    // AOBuilderInterface interface
public:
    QStringList getLegacyObjectsPaths();
    std::unique_ptr<Object> buildLegacyObject(QString path);

    QStringList getLocalAppsPaths();
    std::unique_ptr<Object> buildLocalAppObject(QString path);

    QStringList getCategoriesList();
    std::unique_ptr<Object> buildCategoryObject(QString path);

    QStringList getObjectsPaths();
    std::unique_ptr<Object> buildObject(QString path);
};

} // namespace ao_builder

#endif // AOBUILDERIMPL_H
