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

#ifndef _SNAPINMANAGERADAPTER_H
#define _SNAPINMANAGERADAPTER_H

#include "isnapinmanager.h"
#include "isnapin.h"

namespace gpui
{

class SnapInManagerAdapterPrivate;

/**
 * @brief The SnapInManagerAdapter class This class adapts PluginStorage to provide ISnapInManager interface.
 */
class SnapInManagerAdapter final : public ISnapInManager
{
public:
    ~SnapInManagerAdapter();

    void addSnapIn(ISnapIn* snapIn) override final;

    void removeSnapIn(ISnapIn* snapIn) override final;

    std::vector<ISnapIn*> getSnapIns() const override final;

    void clear() override final;

    /**
     * Get the instance of a snap-in manager.
     */
    static ISnapInManager* instance();

private:
    SnapInManagerAdapter();

    SnapInManagerAdapter(const SnapInManagerAdapter&)            = delete;   // copy ctor
    SnapInManagerAdapter(SnapInManagerAdapter&&)                 = delete;   // move ctor
    SnapInManagerAdapter& operator=(const SnapInManagerAdapter&) = delete;   // copy assignment
    SnapInManagerAdapter& operator=(SnapInManagerAdapter&&)      = delete;   // move assignment

private:
    SnapInManagerAdapterPrivate *d;
};

}

#endif  //_SNAPINMANAGERADAPTER_H
