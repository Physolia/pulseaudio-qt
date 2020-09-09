/*
    SPDX-FileCopyrightText: 2014-2015 Harald Sitter <sitter@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef SINK_H
#define SINK_H

#include "device.h"

struct pa_sink_info;

namespace PulseAudioQt
{
class KF5PULSEAUDIOQT_EXPORT Sink : public Device
{
    Q_OBJECT

public:
    ~Sink();

    void setVolume(qint64 volume) override;
    void setMuted(bool muted) override;
    void setActivePortIndex(quint32 port_index) override;
    void setChannelVolume(int channel, qint64 volume) override;

    bool isDefault() const override;
    void setDefault(bool enable) override;

private:
    explicit Sink(QObject *parent);

    class SinkPrivate *const d;
    friend class MapBase<Sink, pa_sink_info>;
};

} // PulseAudioQt

#endif // SINK_H
