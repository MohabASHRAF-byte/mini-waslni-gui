QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bfs.cpp \
    dfs.cpp \
    dijkstra.cpp \
    edit.cpp \
    floyd.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    navigate.cpp

HEADERS += \
    Node.h \
    NodeConverter.h \
    Point.h \
    algorithm.h \
    bfs.h \
    dfs.h \
    dijkstra.h \
    edit.h \
    floyd.h \
    mainwindow.h \
    map.h \
    navigate.h

FORMS += \
    edit.ui \
    mainwindow.ui \
    navigate.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Res.qrc

DISTFILES += \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 10.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 11.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 12.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 13.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 14.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 15.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 16.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 2.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 3.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 4.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 5.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 6.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 7.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 8.png \
    C:/Users/Moamen Sherif/Desktop/drive-download-20230520T180835Z-001/Asset 9.png
