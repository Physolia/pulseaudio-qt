/*
    Copyright 2014-2015 Harald Sitter <sitter@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PULSEOBJECT_H
#define PULSEOBJECT_H

#include "debug.h"
#include <QObject>

#include "kf5pulseaudioqt_export.h"

namespace PulseAudioQt
{

class Context;
class PulseObjectPrivate;

class KF5PULSEAUDIOQT_EXPORT PulseObject : public QObject
{
    Q_OBJECT
    Q_PROPERTY(quint32 index READ index CONSTANT)
    Q_PROPERTY(QString iconName READ iconName CONSTANT)
    Q_PROPERTY(QVariantMap properties READ properties NOTIFY propertiesChanged)
public:

    quint32 index() const;
    QString iconName() const;
    QVariantMap properties() const;

    template <typename PAInfo>
    void updatePulseObject(PAInfo *info);

    Context *context() const;
    PulseObjectPrivate *d;
Q_SIGNALS:
    void propertiesChanged();

protected:

    PulseObject(QObject *parent);
    virtual ~PulseObject();

private:
    // Ensure that we get properly parented.
    PulseObject();
};

} // PulseAudioQt

#endif // PULSEOBJECT_H
