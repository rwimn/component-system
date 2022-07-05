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

#include "snapinmanagementwidgettest.h"

#include "testcompositesnapin.h"
#include "testsnapin.h"

#include "snapindetailsfactory.h"
#include "snapinmanagementwidget.h"

#include "compositesnapindetailsdialog.h"
#include "snapindetailsdialog.h"

#include <QTest>
#include <QTreeWidget>
#include <QSignalSpy>
#include <QTimer>

using namespace ::testing;
using namespace ::gpui;

namespace test
{

TEST_F(SnapInManagementWidgetTest, TreeWidgetContainsValidSnapInAfterConstruction)
{
    std::vector<ISnapIn*> snapIns;
    std::unique_ptr<TestSnapIn> testSnapIn(new TestSnapIn());
    snapIns.push_back(testSnapIn.get());

    ON_CALL(snapInManager, getSnapIns()).WillByDefault(Return(snapIns));

    SnapInManagementWidget snapInManagementWidget(nullptr, &snapInManager);
    snapInManagementWidget.show();

    auto treeWidget = snapInManagementWidget.findChild<QTreeWidget*>("treeWidget");

    QTest::qWait(1000);

    EXPECT_TRUE(treeWidget);

    ASSERT_EQ(treeWidget->topLevelItem(0)->text(0), "Yes");
    ASSERT_EQ(treeWidget->topLevelItem(0)->text(1), "TestSnapIn");
    ASSERT_EQ(treeWidget->topLevelItem(0)->text(2), "0.1.2");
}

TEST_F(SnapInManagementWidgetTest, MultipleSnapInsTest)
{
    std::vector<ISnapIn*> snapIns;
    std::unique_ptr<TestSnapIn> testSnapIn(new TestSnapIn());
    std::unique_ptr<TestCompositeSnapIn> testCompositeSnapIn(new TestCompositeSnapIn());

    snapIns.push_back(testSnapIn.get());
    snapIns.push_back(testCompositeSnapIn.get());

    ON_CALL(snapInManager, getSnapIns()).WillByDefault(Return(snapIns));

    SnapInDetailsFactory::define<SnapInDetailsDialog>("ISnapIn");
    SnapInDetailsFactory::define<CompositeSnapInDetailsDialog>("ICompositeSnapIn");

    SnapInManagementWidget snapInManagementWidget(nullptr, &snapInManager);
    snapInManagementWidget.show();

    auto treeWidget = snapInManagementWidget.findChild<QTreeWidget*>("treeWidget");

    QTest::qWait(1000);

    EXPECT_TRUE(treeWidget);

    QTimer::singleShot(2000, &snapInManagementWidget, [&]()
    {
        for (const auto& widget :  QApplication::topLevelWidgets())
        {
            widget->close();
        }
    });

    treeWidget->doubleClicked(treeWidget->model()->index(1, 0));
}

}

