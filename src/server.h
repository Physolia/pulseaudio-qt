/*
    SPDX-FileCopyrightText: 2016 David Rosca <nowrep@gmail.com>
    SPDX-FileCopyrightText: 2024 Harald Sitter <sitter@kde.org>

    SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
*/

#ifndef SERVER_H
#define SERVER_H

#include "pulseaudioqt_export.h"
#include <QObject>

namespace PulseAudioQt
{
class Sink;
class Source;
class Context;

class PULSEAUDIOQT_EXPORT Server : public QObject
{
    Q_OBJECT
    /// The default Sink (SinkInputs that aren't otherwise assigned explicitly will use this Sink)
    Q_PROPERTY(Sink *defaultSink READ defaultSink NOTIFY defaultSinkChanged)
    /// The default Source (SourceOutputs that aren't otherwise assigned explicitly will use this Source)
    Q_PROPERTY(Source *defaultSource READ defaultSource NOTIFY defaultSourceChanged)
    /// Whether the connected Server is PipeWire (rather than PulseAudio)
    Q_PROPERTY(bool isPipeWire READ isPipeWire NOTIFY isPipeWireChanged)
    /// Whether the connected PipeWire is driven by WirePlumber
    Q_PROPERTY(bool hasWirePlumber READ hasWirePlumber NOTIFY hasWirePlumberChanged)
public:
    ~Server() override;

    Sink *defaultSink() const;
    void setDefaultSink(Sink *sink);

    Source *defaultSource() const;
    void setDefaultSource(Source *source);

    /**
     * Whether PulseAudio is provided via pipewire-pulse.
     */
    bool isPipeWire() const;

    /**
     * Whether WirePlumber is running in addition to PipeWire.
     *
     * @since 1.6
     */
    [[nodiscard]] bool hasWirePlumber() const;

Q_SIGNALS:
    void defaultSinkChanged(PulseAudioQt::Sink *sink);
    void defaultSourceChanged(PulseAudioQt::Source *source);
    void isPipeWireChanged();
    void updated();
    void hasWirePlumberChanged();

private:
    explicit Server(Context *context);

    void reset();
    void disconnectSignals();
    void updateDefaultDevices();

    std::unique_ptr<class ServerPrivate> d;

    friend class ServerPrivate;
    friend class Context;
    friend class ContextPrivate;
};

} // PulseAudioQt

#endif // CONTEXT_H
