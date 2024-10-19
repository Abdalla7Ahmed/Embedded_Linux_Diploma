LICENSE = "CLOSED"
LIC_FILES_CHKSUM = ""

DEPENDS += "openssl paho-mqtt-c paho-mqtt-cpp"

SRC_URI = "file://receiver.cpp"

S = "${WORKDIR}"

CXXFLAGS += "-I${STAGING_DIR_TARGET}/usr/include"
LDFLAGS += "-L${STAGING_DIR_TARGET}/usr/lib"

do_compile() {
    ${CXX} ${CXXFLAGS} ${LDFLAGS} receiver.cpp -o mqtt_receive -lpaho-mqttpp3 -lpaho-mqtt3a -lpaho-mqtt3c -lpaho-mqtt3as
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 mqtt_receive ${D}${bindir}
}
