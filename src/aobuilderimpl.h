#ifndef AOB_BUILDER_IMPL_H
#define AOB_BUILDER_IMPL_H

#include "aobuilderinterface.h"

namespace ao_builder
{
class AOBuilderImplPrivate;

class AOBuilderImpl final : public AOBuilderInterface
{
public:
    AOBuilderImpl();
    ~AOBuilderImpl();

    // AOBuilderInterface interface
public:
    QStringList getLegacyObjectsPaths() override;
    QStringList getLocalAppsPaths() override;
    QStringList getCategoriesList() override;
    QStringList getObjectsPaths() override;

    std::unique_ptr<Object> buildObject(QString path, QString interface) override;

private:
    AOBuilderImplPrivate *d;

private:
    AOBuilderImpl(const AOBuilderImpl &) = delete;
    AOBuilderImpl(AOBuilderImpl &&)      = delete;
    AOBuilderImpl &operator=(const AOBuilderImpl &) = delete;
    AOBuilderImpl &operator=(AOBuilderImpl &&) = delete;
};

} // namespace ao_builder

#endif // AOB_BUILDER_IMPL_H
