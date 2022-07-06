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

#ifndef MOCK_SNAP_IN_MANAGER_H
#define MOCK_SNAP_IN_MANAGER_H

#include "isnapinmanager.h"
#include "isnapin.h"

#include <gmock/gmock.h>

#include <vector>

namespace test
{
    class MockSnapInManager : public ::gpui::ISnapInManager
    {
    public:
         MOCK_CONST_METHOD0(getSnapIns, std::vector<::gpui::ISnapIn*>());

         MOCK_METHOD1(addSnapIn, void(::gpui::ISnapIn*));

         MOCK_METHOD1(removeSnapIn, void(::gpui::ISnapIn*));

         MOCK_METHOD0(clear, void());

         MOCK_METHOD0(getInstance, ::gpui::ISnapInManager*());
    };
}

#endif//MOCK_SNAP_IN_MANAGER_H

