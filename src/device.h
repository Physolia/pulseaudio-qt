/*
    SPDX-FileCopyrightText: 2014-2015 Harald Sitter <sitter@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef PA_DEVICE_H
#define PA_DEVICE_H

#include <QString>

#include "volumeobject.h"

namespace PulseAudioQt
{
class Port;
class DevicePrivate;

/**
 * A PulseAudio device. Can be either a Sink or Source.
 */
class PULSEAUDIOQT_EXPORT Device : public VolumeObject
{
    Q_OBJECT
    Q_PROPERTY(State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(QString formFactor READ formFactor NOTIFY formFactorChanged)
    Q_PROPERTY(quint32 cardIndex READ cardIndex NOTIFY cardIndexChanged)
    Q_PROPERTY(QVector<Port *> ports READ ports NOTIFY portsChanged)
    Q_PROPERTY(quint32 activePortIndex READ activePortIndex WRITE setActivePortIndex NOTIFY activePortIndexChanged)
    Q_PROPERTY(bool default READ isDefault WRITE setDefault NOTIFY defaultChanged)

public:
    enum State {
        /** This state is used when the server does not support sink/source state introspection. */
        InvalidState = 0,
        /** Running, sink/source is playing/recording and used by at least one non-corked sink-input/source-output.  */
        RunningState,
        /** When idle, the sink/source is playing/recording but there is no non-corked sink-input/source-output attached to it. */
        IdleState,
        /** When suspended, actual sink/source access can be closed, for instance. */
        SuspendedState,
        UnknownState,
    };
    Q_ENUM(State);

    ~Device();

    /**
     * The state of this device.
     */
    State state() const;

    /**
     * A human readable description of this device.
     */
    QString description() const;

    /**
     * The device's form factor.
     * One of "internal", "speaker", "handset", "tv", "webcam", "microphone", "headset", "headphone", "hands-free", "car", "hifi", "computer", "portable".
     * This is based on PA_PROP_DEVICE_FORM_FACTOR.
     */
    QString formFactor() const;

    /**
     * Index of the card that owns this device.
     */
    quint32 cardIndex() const;

    /**
     * The ports associated with this device.
     */
    QVector<Port *> ports() const;

    /**
     * The currently active port, by index.
     */
    quint32 activePortIndex() const;

    /**
     * Set the currently active port, by index.
     */
    virtual void setActivePortIndex(quint32 port_index) = 0;

    /**
     * Whether this is the default device.
     */
    virtual bool isDefault() const = 0;

    /**
     * Set whether this is the default device.
     */
    virtual void setDefault(bool enable) = 0;

Q_SIGNALS:
    void stateChanged();
    void descriptionChanged();
    void formFactorChanged();
    void cardIndexChanged();
    void portsChanged();
    void activePortIndexChanged();
    void defaultChanged();

protected:
    explicit Device(QObject *parent);
    DevicePrivate *d;

private:
    friend class SinkPrivate;
    friend class SourcePrivate;
};

} // PulseAudioQt

#endif // DEVICE_H
