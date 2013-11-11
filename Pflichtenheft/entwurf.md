

Einleitung
==========

OpenCV ist ein im Jahre 1999 aus der Traufe gehobenes Projekt von Intel Forschern. Es wurde im
Jahre 2000 der breiteren Öffentlichkeit vorgestellt, 6 Jahre später erschien Version 1.0.
Seit dem hat sich das Projekt, das von Anfang an unter die freie BSD Clause 3 Lizenz gestellt
wurde, stetig weiter entwickelt - es ist heute der quasi Standard unter den freien
Bilderkennungs-Bibliotheken.

Es umfasst heute Algorithmen für zum Beispiel einfache Bilderkennung, Gesichtserkennung,
Bewegungsverfolgung und noch vielem weiteren. Die Bibliothek ist auf Performance optimiert und
findet auch deshalb heute Einsatz in vielen Bereichen, wie auch der Augmented Reality auf mobilen
Geräten oder im Universitären.

Doch die meisten Menschen bemerken von der Existenz dieses Projektes nichts - abgesehen von jenen,
die direkt mit dem Projekt arbeiten. Für sie gibt es leider zur Zeit noch ein Problem:
Es existiert keine richtige Debugvisualisierung für OpenCV. Das bedeutet, dass es zur Zeit keine
Bibliothek (und auch kein Werkzeug gibt), mit welchem man sich adequat visualisieren lassen kann,
was zum Beispiel eine lange Liste von Matches mit den zwei dazugehörigen Bildern zu tun hat, oder
welche Auswirkung ein bestimmter Filter hat. Deswegen fangen Entwickler oft an eigene Lösungen
für dieses Problem zu entwickeln, die in der Hauptsache aus dem einfachen Speichern der Bilder
oder der Verwendung primitiver Methoden von OpenCV verwenden, in Kombination mit schnell zusammen
geschusterten Zeichenroutinen. Ein Beispiel hierfür stammt direkt aus dem **OpenCV User Guide**,
wo es als nützliche Möglichkeiten bezeichnet wird, um Bilder zu visualisieren:
Es zeigt einfach nur ein Bild mit der Methode ´imshow´ an.

```c++
Mat img = imread("image.jpg");

namedWindow("image", CV_WINDOW_AUTOSIZE);
imshow("image", img);
waitKey();
```

Daran merkt man, wie schlecht es um Visualisierungsmöglichkeiten zu Debugzwecken aussieht - was
besonders für Neulinge eine große Hürde darstellt.

Doch das ändert sich jetzt sich wir als PSE Team arbeiten an einer richtigen Visualisierung für
OpenCV. Wie sie sich von dem schon erwähnten absetzt? Florian, eines der Teammitglieder prachte es
wie folgt auf den Punkt:
	Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ sowie durch
Existenz gegenüber der Nichtexitenz anderer Lösungen ab.

Dazu aber kurz noch eine Anmerkung:
Es gibt schon eine Software, die in unsere Richtung geht: Ein Plugin für [Microsoft Visual
Studio](https://blogs.technet.com/b/inside_microsoft_research/archive/2013/02/27/image-debugging-for
-visual-studio.aspx?Redirected=true),
welche es im Debugmodus der IDE ermöglicht, Bilder, welche im Speicher liegen, direkt anzusehen.
Aber wie gesagt: Es besitzt wirklich nur diese eine Funktionalität und steht des weiteren nicht
unter einer freien Lizenz, sodass man es auch nicht wirklich weiterentwickeln kann.

Unsere Lösung steht dagegen unter der [BSD Clause 3
Lizenz](http://opensource.org/licenses/BSD-3-Clause) (wie auch OpenCV), der gesammte Code steht auf
github später einmal verfügbar.

Unverzichtbar ist hierbei, dass unsere Lösung stark modular ist und jeder später Erweiterungen
entwickeln kann (in der Zeit in der er/sie "random code" geschrieben hätte).

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

Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt laufen sowie ein
C++11-Compiler.


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

* Die Bedienoberfläche wird in Qt implementiert sein.
* Sie wird aus einem Hauptfenster pro Thread bestehen.
* Die verschiedenen Debug-Ansichten werden im Hauptfenster dargestellt.

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

* Resource-Leak: Das auftreten der Situation, das Ressourcen irgendeiner Art (Speicher, Dateien...) zwar
	alloziert werden, aber nach Verwendung nicht mehr an das System zurückgegeben werden.
