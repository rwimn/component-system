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

#include "snapinmanagementwidget.h"
#include "ui_snapinmanagementwidget.h"

namespace gpui
{

class SnapInManagementWidgetPrivate
{
public:
    Ui::SnapInManagementWidget* ui = nullptr;
    ISnapInManager* manager = nullptr;

    SnapInManagementWidgetPrivate()
        : ui(new Ui::SnapInManagementWidget())
    {
    }
    ~SnapInManagementWidgetPrivate()
    {
        delete ui;
    }
};

SnapInManagementWidget::SnapInManagementWidget(QWidget *parent, ISnapInManager *manager)
    : QWidget(parent)
    , d(new SnapInManagementWidgetPrivate())
{
    d->manager = manager;
    d->ui->setupUi(this);
}

SnapInManagementWidget::~SnapInManagementWidget()
{
    delete d;
}

}
