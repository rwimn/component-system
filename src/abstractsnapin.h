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

#ifndef _ABSTRACTSNAPIN_H
#define _ABSTRACTSNAPIN_H

#include "plugin.h"
#include "isnapin.h"

#include <QUuid>
#include <QVersionNumber>

namespace gpui
{

/**
 * @brief Adapts interface of a ISnapIn for a plugin.
 */
class AbstractSnapIn : protected Plugin, public ISnapIn
{
public:
    /**
     * @brief isLoaded Returns true if snap-in is loaded.
     */
    bool isLoaded();

    /**
     * @brief Gets the identifier for the instance of the snap-in.
     * The identifier is unique across snap-in instances within a application.
     */
    QUuid getId() override;

    /**
     * @brief getType Returns type of a snap-in.
     */
    QString getType() override;

    /**
     * @brief Gets the identifier for the instance of the snap-in.
     * The identifier is unique across snap-in instances within a application.
     * This value can never be a null value or invalid.
     */
    QUuid getRootNode() override;

    /**
     * @brief Called when a snap-in is initialized. It allows derived classes to provide additional initialization.
     */
    void onInitialize() override;

    /**
     * @brief Called when the snap-in is shutting down.
     * Once this call returns, actions which modify the application, such as adding nodes,
     * or modifying view descriptions, are not honored.
     */
    void onShutdown() override;

    /**
     * @brief Returns display name of a snap-in.
     */
    QString getDisplayName() override;

    /**
     * @brief Gets the help text for the instance of the snap-in.
     */
    QString getHelpText() override;

    /**
     * @brief Gets version of a snap-in.
     */
    QVersionNumber getVersion() override;

    /**
     * @brief Returns license assosiated with the module.
     */
    QString getLicense() override;

    /**
     * @brief Returns copyright of module.
     */
    QString getCopyright() override;
};

}

#endif  //_ABSTRACTSNAPIN_H
