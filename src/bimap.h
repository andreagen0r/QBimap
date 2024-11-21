#pragma once

#include <QObject>
#include <QDebug>
#include <QMap>
#include <QString>
#include <QVariant>
#include <optional>

class Bimap : public QObject
{
    Q_OBJECT
public:
    explicit Bimap(QObject *parent = nullptr);

    [[nodiscard]] bool insert(const QString& key, const QVariant& value) noexcept;

    [[nodiscard]] bool setValue(const QString& key, const QVariant& value) noexcept;

    [[nodiscard]] bool removeByKey(const QString& key) noexcept;

    [[nodiscard]] bool removeByValue(const QVariant& value) noexcept;

    [[nodiscard]] std::optional<QVariant> getValue(const QString& key) const noexcept;

    [[nodiscard]] std::optional<QVariant> getKey(const QVariant& value) const noexcept;

Q_SIGNALS:
    void valueChanged();
    void valueInserted();
    void valueRemoved();

private:
    QMap<QString, QVariant> m_keyToValue;
    QMap<QVariant, QString> m_valueToKey;

    friend QDebug operator<<( QDebug debug, const Bimap& data ) {
        const QDebugStateSaver saver( debug );
        debug.nospace();
        debug  << "[Key to value: " << data.m_keyToValue << "]; [";
        debug  << "Value to key: " << data.m_valueToKey << "]";
        return debug;
    }
};
