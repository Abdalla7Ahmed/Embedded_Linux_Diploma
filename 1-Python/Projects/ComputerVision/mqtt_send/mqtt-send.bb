

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

#LICENSE = "CLOSED"
#LIC_FILES_CHKSUM = ""

DEPENDS += "openssl paho-mqtt-c paho-mqtt-cpp"

SRC_URI = "file://sender.cpp"

S = "${WORKDIR}"

CXXFLAGS += "-I${STAGING_DIR_TARGET}/usr/include"
LDFLAGS += "-L${STAGING_DIR_TARGET}/usr/lib"

do_compile() {
    ${CXX} ${CXXFLAGS} ${LDFLAGS} sender.cpp -o mqtt_sender -lpaho-mqttpp3 -lpaho-mqtt3a -lpaho-mqtt3c -lpaho-mqtt3as
}

do_install() {
    install -d ${D}${bindir}
    install -m 0755 mqtt_sender ${D}${bindir}
}
