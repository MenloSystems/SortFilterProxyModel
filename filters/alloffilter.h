#ifndef ALLOFFILTER_H
#define ALLOFFILTER_H

#include "../qqsfpm_global.h"
#include "filtercontainerfilter.h"

namespace qqsfpm {

class QQSFPM_EXPORT AllOfFilter : public FilterContainerFilter {
    Q_OBJECT

public:
    using FilterContainerFilter::FilterContainerFilter;

protected:
    bool filterRow(const QModelIndex& sourceIndex, const QQmlSortFilterProxyModel& proxyModel) const override;
};

}

#endif // ALLOFFILTER_H
