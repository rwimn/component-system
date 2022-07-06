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

#ifndef SNAP_IN_LOADER_H
#define SNAP_IN_LOADER_H

#include <QDir>

namespace gpui
{

class ISnapInManager;

class SnapInLoaderPrivate;

class SnapInLoader
{
public:
    SnapInLoader(ISnapInManager* manager);
    ~SnapInLoader();

    void loadSnapIns(const QDir& snapInDirectory);

private:
    SnapInLoaderPrivate* d;
};

}

#endif//SNAP_IN_LOADER_H
