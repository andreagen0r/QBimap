#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <bimap.h>
#include <QVariant>

TEST_CASE("Bimap: Insert Key-Value Pairs", "[Bimap]") {
    Bimap bimap;
    REQUIRE(bimap.insert("key1", 14));
    REQUIRE(bimap.insert("key2", 1));
    REQUIRE_FALSE(bimap.insert("key1", 27)); // Chave duplicada
    REQUIRE_FALSE(bimap.insert("key2", 14)); // Chave e valor duplicado
    REQUIRE_FALSE(bimap.insert("key3", 1)); // Valor duplicado
}

TEST_CASE("Bimap: Remove By Key", "[Bimap]") {
    Bimap bimap;
    REQUIRE(bimap.insert("key1", 42));
    REQUIRE(bimap.removeByKey("key1"));
    REQUIRE_FALSE(bimap.removeByKey("key1")); // Já removido
    REQUIRE_FALSE(bimap.removeByKey("key5")); // Não existe
}

TEST_CASE("Bimap: Remove By Value", "[Bimap]") {
    Bimap bimap;
    REQUIRE(bimap.insert("key1", 42));
    REQUIRE(bimap.removeByValue(42));
    REQUIRE_FALSE(bimap.removeByValue(42)); // Já removido
    REQUIRE_FALSE(bimap.removeByValue(1)); // Não existe
}

TEST_CASE("Bimap: Get Value/Key", "[Bimap]") {
    Bimap bimap;
    REQUIRE(bimap.insert("key1", 42));
    REQUIRE(bimap.insert("key2", 14));
    REQUIRE(bimap.getValue("key1") == std::optional<QVariant>(42));
    REQUIRE(bimap.getValue("key2") == std::optional<QVariant>(14));
    REQUIRE(bimap.getKey(42) == std::optional<QString>("key1"));
    REQUIRE(bimap.getKey(14) == std::optional<QString>("key2"));
    REQUIRE_FALSE(bimap.getKey(42) == std::optional<QString>("key2"));
    REQUIRE_FALSE(bimap.getKey(33) == std::optional<QString>("key2"));
}

