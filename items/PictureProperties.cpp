/***************************************************************************
 *                                                                         *
 *   This file is part of the FotoWall project,                            *
 *       http://code.google.com/p/fotowall                                 *
 *                                                                         *
 *   Copyright (C) 2009 by Enrico Ros <enrico.ros@gmail.com>               *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "PictureProperties.h"
#include "PictureContent.h"
#include "ui_PictureProperties.h"
#include <QListWidgetItem>
#include <QSettings>

PictureProperties::PictureProperties(PictureContent * pictureContent, QGraphicsItem * parent)
    : AbstractProperties(pictureContent, parent)
    , m_pictureUi(new Ui::PictureProperties())
    , m_pictureContent(pictureContent)
{
    // WIDGET setup
    QWidget * pictureTab = new QWidget();
    m_pictureUi->setupUi(pictureTab);
    addTab(pictureTab, tr("Picture"));

    // add effects items to the listview
    QListWidgetItem *no_effect = new QListWidgetItem(QIcon(":/data/effects-icons/no-effect.png"), tr("No effects"), m_pictureUi->effectsList);
    no_effect->setData(Qt::UserRole, 4);
    QListWidgetItem *item_invert = new QListWidgetItem(QIcon(":/data/effects-icons/invert-effect.png"), tr("Invert colors"), m_pictureUi->effectsList);
    item_invert->setToolTip(tr("Invert the colors of the picture"));
    item_invert->setData(Qt::UserRole, 0);
    QListWidgetItem *item_nvg = new QListWidgetItem(QIcon(":/data/effects-icons/nvg-effect.png"), tr("NVG"), m_pictureUi->effectsList);
    item_nvg->setToolTip(tr("Set the colors to levels of gray"));
    item_nvg->setData(Qt::UserRole, 1);
    QListWidgetItem *item_black = new QListWidgetItem(QIcon(":/data/effects-icons/black-and-white-effect.png"), tr("Black and White"), m_pictureUi->effectsList);
    item_black->setData(Qt::UserRole, 2);
    QListWidgetItem *glow = new QListWidgetItem(QIcon(":/data/effects-icons/glow-effect.png"), tr("Glow effect"), m_pictureUi->effectsList);
    glow->setData(Qt::UserRole, 3);

    connect(m_pictureUi->invertButton, SIGNAL(clicked()), m_pictureContent, SLOT(slotFlipVertically()));
    connect(m_pictureUi->flipButton, SIGNAL(clicked()), m_pictureContent, SLOT(slotFlipHorizontally()));
    // autoconnection doesn't work because we don't do ->setupUi(this), so here we connect manually
    connect(m_pictureUi->applyEffects, SIGNAL(clicked()), this, SLOT(on_applyEffects_clicked()));
    connect(m_pictureUi->effectsList, SIGNAL(itemActivated(QListWidgetItem*)), this, SLOT(on_effectsList_itemActivated(QListWidgetItem*)));
}

PictureProperties::~PictureProperties()
{
    delete m_pictureUi;
}

void PictureProperties::on_applyEffects_clicked()
{
    QList<QListWidgetItem *> selectedEffects = m_pictureUi->effectsList->selectedItems();
    QList<QListWidgetItem *>::iterator it = selectedEffects.begin();
    for (; it != selectedEffects.end(); it++) {
        int effectClass = (*it)->data(Qt::UserRole).toUInt();
        emit applyEffects(effectClass);
    }
}

void PictureProperties::on_effectsList_itemActivated(QListWidgetItem * item)
{
    // get the effect class
    if (!item)
        return;
    quint32 effectClass = item->data(Qt::UserRole).toUInt();

    // apply the effect
    m_pictureContent->setEffect(effectClass);
}