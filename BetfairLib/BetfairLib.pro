#-------------------------------------------------
#
# Project created by QtCreator 2015-05-24T01:09:59
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = BetfairLib
TEMPLATE = lib
CONFIG   += c++11
DEFINES += BETFAIRLIB_LIBRARY

SOURCES += \
    betfairapi/eventsapi.cpp \
    betfairapi/httpjsonclient.cpp \
    betfairapi/loginapi.cpp \
    betfairapi/marketbookapi.cpp \
    betfairapi/marketcatalogueapi.cpp \
    betfairapi/keepaliveapi.cpp \
    betfairapi/placeordersapi.cpp \
    betfairapi/accountsapi.cpp \
    betfairapi/listcurrentordersapi.cpp \
    betfairapi/cancelordersapi.cpp

HEADERS +=\
        betfairlib_global.h \
    betfairapi/eventsapi.h \
    betfairapi/httpjsonclient.h \
    betfairapi/loginapi.h \
    betfairapi/marketbookeapi.h \
    betfairapi/marketcatalogueapi.h \
    betfairfilter/betfairmarketfilter.h \
    betfairapi/keepaliveapi.h \
    betfairapi/placeordersapi.h \
    misc/debugmacros.h \
    betfairapi/listcurrentordersapi.h \
    betfairapi/cancelordersapi.h \
    betfairapi/accountsapi.h \
    betfairfilter/bfmarkettype.h \
    bfenums/bfcompetition.h \
    bfenums/bfexecutionreporterrorcode.h \
    bfenums/bfexecutionreportstatus.h \
    bfenums/bfgroupby.h \
    bfenums/bfinstructionreporterrorcode.h \
    bfenums/bfinstructionreportstatus.h \
    bfenums/bfmarketbettingtype.h \
    bfenums/bfmarketprojection.h \
    bfenums/bfmarketsort.h \
    bfenums/bfmarketstatus.h \
    bfenums/bfmatchprojection.h \
    bfenums/bforderby.h \
    bfenums/bforderprojection.h \
    bfenums/bforderstatus.h \
    bfenums/bfordertype.h \
    bfenums/bfpersistencetype.h \
    bfenums/bfpricedata.h \
    bfenums/bfrollupmodel.h \
    bfenums/bfrunnerstatus.h \
    bfenums/bfside.h \
    bfenums/bfsortdir.h \
    bfenums/bftimegranuality.h \
    bfjsoncreator/bfaccountsapijsoncreator.h \
    bfjsoncreator/bfcancelordersjsoncreator.h \
    bfjsoncreator/bflistcurrentordersjsoncreator.h \
    bfjsoncreator/bfplaceordersjsoncreator.h \
    bfjsonparser/bfaccountsapiparser.h \
    bfjsonparser/bfapingexceptionparser.h \
    bfjsonparser/bfcancelordersparser.h \
    bfjsonparser/bfeventresultlistparser.h \
    bfjsonparser/bflistcurrentordersparser.h \
    bfjsonparser/bfmarketcatalogueparser.h \
    bfjsonparser/bfplaceordersparser.h \
    bftypes/bfaccountdetailsrsp.h \
    bftypes/bfaccountfundsrsp.h \
    bftypes/bfapingexception.h \
    bftypes/bfcancelexecutionreport.h \
    bftypes/bfcancelinstruction.h \
    bftypes/bfcancelinstructionreport.h \
    bftypes/bfcurrentorder.h \
    bftypes/bfevent.h \
    bftypes/bfeventresult.h \
    bftypes/bflimitoncloseorder.h \
    bftypes/bflimitorder.h \
    bftypes/bfmarket.h \
    bftypes/bfmarketoncloseorder.h \
    bftypes/bfplaceexecutionreport.h \
    bftypes/bfplaceinstruction.h \
    bftypes/bfplaceinstructionreport.h \
    bftypes/bfselection.h \
    misc/bfconfig.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += \
    misc/Eigen/CMakeLists.txt
