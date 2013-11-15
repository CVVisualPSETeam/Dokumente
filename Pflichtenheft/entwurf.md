Pflichtenheft CVVisual
======================

Einleitung
----------

OpenCV ist ein im Jahre 1999 aus der Taufe gehobenes Projekt von Intel-Forschern.  
Es wurde im Jahre 2000 der breiteren Öffentlichkeit vorgestellt, 6 Jahre später erschien Version 1.0.  
Seitdem hat sich das Projekt stetig weiterentwickelt - es ist heute der Quasi-Standard unter den freien   
Bilderkennungs-Bibliotheken.
Es umfasst heutzutage Algorithmen für zum Beispiel einfache Bilderkennung, Gesichtserkennung,  
Bewegungsverfolgung und vieles mehr. Die Bibliothek ist auf Performance optimiert und findet auch  
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
bestehen, oder aber sie greifen auf ein Microsoft-Plug-in für Visual Studio mit stark eingeschränktem  
Funktionsumfang zurück (d.h. man kann im wesentlichen nur Bilder ansehen, die im Speicher liegen).
Besonders für Neulinge stellt dieses weitestgehende Fehlen von Visualisierungsmöglichkeiten  
zu Debugzwecken eine große Hürde dar.  

Das sich daran etwas ändert, ist Ziel unserer Arbeit als PSE-Team an einer  
Open Source-Visualisierung für OpenCV. 

Zielbestimmungen
----------------

###API Kriterien

####Musskriterien

//TODO: Überlegen ob nicht lieber deutsche Beschreibung der Feautures mit Verweis auf Bezeichnung

#####Unterstützte OpenCV Features
- imgproc/Image Filtering: dilate, erode, morphologyEx, Sobel
- imgproc/Miscellaneous Image Transformations: threshold, adaptiveThreshold, floodFill
- feature2sd: KeyPoint, DMatch

#####Allgemeine API Features
- Auswahl der Visualisierung für Operationstyp
- Globale Auswahl zwischen Debug und Release Modus


####Wunschkriterien

#####Unterstützte OpenCV Features
- imgproc/Histograms: calcHist
- imgproc/Feature Detection: Canny, HoughCircles
- stitching
- ocl

#####Allgemeine API Features
- Optionale Parameter für Einstellungen der Visualisierungen
- Lokale Auswahl Debug/Release
- Optionale nicht-blockierende Aufrufe für Streaming


###GUI Kriterien

####Musskriterien

- Eine Visualisierung pro Operation (siehe API Kriterien)
- Drei Visualisierungen für features2d/DMatch (drei aus den Wunsch-Visualisierungen, siehe unten)
- Zoomfunktion

####Wunschkriterien

#####Visualisierungen
######Für Matches
######FÜr Filter

#####Allgemein
- Hohe Zoomstufen mit Zusatzinformationen (z.B. Pixelwerte)
- Permanente GUI mit Historie
- Möglichkeit Operation mit geänderten Parametern erneut anzuwenden
- Datenfluss von GUI zu Code sofern sinnvoll
- Optionale Ausnutzung von mehreren Bildschirmen
- Interaktive Überlagerung von Zusatzinformationen (Mouse-Over)

###Abgrenzungskriterien

Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ ab. Darüber hinaus ist uns
keine andere Lösung bekannt, insbesondere keine die FLOSS ist, die mit unserer vergleichbare Ziele
verfolgt.


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

Unser Produkt wird ein Debug-werkzeug für diverse opencv-Funktionalität sein. Hierzu werden wir
die Ergebnisse von Filteroperationen verwenden um die Auswirkungen des Filters auf ein oder mehrere
Ursprungsbilder graphisch darzustellen.

Um das debuggen zu erleichtern und Codeänderungen im Anschluss überflüssig zu machen, werden wir die
Funktionalität dabei so implementieren, dass pro translation-unit der Debug-modus sowohl während
des Kompiliervorgangs als auch zur Laufzeit (de-)aktiviert werden kann. Bei der Deaktivierung während
des Kompilierens werden wir hierbei versuchen die Programmlaufzeit in keiner Weise negativ zu
beeinflussen.

Bei der Verwendung in Programmen mit mehreren Threads wird zwar mit eingeschränktem Komfort zu rechnen
sein, aber die prinzipielle Funktionalität an sich wird unbeeinträchtigt bleiben.

Zur Verwendung werden wir für die debugbaren opencv-Funktionalitäten Funktionen bereitstellen, welche
eine graphische Darstellung des Filters zu einem großen Debug-Hauptfenster hinzufügen werden (pro
Thread ein Hauptfenster).

Je nach Filter werden wir beispielsweise die Differenz zwischen zwei Bildern mit Pfeilen darstellen.
Hierbei soll es auch eine Möglichkeit geben, die Darstellungen selbst zu filtern, beispielsweise indem
nur Pfeile zwischen Unterschieden, die einen gewissen Schwellwert überschreiten, gezeichnet werden.

Produktdaten
------------

Keine?

Systemmodell
------------

* Das Interface wird aus öffentlichen Funktionen bestehen, die im Release-Modus nichts tun und im Debug-
	Modus, so gewünscht, die nicht-öffentlichen Debug-Methoden aufrufen
* Die nichtöffentlichen Debug-Funktionen erzeugen eine graphische Visalisierung und fügen diese dem
	Thread-lokalem Hauptfenster hinzu.

![Das Modul besteht aus drei Layern bei denen jeweils die Äußeren die
Inneren aufrufen](architektur_skizze.svg "Architekturskizze")


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

* keine Resource-Leaks
* kein undefiniertes Verhalten
* Threadsafety

Testfälle und Testszenarien
---------------------------
###Testfälle(erste Version wird noch bearbeitet)

###Testfälle für Filter

####Test 1
#####(Anzeige der Bilder, Auswählen eines Filters, Verändern der Werte
#####eines Filtes auch bei großen Bildern/langsameren Computern, Schließen des
#####Programms ohne Fehler)

Das Fenster zeigt ihm sein Originalbild und das Bild nach Anwendung des von
ihm ausgewählten Filter nebeneinander. Auch kann er die Werte für den Filter
mit einem Schieberegler verändern und sieht wie sich das Bild durch die
Änderung verändert. Da er aber ein sehr großes Bild benutzt hat, kann sein
Computer den Filter nicht so schnell auf das Bild anwenden und deshalb
freut er sich über  die Option die Werte einzutippen anstatt sie mit dem
Schieberegler auszuwählen da dieser etwas ruckelt.
Nach dem er den Wert zu seiner Zufriedenheit eingestellt hat, trägt den
ermittelten Wert bei sich ein, beendet das Programm und freut sich über
das neu entdeckte Debug Modul.

####Test 2
#####( benutzen des Programms auch mit mehreren Bildern, Speicher-/
#####Wiederherstellungs-Funktion, auch von Menschen lesbare Speicherdatei)

Der Programmierer ist so zufrieden mit dem Debug Modul das er es auch für
ein anderes Projekt benutzen will. Doch hat er diesmal will er mehrere
Filtereinstellungen testen die er vorher mit dem Debugmodul heraus finden
will. Da er nur keine Lust hat sich die Filtereinstellungen für jeden
einzelnen Schritte irgendwo aufzuschreiben und bei Bedarf wieder einzustellen,
benutzt er einfach die Speicherfunktion des Moduls und kann so bequem
und einfach die optimalen Filtereinstellungen finden.

####Test 3 (Voreinstellungen durch Api aufrufe im code)
 Noch zuschreiben falls nötig


###Testfälle für Matches

####Test 1

Der Programmierer arbeiten mit der Matchfunktion von OpenCV, damit er
das PRogramm einfacher debugen kann benutzer der das Debugmodul

Er schreibt die entsprechenden Aufrufe in seinem Code mit denen er sich
zwei Bilder anzeigen lassen kann auf denen die Matches visuell dargestellt werden.
Das Fenster zeigt im die zwei Bilder und er kann zwischen den Visualisierungen
für die Matches auf den beiden Bilder wechseln.
Auch kann er bestimmte Matches markieren und diese dann ausblenden/einblenden
oder sie zusammenfassen damit er eine bessere Übersicht hat.





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
