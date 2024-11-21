#include "bimap.h"

Bimap::Bimap(QObject *parent)
    : QObject{parent}
{}

bool Bimap::insert(const QString &key, const QVariant &value) noexcept {

    if ( m_keyToValue.contains(key)  || m_valueToKey.contains(value) ) {
        return false;
    }

    m_keyToValue[key] = value;
    m_valueToKey[value] = key;

    return true;
}

bool Bimap::setValue(const QString &key, const QVariant &value) noexcept {

    if (!m_keyToValue.contains(key) || m_valueToKey.contains(value)) {
        return false;
    }

    const auto oldValue = m_keyToValue[key];

    if (oldValue == value) {
        return false;
    }

    m_keyToValue[key] = value;
    m_valueToKey.remove(oldValue);
    m_valueToKey[value] = key;

    return true;
}

bool Bimap::removeByKey(const QString &key) noexcept{
    if (!m_keyToValue.contains(key)) {
        return false;
    }

    const auto value = m_keyToValue[key];
    m_keyToValue.remove(key);
    m_valueToKey.remove(value);

    return true;
}

bool Bimap::removeByValue(const QVariant &value) noexcept{
    if (!m_valueToKey.contains(value)) {
        return false;
    }

    const auto key = m_valueToKey[value];
    m_valueToKey.remove(value);
    m_keyToValue.remove(key);

    return true;
}

std::optional<QVariant> Bimap::getKey(const QVariant &value) const noexcept {
    if (!m_valueToKey.contains(value)) {
        return {};
    }
    return m_valueToKey.value(value);
}

std::optional<QVariant> Bimap::getValue(const QString &key) const noexcept {
    if ( !m_keyToValue.contains(key) ) {
        return {};
    }
    return m_keyToValue.value(key);
}
