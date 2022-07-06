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

#ifndef TEST_COMPOSITE_SNAP_IN_H
#define TEST_COMPOSITE_SNAP_IN_H

#include "abstractcompositesnapin.h"

namespace test
{
class TestCompositeSnapIn : public ::gpui::AbstractCompositeSnapIn
{
public:
    TestCompositeSnapIn()
        : ::gpui::AbstractCompositeSnapIn("ICompositeSnapIn",
                                          "TestSnapIn",
                                          "Help Text.",
                                          {0, 1, 2},
                                          "MIT",
                                          "BaseALT")
    {
        addDependency("Plugin 1", {1, 0, 0});
        addDependency("Plugin 2", {2, 10, 1});
    }

    void onInitialize() override {}

    void onShutdown() override {}
};

} // namespace test

#endif //TEST_COMPOSITE_SNAP_IN_H
