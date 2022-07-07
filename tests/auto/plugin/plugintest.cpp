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

#include "plugintest.h"

#include "plugin.h"

#include <QLibrary>
#include <QString>

using namespace ::testing;
using namespace ::gpui;

namespace test
{
const QString pluginName = "Test Plugin";
const QString fileName   = "example.so";
const QString className  = "Test Class";

class TestPlugin : public ::gpui::Plugin
{
public:
    explicit TestPlugin(const QString &name)
        : ::gpui::Plugin(name)
    {}

    explicit TestPlugin(const char *name)
        : ::gpui::Plugin(name)
    {}

    void registerPluginClass(const QString &name, std::function<void *()> constructor)
    {
        Plugin::registerPluginClass(name, constructor);
    }
};

TEST_F(PluginTest, ConstructionTest)
{
    TestPlugin plugin1(pluginName);

    EXPECT_EQ(plugin1.getName(), pluginName);

    EXPECT_EQ(plugin1.getLibrary(), nullptr);

    TestPlugin plugin2(pluginName.toStdString().c_str());

    EXPECT_EQ(plugin2.getName(), pluginName);

    EXPECT_EQ(plugin2.getLibrary(), nullptr);
}

TEST_F(PluginTest, LibrarySetupTest)
{
    TestPlugin plugin(pluginName);

    auto library = std::make_unique<QLibrary>(fileName);

    EXPECT_NO_THROW(plugin.setLibrary(std::move(library)));

    EXPECT_EQ(plugin.getLibrary()->fileName(), fileName);
}

TEST_F(PluginTest, RegisterClassTest)
{
    TestPlugin plugin(pluginName);

    std::function<void *()> testFunction = []() { return nullptr; };

    plugin.registerPluginClass(className, testFunction);

    EXPECT_EQ(plugin.getPluginClasses().size(), 1);
}

} // namespace test
