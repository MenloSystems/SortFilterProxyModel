#ifndef ANYOFFILTER_H
#define ANYOFFILTER_H

#include "../qqsfpm_global.h"
#include "filtercontainerfilter.h"

namespace qqsfpm {

class QQSFPM_EXPORT AnyOfFilter : public FilterContainerFilter {
    Q_OBJECT

public:
    using FilterContainerFilter::FilterContainerFilter;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

}

#endif // ANYOFFILTER_H
