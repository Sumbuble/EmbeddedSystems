# Don't change!!!
CXX         =g++
UTCXXFLAGS  =-Werror -Wall -Wextra -Wno-format -Wold-style-cast -std=c++1z
CXXFLAGS    = $(UTCXXFLAGS) -fno-exceptions -fno-rtti
OUTPUT      =bin
UNITTEST_DIR=unittest

CURL_OPTIONS=-u $(USER):$(PASSWORD) -X POST -F 'speicherung=$(ICH_STIMME_DER_SPEICHERUNG_DER_DATE_ZU)'

ECHO_COMPILE=echo "1. CC $(PROGNAME)"
ECHO_UT_COMPILE=echo "1. UTCC $(PROGNAME)"
SILENT_MKDIR=

SUBMIT_URL=https://www.andreasfertig.info/submit_es.html

PROGNAME   =uebung0$(EXERCISE_NO)
PROGNAME_UT=ut$(PROGNAME)

USER=abgabe
PASSWORD=pes18

# insert correct values
EXERCISE_NO=4
MATNR=1430141
# Um der Speicherung Ihrer Daten zuzustimmen tragen Sie in das folgende Feld bitte 'yes' ein
ICH_STIMME_DER_SPEICHERUNG_DER_DATE_ZU=yes
