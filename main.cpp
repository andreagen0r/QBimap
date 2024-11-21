#include <QCoreApplication>

#include <bimap.h>

int main(int argc, char *argv[])
{
    Bimap bimap;

    if (!bimap.insert("DP-0", 14)) {
        qInfo() << "Erro ao tentar adicionar";
    }
    if (!bimap.insert("HDMI-0", 21)) {
        qInfo() << "Erro ao tentar adicionar";
    }
    if (!bimap.insert("HDMI-1", {})) {
        qInfo() << "Erro ao tentar adicionar";
    }

    qInfo() << bimap;


    if ( bimap.removeByKey("DP-0") ) {
        qInfo() << "Removeu";
    }

    const auto value = bimap.getValue("DP-0");

    if (value.has_value()) {
        qInfo() <<  bimap.getKey(value.value())->toString() << value.value();
    }

    qInfo() << bimap;

    if (bimap.setValue("HDMI-0", 33) ) {
        qInfo() << "ok" << bimap;
    }

    if (bimap.setValue("HDMI-1", 33) ) {
        qInfo() << bimap;
    }

    return 0;
}


