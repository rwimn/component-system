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

#include "snapindetailsdialogtest.h"

#include "snapindetailsdialog.h"

#include <QTest>
#include <QLineEdit>
#include <QPlainTextEdit>

using namespace ::testing;
using namespace ::gpui;

namespace test
{

TEST_F(SnapInDetailsDialogTest, WidgetContainsValidSnapInAfterConstruction)
{
    ON_CALL(snapIn, getDisplayName()).WillByDefault(Return("Name"));
    ON_CALL(snapIn, getDisplayName()).WillByDefault(Return("Name"));

    ON_CALL(snapIn, getId).WillByDefault(Return(QUuid::createUuid()));
    ON_CALL(snapIn, getType).WillByDefault(Return("Type"));
    ON_CALL(snapIn, getRootNode).WillByDefault(Return(QUuid::createUuid()));
    ON_CALL(snapIn, getDisplayName).WillByDefault(Return("Name"));
    ON_CALL(snapIn, getHelpText).WillByDefault(Return("Help Text"));
    ON_CALL(snapIn, getVersion).WillByDefault(Return(QVersionNumber(0, 1, 2)));
    ON_CALL(snapIn, getLicense).WillByDefault(Return("License"));
    ON_CALL(snapIn, getCopyright).WillByDefault(Return("Copyright"));

    SnapInDetailsDialog snapInDetailsDialog(nullptr, &snapIn);
    snapInDetailsDialog.show();

    QTest::qWait(1000);

    auto nameLineEdit = snapInDetailsDialog.findChild<QLineEdit*>("nameLineEdit");
    auto descriptionPlainTextEdit = snapInDetailsDialog.findChild<QPlainTextEdit*>("descriptionPlainTextEdit");
    auto versionLineEdit = snapInDetailsDialog.findChild<QLineEdit*>("versionLineEdit");
    auto licensePlainTextEdit = snapInDetailsDialog.findChild<QPlainTextEdit*>("licensePlainTextEdit");
    auto copyrightLineEdit = snapInDetailsDialog.findChild<QLineEdit*>("copyrightLineEdit");

    EXPECT_TRUE(nameLineEdit);
    EXPECT_TRUE(descriptionPlainTextEdit);
    EXPECT_TRUE(versionLineEdit);
    EXPECT_TRUE(licensePlainTextEdit);
    EXPECT_TRUE(copyrightLineEdit);

    ASSERT_EQ(nameLineEdit->text(), "Name");
    ASSERT_EQ(descriptionPlainTextEdit->toPlainText(), "Help Text");
    ASSERT_EQ(versionLineEdit->text(), "0.1.2");
    ASSERT_EQ(licensePlainTextEdit->toPlainText(), "License");
    ASSERT_EQ(copyrightLineEdit->text(), "Copyright");
}

}

