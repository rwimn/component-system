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

#include "pluginstoragetest.h"

#include "pluginstorage.h"
#include "plugin.h"

#include <QLibrary>
#include <QFileInfo>
#include <QString>

using namespace ::testing;
using namespace ::gpui;

namespace test
{

TEST_F(PluginStorageTest, getPlugin)
{
    QString pluginName = "barplugin";

    PluginStorage::instance()->loadPluginDirectory(QString::fromStdString("./"));

    auto plugin = PluginStorage::instance()->getPlugin(pluginName);

    EXPECT_EQ(plugin->getName(), pluginName);
}

} // namespace test
