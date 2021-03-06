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

#ifndef __VersionCheckDialog_h__
#define __VersionCheckDialog_h__

#include <QDialog>
class QNetworkAccessManager;
namespace Ui { class VersionCheckDialog; }

class VersionCheckDialog : public QDialog
{
    Q_OBJECT
    public:
        VersionCheckDialog(QWidget * parent = 0);
        ~VersionCheckDialog();

    private Q_SLOTS:
        void slotGotReply();
        void slotTimeOut();
        void slotDownload();

    private:
        Ui::VersionCheckDialog * ui;
        QNetworkAccessManager * m_nam;
};

#endif
