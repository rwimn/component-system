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

#include "compositesnapintest.h"

#include "abstractcompositesnapin.h"

#include <QMap>
#include <QString>
#include <QVersionNumber>

using namespace gpui;

namespace test
{
class TestCompositeSnapIn : public AbstractCompositeSnapIn
{
public:
    TestCompositeSnapIn()
        : AbstractCompositeSnapIn("", "")
    {}

    void addDependency(const QString &name, const QVersionNumber &version)
    {
        AbstractCompositeSnapIn::addDependency(name, version);
    }

    void removeDependency(const QString &name) { AbstractCompositeSnapIn::removeDependency(name); }

    void onInitialize() {}

    void onShutdown() {}
};

TEST_F(CompositeSnapInTest, AddDependencyTest)
{
    TestCompositeSnapIn testSnapIn;

    testSnapIn.addDependency("Test", {1, 0, 0});

    ASSERT_EQ(testSnapIn.getDependencies().size(), 1);

    auto dependency = testSnapIn.getDependencies().begin();

    ASSERT_EQ(dependency.key(), "Test");
    ASSERT_EQ(dependency.value(), QVersionNumber(1, 0, 0));
}

TEST_F(CompositeSnapInTest, RemoveDependencyPositiveTest)
{
    TestCompositeSnapIn testSnapIn;

    testSnapIn.addDependency("Test", {1, 0, 0});

    ASSERT_EQ(testSnapIn.getDependencies().size(), 1);

    testSnapIn.removeDependency("Test");

    ASSERT_EQ(testSnapIn.getDependencies().size(), 0);
}

TEST_F(CompositeSnapInTest, RemoveDependencyNegativeTest)
{
    TestCompositeSnapIn testSnapIn;

    ASSERT_EQ(testSnapIn.getDependencies().size(), 0);

    ASSERT_NO_THROW(testSnapIn.removeDependency("Test"));

    ASSERT_EQ(testSnapIn.getDependencies().size(), 0);
}

} // namespace test
