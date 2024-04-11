QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


win32: {
    CONFIG(release, debug|release): {
        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-1.3.0/install/release/include/oatpp-1.3.0/oatpp
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-1.3.0/install/release/lib/oatpp-1.3.0 -loatpp

        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-swagger-1.3.0/install/release/include/oatpp-1.3.0/oatpp-swagger
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-swagger-1.3.0/install/release/lib/oatpp-1.3.0 -loatpp-swagger
        LIBS += -lWS2_32
    }
    CONFIG(debug, debug|release): {
        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-1.3.0/install/debug/include/oatpp-1.3.0/oatpp
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-1.3.0/install/debug/lib/oatpp-1.3.0 -loatpp

        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-swagger-1.3.0/install/debug/include/oatpp-1.3.0/oatpp-swagger
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-swagger-1.3.0/install/debug/lib/oatpp-1.3.0 -loatpp-swagger
        LIBS += -lWS2_32
    }
}
unix: {
    CONFIG(release, debug|release): {
        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-swagger/include/oatpp-1.3.0/oatpp-swagger
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-swagger/lib/oatpp-1.3.0 -loatpp-swagger

        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp/include/oatpp-1.3.0/oatpp
        LIBS += -L$$(AOS_KERNEL_3RD)/oatpp/lib/oatpp-1.3.0 -loatpp
    }
    CONFIG(debug, debug|release): {
        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp-swagger/include/oatpp-1.3.0/oatpp-swagger
        LIBS += -L$$_PRO_FILE_PWD_/oatpp-swagger/lib/oatpp-1.3.0 -loatpp-swagger

        INCLUDEPATH += $$_PRO_FILE_PWD_/oatpp/include/oatpp-1.3.0/oatpp
        LIBS += -L$$_PRO_FILE_PWD_/oatpp/lib/oatpp-1.3.0 -loatpp
    }
}

SOURCES += \
        controller/MyTestController.cpp \
        main.cpp

HEADERS += \
    AppComponent.h \
    OatppTestGlobal.h \
    SwaggerComponent.h \
    controller/MyTestController.h \
    dto/DtoTest.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
