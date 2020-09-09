/*
    SPDX-FileCopyrightText: 2014-2015 Harald Sitter <sitter@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef PORT_H
#define PORT_H

#include "kf5pulseaudioqt_export.h"
#include "profile.h"

namespace PulseAudioQt
{
class KF5PULSEAUDIOQT_EXPORT Port : public Profile
{
    Q_OBJECT

public:
    ~Port();

protected:
    explicit Port(QObject *parent);
    class PortPrivate *const d;

    friend class DevicePrivate;
};

} // PulseAudioQt

#endif // PORT_H
