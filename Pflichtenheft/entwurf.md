

Einleitung
==========


Zielbestimmungen
================


Musskriterien
-------------


Wunschkriterien
---------------


Abgrenzungskriterien
--------------------

Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ sowie durch Existenz gegenüber
der Nichtexitenz anderer Lösungen ab.


Produkteinsatz
==============

Die Software soll zunächst im universitären Forschungsumfeld des beauftragenden Institutes eingesetzt
werden. Später kann der Nutzerkreis potentiell auf alle OpenCV Benutzer ausgedehnt werden, welche
OpenCV mit Qt Unterstützung kompiliert haben. (Kopie Lastenheft)


Produktumgebung
===============

Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt laufen.


Produktfunktion
===============


Produktdaten
============

Keine?

Systemmodel
===========

* Das Interface wird aus Funktionen bestehen, die mit einer thread-lokalen GUI kommunizieren und dort
die Debug-Informationen anzeigen. Über conditional compilation werden die Funktionen im Release-Mode
durch leere ersetzt, so dass kein Runtime-Overhead entsteht.

Produktleistungen
=================

Möglichst kein Overhead im Release-mode.

Bedienoberfläche
================

Qualitätszielbestimmungen
=========================

* Resource-Leaks
* kein undefiniertes Verhalten
* Threadsafety

Testfälle und Testszenarien
===========================

Entwicklungsumgebung
====================

* gcc-4.8.x oder später
* C++11 oder später
* GNU/Linux
* Cmake
* opencv

Glossar
=======

* „random code“: Individueller Wegwerfcode der nur für eine einzige Probleminstanz hilfreich ist und
	sich meist durch nichtexistentes Design auszeichnet.
