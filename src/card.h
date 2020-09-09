/*
    SPDX-FileCopyrightText: 2014-2015 Harald Sitter <sitter@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef CARD_H
#define CARD_H

#include "pulseobject.h"

struct pa_card_info;

namespace PulseAudioQt
{
class CardPort;
class Profile;

class KF5PULSEAUDIOQT_EXPORT Card : public PulseObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QVector<Profile *> profiles READ profiles NOTIFY profilesChanged)
    Q_PROPERTY(quint32 activeProfileIndex READ activeProfileIndex WRITE setActiveProfileIndex NOTIFY activeProfileIndexChanged)
    Q_PROPERTY(QVector<CardPort *> ports READ ports NOTIFY portsChanged)

public:
    ~Card();

    QString name() const;
    QVector<Profile *> profiles() const;
    quint32 activeProfileIndex() const;
    void setActiveProfileIndex(quint32 profileIndex);
    QVector<CardPort *> ports() const;

Q_SIGNALS:
    void nameChanged();
    void profilesChanged();
    void activeProfileIndexChanged();
    void portsChanged();

private:
    explicit Card(QObject *parent);

    class CardPrivate *const d;
    friend class MapBase<Card, pa_card_info>;
};

} // PulseAudioQt

#endif // CARD_H
