/***********************************************************************************************************************
**
** Copyright (C) 2022 BaseALT Ltd. <org@basealt.ru>
**
** This program is free software; you can redistribute it and/or
** modify it under the terms of the GNU General Public License
** as published by the Free Software Foundation; either version 2
** of the License, or (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
**
***********************************************************************************************************************/

#include "snapinmanageradapter.h"
#include "isnapin.h"

#include "pluginstorage.h"

#include <algorithm>

namespace gpui
{

class SnapInManagerAdapterPrivate
{
public:
    std::vector<ISnapIn const*> snapIns;
};

void SnapInManagerAdapter::addSnapIn(ISnapIn const* snapIn)
{
    d->snapIns.push_back(snapIn);
}

void SnapInManagerAdapter::removeSnapIn(ISnapIn const* snapIn)
{
    d->snapIns.erase(std::find(d->snapIns.begin(), d->snapIns.end(), snapIn));
}

std::vector<ISnapIn const*> SnapInManagerAdapter::getSnapIns() const
{
    return d->snapIns;
}

void SnapInManagerAdapter::clear()
{
    d->snapIns.clear();
}

ISnapInManager* SnapInManagerAdapter::instance()
{
    static SnapInManagerAdapter instance;

    return &instance;
}

SnapInManagerAdapter::SnapInManagerAdapter()
    : d(new SnapInManagerAdapterPrivate())
{
}

SnapInManagerAdapter::~SnapInManagerAdapter()
{
    delete d;
}

}
