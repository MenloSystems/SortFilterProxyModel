#ifndef VALUEFILTER_H
#define VALUEFILTER_H

#include "../qqsfpm_global.h"
#include "rolefilter.h"
#include <QVariant>

namespace qqsfpm {

class QQSFPM_EXPORT ValueFilter : public RoleFilter {
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    using RoleFilter::RoleFilter;

    const QVariant& value() const;
    void setValue(const QVariant& value);

protected:
    bool filterRow(const QModelIndex &sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;

Q_SIGNALS:
    void valueChanged();

private:
    QVariant m_value;
};

}

#endif // VALUEFILTER_H
