Pflichtenheft CVVisual
======================

Einleitung
----------

OpenCV ist ein im Jahre 1999 aus der Taufe gehobenes Projekt von Intel-Forschern.  
Es wurde im Jahre 2000 der breiteren Öffentlichkeit vorgestellt, 6 Jahre später erschien Version 1.0.  
Seitdem hat sich das Projekt stetig weiterentwickelt - es ist heute der quasi Standard unter den freien   
Bilderkennungs-Bibliotheken.
Es umfasst heutzutage Algorithmen für zum Beispiel einfache Bilderkennung, Gesichtserkennung,  
Bewegungsverfolgung und viel weiteres. Die Bibliothek ist auf Performance optimiert und findet auch  
deshalb heute Einsatz in vielen Bereichen, wie etwa der Augmented Reality auf mobilen Geräten  
oder an Universitäten.  

Wer jedoch damit arbeitet, steht zur Zeit noch vor einem Problem:  
Es existiert keine richtige Debug-Visualisierung für OpenCV. Das bedeutet, dass es augenblicklich  
keine Bibliothek (und auch kein Werkzeug) gibt, mit welchem man sich adäquat visualisieren lassen kann,  
was zum Beispiel eine lange Liste von Matches mit den zwei dazugehörigen Bildern zu tun hat,  
oder welche Auswirkung ein bestimmter Filter hat. Deswegen fangen Entwickler oft an, eigene  
Lösungen für dieses Problem zu entwickeln, die in der Hauptsache aus dem einfachen Speichern  
der Bilder oder der Verwendung primitiver Methoden von OpenCV  (wie etwa 'imshow()',  
das einfach nur ein Bild anzeigt) in Kombination mit schnell zusammengeschusterten Zeichenroutinen  
bestehen, oder aber sie greifen auf ein Windows-Plug-in für Visual Studio mit stark eingeschränktem  
Funktionsumfang zurück.
Besonders für Neulinge stellt dieses weitestgehende Fehlen von Visualisierungsmöglichkeiten  
zu Debugzwecken eine große Hürde dar.  

Das sich daran etwas ändert, ist Ziel unserer Arbeit als PSE-Team an einer  
Open Source-Visualisierung für OpenCV.  

Zielbestimmungen
----------------

###API Kriterien

####Musskriterien

- imgproc/Image Filtering: dilate, erode, morphologyEx, Sobel,
- imgproc/Miscellaneous Image Transformations: threshold, adaptiveThreshold, floodFill
- features2d: KeyPoint, DMatch
- Auswahl der Visualisierung für Operationstyp
- Globale Auswahl zwischen Debug und Release Modus


####Wunschkriterien

- imgproc/Histograms: calcHist
- imgproc/Feature Detection: Canny, HoughCircles
- stitching
- ocl
- Optionale Parameter für Einstellungen der Visualisierungen
- Lokale Auswahl Debug/Release
- Optionale nicht-blockierende Aufrufe für Streaming


###GUI Kriterien

####Musskriterien

- Eine Visualisierung pro Operation (siehe API Kriterien)
- Drei Visualisierungen für features2d/DMatch
- Zoomfunktion

####Wunschkriterien

- Hohe Zoomstufen mit Zusatzinformationen (z.B. Pixelwerte)
- Parameter für Visualisierungen
- Weitere Visualisierungen
- Permanente GUI mit Historie
- Möglichkeit Operation mit geänderten Parametern erneut anzuwenden
- Datenfluss von GUI zu Code sofern sinnvoll
- Optionale Ausnutzung von mehreren Bildschirmen
- Interaktive Überlagerung von Zusatzinformationen (Mouse-Over)

###Abgrenzungskriterien

Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ sowie durch Existenz gegenüber
der Nichtexitenz anderer Lösungen ab.


Produkteinsatz
--------------

Die Software soll zunächst im universitären Forschungsumfeld des beauftragenden Institutes eingesetzt
werden. Später kann der Nutzerkreis potentiell auf alle OpenCV Benutzer ausgedehnt werden, welche
OpenCV mit Qt Unterstützung kompiliert haben. (Kopie Lastenheft)


Produktumgebung
---------------

Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt5 laufen sowie ein
C++11-Compiler.


Produktfunktion
---------------


Produktdaten
------------

Keine?

Systemmodel
-----------

* Das Interface wird aus Funktionen bestehen, die mit einer thread-lokalen GUI kommunizieren und dort
die Debug-Informationen anzeigen. Über conditional compilation werden die Funktionen im Release-Mode
durch leere ersetzt, so dass kein Runtime-Overhead entsteht.

Produktleistungen
-----------------

Möglichst kein Overhead im Release-mode.

Bedienoberfläche
----------------

* Die Bedienoberfläche wird in Qt implementiert sein.
* Sie wird aus einem Hauptfenster pro Thread bestehen.
* Die verschiedenen Debug-Ansichten werden im Hauptfenster dargestellt.

Qualitätszielbestimmungen
-------------------------

* Resource-Leaks
* kein undefiniertes Verhalten
* Threadsafety

Testfälle und Testszenarien
---------------------------

Entwicklungsumgebung
--------------------

* gcc-4.8.0 oder später
* Qt 5
* C++11 oder später
* GNU/Linux
* Cmake
* opencv

Glossar
-------

* „random code“: Individueller Wegwerfcode der nur für eine einzige Probleminstanz hilfreich ist und
	sich meist durch nichtexistentes Design auszeichnet.

* Resource-Leak: Das auftreten der Situation, das Ressourcen irgendeiner Art (Speicher, Dateien...) zwar
	alloziert werden, aber nach Verwendung nicht mehr an das System zurückgegeben werden.
