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

#include "snapinmanagertest.h"

#include "snapinmanager.h"

using namespace ::testing;
using namespace ::gpui;

namespace test
{

TEST_F(SnapInManagerTest, AddSnapInTest)
{
    snapInManager.addSnapIn(&snapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 1);
}

TEST_F(SnapInManagerTest, RemoveExistingSnapInTest)
{
    snapInManager.addSnapIn(&snapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 1);

    snapInManager.removeSnapIn(&snapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 0);
}

TEST_F(SnapInManagerTest, RemoveNullptrTest)
{
    snapInManager.removeSnapIn(nullptr);
}

TEST_F(SnapInManagerTest, RemoveNotAddedSnapInTest)
{
    snapInManager.addSnapIn(&snapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 1);

    ::test::MockSnapIn secondSnapIn;

    snapInManager.removeSnapIn(&secondSnapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 1);
}

TEST_F(SnapInManagerTest, ClearEmptyTest)
{
    EXPECT_EQ(snapInManager.getSnapIns().size(), 0);

    snapInManager.clear();

    EXPECT_EQ(snapInManager.getSnapIns().size(), 0);
}

TEST_F(SnapInManagerTest, ClearExistingTest)
{
    snapInManager.addSnapIn(&snapIn);

    EXPECT_EQ(snapInManager.getSnapIns().size(), 1);

    snapInManager.clear();

    EXPECT_EQ(snapInManager.getSnapIns().size(), 0);
}

}

