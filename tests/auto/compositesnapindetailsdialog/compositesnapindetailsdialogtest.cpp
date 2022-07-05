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

#include "compositesnapindetailsdialogtest.h"

#include "compositesnapindetailsdialog.h"

#include <QTest>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QTableWidget>

using namespace ::testing;
using namespace ::gpui;

namespace test
{

TEST_F(CompositeSnapInDetailsDialogTest, DialogContainsValidInformationAfterConstruction)
{
    QMap<QString, QVersionNumber> dependencies;
    dependencies.insert("Plugin1", { 0, 1, 2 });
    dependencies.insert("Plugin2", { 1, 2, 3 });
    dependencies.insert("Plugin3", { 2, 3, 4 });

    ON_CALL(snapIn, getDisplayName()).WillByDefault(Return("Name"));
    ON_CALL(snapIn, getId).WillByDefault(Return(QUuid::createUuid()));
    ON_CALL(snapIn, getType).WillByDefault(Return("Type"));
    ON_CALL(snapIn, getRootNode).WillByDefault(Return(QUuid::createUuid()));
    ON_CALL(snapIn, getDisplayName).WillByDefault(Return("Name"));
    ON_CALL(snapIn, getHelpText).WillByDefault(Return("Help Text"));
    ON_CALL(snapIn, getVersion).WillByDefault(Return(QVersionNumber(0, 1, 2)));
    ON_CALL(snapIn, getLicense).WillByDefault(Return("License"));
    ON_CALL(snapIn, getCopyright).WillByDefault(Return("Copyright"));
    ON_CALL(snapIn, getDependencies).WillByDefault(Return(dependencies));

    CompositeSnapInDetailsDialog compositeSnapInDetailsDialog(nullptr, &snapIn);
    compositeSnapInDetailsDialog.show();

    QTest::qWait(1000);

    auto nameLineEdit = compositeSnapInDetailsDialog.findChild<QLineEdit*>("nameLineEdit");
    auto descriptionPlainTextEdit = compositeSnapInDetailsDialog.findChild<QPlainTextEdit*>("descriptionPlainTextEdit");
    auto versionLineEdit = compositeSnapInDetailsDialog.findChild<QLineEdit*>("versionLineEdit");
    auto licensePlainTextEdit = compositeSnapInDetailsDialog.findChild<QPlainTextEdit*>("licensePlainTextEdit");
    auto copyrightLineEdit = compositeSnapInDetailsDialog.findChild<QLineEdit*>("copyrightLineEdit");
    auto tableWidget = compositeSnapInDetailsDialog.findChild<QTableWidget*>("tableWidget");

    EXPECT_TRUE(nameLineEdit);
    EXPECT_TRUE(descriptionPlainTextEdit);
    EXPECT_TRUE(versionLineEdit);
    EXPECT_TRUE(licensePlainTextEdit);
    EXPECT_TRUE(copyrightLineEdit);
    EXPECT_TRUE(tableWidget);

    ASSERT_EQ(nameLineEdit->text(), "Name");
    ASSERT_EQ(descriptionPlainTextEdit->toPlainText(), "Help Text");
    ASSERT_EQ(versionLineEdit->text(), "0.1.2");
    ASSERT_EQ(licensePlainTextEdit->toPlainText(), "License");
    ASSERT_EQ(copyrightLineEdit->text(), "Copyright");

    ASSERT_EQ(tableWidget->item(0, 0)->text(), "Plugin1");
    ASSERT_EQ(tableWidget->item(1, 0)->text(), "Plugin2");
    ASSERT_EQ(tableWidget->item(2, 0)->text(), "Plugin3");

    ASSERT_EQ(tableWidget->item(0, 1)->text(), "0.1.2");
    ASSERT_EQ(tableWidget->item(1, 1)->text(), "1.2.3");
    ASSERT_EQ(tableWidget->item(2, 1)->text(), "2.3.4");
}

}

