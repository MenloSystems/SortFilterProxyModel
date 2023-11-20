#ifndef FILTERCONTAINERFILTER_H
#define FILTERCONTAINERFILTER_H

#include "../qqsfpm_global.h"
#include "filter.h"
#include "filtercontainer.h"

namespace qqsfpm {

class QQSFPM_EXPORT FilterContainerFilter : public Filter, public FilterContainer {
    Q_OBJECT
    Q_INTERFACES(qqsfpm::FilterContainer)
    Q_PROPERTY(QQmlListProperty<qqsfpm::Filter> filters READ filtersListProperty NOTIFY filtersChanged)
    Q_CLASSINFO("DefaultProperty", "filters")

public:
    using Filter::Filter;

    void proxyModelCompleted(const QQmlSortFilterProxyModel& proxyModel) override;

Q_SIGNALS:
    void filtersChanged();

private:
    void onFilterAppended(Filter* filter) override;
    void onFilterRemoved(Filter* filter) override;
    void onFiltersCleared() override;
};

}

#endif // FILTERCONTAINERFILTER_H
