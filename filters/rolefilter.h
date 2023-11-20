#ifndef ROLEFILTER_H
#define ROLEFILTER_H

#include "../qqsfpm_global.h"
#include "filter.h"

namespace qqsfpm {

class QQSFPM_EXPORT RoleFilter : public Filter
{
    Q_OBJECT
    Q_PROPERTY(QString roleName READ roleName WRITE setRoleName NOTIFY roleNameChanged)

public:
    using Filter::Filter;

    const QString& roleName() const;
    void setRoleName(const QString& roleName);

Q_SIGNALS:
    void roleNameChanged();

protected:
    QVariant sourceData(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const;

private:
    QString m_roleName;
};

}

#endif // ROLEFILTER_H
