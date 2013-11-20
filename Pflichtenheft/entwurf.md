#Pflichtenheft CVVisual

##Einleitung
OpenCV ist ein im Jahre 1999 aus der Taufe gehobenes Projekt von Intel-Forschern.  
Es wurde im Jahre 2000 der breiteren Öffentlichkeit vorgestellt, 6 Jahre später erschien Version 1.0.  
Seitdem hat sich das Projekt stetig weiterentwickelt - es ist heute quasi der Standard unter den freien   
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
Funktionsumfang zurück (man kann damit im wesentlichen nur Bilder ansehen, die im Speicher liegen).
Besonders für Neulinge stellt dieses weitestgehende Fehlen von Visualisierungsmöglichkeiten  
zu Debugzwecken eine große Hürde dar.  

Das sich daran etwas ändert, ist Ziel unserer Arbeit als PSE-Team an einer  
Open Source-Visualisierung für OpenCV. 

##Zielbestimmungen

###API Musskriterien
* Auswahl der Visualisierung für Operationstyp
* Globale Auswahl zwischen Debug und Release Modus
* Unterstützung folgender Operationen:
	* [imgproc/Image Filtering](http://docs.opencv.org/modules/imgproc/doc/filtering.html): 
		* [dilate (Dilatation)](http://docs.opencv.org/modules/imgproc/doc/filtering.html#dilate)
		* [erode (Erosion)](http://docs.opencv.org/modules/imgproc/doc/filtering.html#erode)
		* [morphologyEx](http://docs.opencv.org/modules/imgproc/doc/filtering.html#morphologyex)
		* [Sobel](http://docs.opencv.org/modules/imgproc/doc/filtering.html#sobel)
	* [imgproc/Miscellaneous Image Transformations](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html): 
		* [threshold](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#threshold)
		* [adaptiveThreshold](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#adaptivethreshold)
		* [floodFill (Ausfüllen)](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#floodfill)
	* [feature2sd](http://docs.opencv.org/modules/features2d/doc/features2d.html): 
		* [KeyPoint](http://docs.opencv.org/modules/features2d/doc/common_interfaces_of_feature_detectors.html#keypoint) 
		* [DMatch](http://docs.opencv.org/modules/features2d/doc/common_interfaces_of_descriptor_matchers.html#dmatch)

###API Wunschkriterien
* Optionale Parameter für Einstellungen der Visualisierungen
* Lokale Auswahl Debug/Release
* Optionale nicht-blockierende Aufrufe für Streaming
* Unterstützung folgender Operationen:
	* imgproc/Histograms: [calcHist](http://docs.opencv.org/modules/imgproc/doc/histograms.html#calchist)
	* [imgproc/Feature Detection](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html): 
		* [Canny](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#canny)
		* [HoughCircles](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#houghcircles)
	* stitching
	* ocl (OpenCL)


###GUI Musskriterien
* Eine Visualisierung pro Operation (siehe API Kriterien)
* Drei Visualisierungen für features2d/DMatch (drei aus den Wunsch-Visualisierungen, siehe unten)
* Zoomfunktion

###GUI Wunschkriterien
* Hohe Zoomstufen mit Zusatzinformationen (z.B. Pixelwerte)
* Permanente GUI mit Historie
* Möglichkeit Operation mit geänderten Parametern erneut anzuwenden
* Datenfluss von GUI zu Code sofern sinnvoll
* Optionale Ausnutzung von mehreren Bildschirmen
* Interaktive Überlagerung von Zusatzinformationen (Mouse-Over)
* Darstellung von Verbindungslinien
	* (ähnlich [drawMatches](http://docs.opencv.org/modules/features2d/doc/drawing_function_of_keypoints
_and_matches.html?highlight=drawmatches#drawmatches))
	* Einzeichnen der Keypoints in die Bilder
	* Verbinden der Matches durch Linien
	* Einfärben der Linien mit Falschfarben
	* Ausblenden der Keypoints ohne Matches
	* Auswahl von Matches anhand eines Schwellwertes (bzw. Intervalls)
	* x% oder n besten/schlechtesten Matches
	* Manuelle Auswahl von Matches
* Darstellung von Rohdaten
	* Abmessungen der Bilder
	* Farbraum der Bilder (der in OpenCV genutzte Datentyp)
	* Durchschnittlicher / größter / kleinster Abstand aller / der ausgewählten Matches
	* Durchschnittliche / größte / kleinste Verschiebung aller / der ausgewählten Matches
* Darstellung von Projektionen
	* Einzeichnen von Linien / Formen
	* Auswählen von zugehörigen Matches
	* Die Linien / Formen werden auf das zweite Bild projiziert 
* Darstellungen für Filter
	* Differenzbilder ([u.A.](http://www.imagemagick.org/Usage/compare/#metrics%29))


###Nichtfunktionale Anforderungen
* **NF100** keine Resource-Leaks
* **NF200** kein undefiniertes Verhalten
* **NF300** Möglichst kein Overhead im Release-mode.
* **NF400** geringe Verzögerungen durch Berechnungen
* **NF500** Threadsafety
* **NF600** Tolleranz gegenüber fehlerhaften API-Aufrufen

##Abgrenzungskriterien
Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ ab. Darüber hinaus ist uns
keine andere Lösung bekannt die Open Source ist, die mit unserer vergleichbare Ziele verfolgt.
Unser Projekt ist kein Standaloneprogramm und wird voraussichtlich keinen rückläufigen Datenfluss unterstützen.

##Produkteinsatz
Die Software soll zunächst im universitären Forschungsumfeld des beauftragenden Institutes eingesetzt
werden. Später kann der Nutzerkreis potentiell auf alle OpenCV Benutzer ausgedehnt werden, welche
OpenCV mit Qt Unterstützung kompiliert haben.

##Produktumgebung
Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt5 laufen sowie ein
C++11-Compiler.

##Produktfunktion
Unser Produkt wird ein Debug-Werkzeug für diverse OpenCV-Funktionalität sein. Hierzu werden wir
die Ergebnisse von Filteroperationen verwenden, um die Auswirkungen des Filters auf das
Ursprungsbild zu visualisieren.

Um das Debuggen zu erleichtern und Codeänderungen im Anschluss überflüssig zu machen, werden wir die
Funktionalität dabei so implementieren, dass pro translation-unit der Debug-modus sowohl während
des Kompiliervorgangs als auch zur Laufzeit (de-)aktiviert werden kann. Bei der Deaktivierung während
des Kompilierens werden wir hierbei versuchen die Programmlaufzeit in keiner Weise negativ zu
beeinflussen.

Bei der Verwendung in Programmen mit mehreren Threads wird zwar mit eingeschränktem Komfort zu rechnen
sein, aber die prinzipielle Funktionalität an sich wird unbeeinträchtigt bleiben.

Zur Verwendung werden wir für die debugbaren opencv-Funktionalitäten Funktionen bereitstellen, welche
eine graphische Darstellung des Filters zu einem großen Debug-Hauptfenster hinzufügen werden (pro
Thread ein Hauptfenster).

Je nach View werden wir beispielsweise die Matches zwischen zwei Bildern mit Pfeilen darstellen.
Hierbei soll es auch eine Möglichkeit geben, die Darstellungen selbst zu filtern, beispielsweise indem
nur Pfeile zwischen Unterschieden, die einen gewissen Schwellwert überschreiten, gezeichnet werden.


##Produktdaten
Rein aus der Konzeption unseres Projektes her, sind die meisten Produktdaten dem Typ der Dokumentation zu zurechnen. Diese ist auf Grund des OpenSource-Gedanken nicht wichtig genug einzuschätzen.

- Handbuch:
	Es umfasst Erklärungen zur Benutzung der GUI, der einzelnen Visualisierungen und der Bibliothek. Des Weiteren sind ein
	Wegweiser zum Schnelleinstieg und Anleitungen zur Entwicklung von Erweiterungen des Projekts, insbesondere durch
	das Hinzufügen neuer Views, enthalten.
- Dokumentation: Es ist im wesentlichen die Dokumentation, welche dem Quellcode des Projektes entstammt und klar stellt, wie z.B. die API zu verwenden ist.
- FAQ
- Einstellungen:
	Einstellungen der Übersichtsseite und der einzelnen Visualisierungen,
	welche vom Benutzer verändert wurden, sollen gespeichert werden.
- Rohdaten:
	In vielen Views wird es möglich sein, die Rohdaten in einem gewünschten Format (z.B. CSV oder JSON) in einer Datei abzuspeichern.
- Ursprungsbilder sowie, Visualisierungen in Form von Schnappschüssen

##Systemmodell
* Das Interface wird aus öffentlichen Funktionen bestehen, die im Release-Modus nichts tun und im Debug-
	Modus, so gewünscht, die nicht-öffentlichen Debug-Methoden aufrufen
* Die nichtöffentlichen Debug-Funktionen erzeugen eine graphische Visalisierung und fügen diese dem
	Thread-lokalem Hauptfenster hinzu.

![Das Modul besteht aus drei Layern bei denen jeweils die Äußeren die
Inneren aufrufen](architektur_skizze.svg "Architekturskizze")

##Produktleistungen
//TODO: weg?

##Bedienoberfläche
* Die Bedienoberfläche wird in Qt implementiert sein.
* Sie wird aus einem Hauptfenster pro Thread bestehen.
* Die verschiedenen Debug-Ansichten werden im Hauptfenster dargestellt.

##Qualitätszielbestimmungen
//TODO: weg? (ist eigendlich nf)

##Testfälle und Testszenarien

Unser Projekt ist eine reine Debug-Bibliothek, die es dem Benutzer möglichst einfach macht,
seine Bilddaten zu visualisieren. Deshalb enthält der Funktionsumfang im Grunde genommen nur
Visualisierungen und die meisten Testszenarios besitzen auch auf Grund dessen die folgende Struktur: 
* -> der Programmierer schreibt den gewünschten API-Aufruf an die gewünschte Stelle in seinen Quelltext.
* -> Ein Fenster öffnet sich und visualisiert die beim Aufruf übergebenen Daten.
* -> Nun kann er mit der Visualisierung arbeiten, sie in den Einstellungen anpassen oder die Visualisierung wechseln.
* -> Bei blockierenden Aufrufen klickt er nun auf einen Button, der das aufrufende Programm weiterlaufen lässt.
* -> Er sucht entweder weiter Fehler in seinem Programm, oder sieht die angefallenen Datensätze in der Übersichtsseite durch und visualisiert die gewünschten.
* -> Der Programmierer ist jetzt hoffentlich glücklich, weil er seinen Bug gefunden oder OpenCV wieder etwas besser verstanden hat.
* -> Die Debugumgebung lässt sich ohne Fehler beenden.

###Tests für Filterview 
* Anzeige der/des Bild(es)
* Auswählen und wechseln vom Filter
* Ändern der Werte eines Filters
* Bedienung bei einem Großen Bild und geringer Rechenleistung
* Benutzung mit mehr als einem Bild


###Tests für Matchview
* Anzeige der/des Bild(es)
* Auswählen und wechseln von Views
* Sämtliche Buttons und Schieberegler testen
* Bedingung auch mit großen Bildern und mit geringer Rechenleistung

##Entwicklungsumgebung

###Quellcode
* GCC 4.8.0 oder später
	Der GCC ist die vom GNU Projekt entwickelte Compiler Sammlung, welche den verwendeten C++ Compiler enthällt.
	Es wird hierbei eine Version >= 4.8.0 erwartet, da frühere Versionen manche verwendeten C++ Eigenschaften noch nicht
	unterstützen.
* Qt 5
* C++11
* OpenCV
* GNU/Linux (besonders Ubuntu 12.04)
* CMake

###Dokumentation
Zur Dokumentation werden im wesentlichen die auch von OpenCV verwendeten Werkzeuge benutzt.
Die folgende Aufzählung wird im Verlauf des Projektentwicklung unter Umständen noch erweitert.
* SPHINX: Ein in Python geschriebenes Werkzeug mit dessen Hilfe, das Handbuch und das FAQ geschrieben wird.
* Doxygen: Ein weitverbreitetes Werkzeug um aus den Kommentaren im Quelltext unseres Projektes eine übersichtliche Quelltextdokumentation zu erzeugen (vgl. Produktdaten). Es wird in Verbindung mit SPHINX verwendet.

##Lizenz
Unser Projekt ist OpenSource, weshalb jegliche Dokumentation und Quelllcode unter freien Lizenzen stehen.
Im folgenden werden nun kurz die Lizenzen für Dokumentation und Quelltext erläutert.

###Quellcode
Der Quelltext dieses Projektes steht in seiner Gesammtheit unter der BSD Clause 3 Lizenz, da auch OpenCV unter dieser Lizenz steht.
Die BSD Clause 3 Lizenz erlaubt es anderen Entwicklern den Quelltext unseres Projektes, wie auch dessen Binärformen, weiterzuverteilen und zu verändern,
solange der folgende Lizenzabschnitt im Programm selbst, dem Quelltext und der Dokumentation enthalten ist.
Außerdem ist es verboten, den Namen CVVisual oder die Namen der Mitentwickler zur Produktwerbung zu verwenden, ohne dass eine vorherige Erlaubnis eingeholt wurde.

	Copyright (c) 2013, CVVisual PSE Team
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
		* Redistributions of source code must retain the above copyright
		   notice, this list of conditions and the following disclaimer.
		* Redistributions in binary form must reproduce the above copyright
		   notice, this list of conditions and the following disclaimer in the
		   documentation and/or other materials provided with the distribution.
		* Neither the name of the <organization> nor the
		   names of its contributors may be used to endorse or promote products
		   derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
	ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
	WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE CVVISUAL DEVELOPERS BE LIABLE FOR ANY
	DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
	(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
	ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Diese Lizenz hat außerdem, gegenüber z.B. der GNU GPL, den Vorteil, dass es auch eine Verwendung unseres Projektes
im Umfeld proprietärer Lizenzen erlaubt, und damit hoffentlich auch von Unternehmen genutzt werden kann.

###Dokumentation
Die Dokumentation, mit sammt aller Bilder und Texte, steht unter der [CC-BY-SA Lizenz](https://creativecommons.org/licenses/by-sa/3.0/),
sofern nicht anders angegeben. 
Die Lizenz erlaubt es anderen die Dokumentation und Teile jener, zu kopieren und weiter zu verteilen, zu verändern und zu kommerziellen Zwecken
zu verwenden. Hierbei muss allerdings immer der Autor genannt werden und abgeleitete Werke müssen unter der selben, oder einer gleichwertigen,
Lizenz gestellt werden.

##Glossar
###Allgemein:
* API: Application Programming Interface. Eine Schnittstelle, über welche andere Programme auf der 
	Quelltextebene auf dahinter verborgene Funktionalität zugreifen können.

* Augmented Reality: "Erweiterung der Realität" durch einen Computer, etwa bei der Einblendung von
	Informationen in ein Bild der Umgebung, das etwa auf einem Smartphone angezeigt wird.

* Bug: Fehlerhaftes Verhalten eines Programmes.
		
* Binärform: Hier das Programm in für den Computer direkt verwendbarer Form im Gegensatz zum
	Quellcode. Anders als dort ist hier kaum sichtbar, wie das Programm genau arbeitet,
	weshalb bei Open-Source-Projekten gerade der Quelltext offen liegt (daher der Name).

* Datenstrom: Daten, die beispielsweise während der Ausführung eines Programms fließen, 
	wobei das Ende dieses Flusses nicht absehbar ist.

* Debug-Modus: Modus, bei dem zusätzliche Informationen angezeigt werden, um dem Programmierer das
	Auffinden und Beheben von Bugs (kurz Debugging oder Debuggen), hier insbesondere 
	Programmierfehlern, zu erleichtern. Vgl. Release-Modus.

* Debug-Visualisierung: Eine Visualisierung die den Benutzer beim Debuggen unterstützt, in dem sie relevante
	Daten zu den übergebenen Bilder anzeigt und diese damit leicht verständlich darstellt.

* FAQ: Engl. für "Häufig gestellte Fragen" enthält sie viele Fragen, die besonders neue Benutzer sich stellen, wenn sie anfangen unser Projekt zu nutzen.
 
* Filter: In der Bildverarbeitung die Veränderung eines Bildbereiches mithilfe eines bestimmten Algorithmus.

* freie Lizenz: Lizenz, die im Sinne der [Open Source Initiative](opensource.org), die Veränderung und Weitergabe des unter ihr lizenzierten Inhalts ermöglicht.

* GNU: "GNU is Not Unix". Freies Betriebssystem und Software.

* GNU GPL: General Public License. Eine freie Software-Lizenz. Alle auf einer unter dieser Lizenz stehenden
	Software aufbauenden Software steht ebenfalls unter dieser Lizenz.

* GNU/Linux: Das GNU-Betreibssystem in Kombination mit einem Linux-Kernel.

* GNU-Projekt: Das Projekt zur Erstellung von GNU-Betriebssystem und Software.

* GUI: Graphical User Interface, zu deutsch Graphische Benutzeroberfläche. Stellt Funktionen graphisch dar,
	so dass der Benutzer beispielsweise per Mausklick damit interagieren kann; im Gegensatz zu
	textbasierten Benutzerschnittstellen.

* Interface: Schnittstelle. Ein Zugriffspunkt auf Funktionalitäten von außen, der einerseits den Zugriff 
	erleichtern und andererseits die eigentliche Funktionalität verbergen soll.

* Matches: Durch OpenCV erzeugte Verknüpfungen zwischen zwei Bildbereichen bzw. Bildpixeln, 
	welche vom Benutzer an die API übergeben werden.

* OpenSource: Deutsch offene Quelle. Software, bei welcher der Quellcode frei zugänglich gemacht wird.
	Dies erlaubt unter anderem die Weiterverwendung und -entwicklung durch andere.
 
* Overhead: Zusätzlicher Speicher- oder Zeitaufwand.

* Plug-in: Grob gesagt Zusatzfunktionalität für ein Programm.

* proprietär: In diesem Zusammenhang Software, die nicht unter einer freien Lizenz steht.

* Quellcode oder Quelltext: In einer Programmiersprache geschriebener Text, der zu einem 
	Computerprogramm umgewandelt werden kann. Vgl. auch Binärform.

* „random code“: Individueller Wegwerfcode der nur für eine einzige Probleminstanz hilfreich ist und
	sich meist durch nichtexistentes Design auszeichnet.

* Release-Modus: Veröffentlichungs-Modus, in dem keine zusätzlichen Debug-Informationen 
	angezeigt werden, also der Modus, in dem das fertige Programm läuft.

* Resource-Leak: Das Auftreten der Situation, dass Ressourcen irgendeiner Art (Speicher, Dateien, usw.) zwar
	alloziert werden, aber nach Verwendung nicht mehr an das System zurückgegeben werden.

* Rohdaten: Daten, die direkt und ohne wirkliche Aufarbeitung, aus den vom Entwickler beim API-Aufruf übergebenen Datenstrukturen stammen.

* Streaming: Hier das Weiterlaufen des Datenstroms.

* Thread: Dt. Faden. Moderne Computer besitzen mehrere Prozessorkerne, die sich Rechenarbeit aufteilen
	können. Ein solcher Teil wird als Thread bezeichnet.

* Threadsafety: Es ist sichergestellt, das mehrere Threads sich nicht gegenseitig in die Quere kommen, etwa
	beim Speichern von Daten.

* Undefiniertes Verhalten: Instruktionen deren Verwendung dazu führt, dass der C++-Standard *keinerlei*
	Verhaltensgarantien irgendeiner Art für das gesammte Programm mehr gibt. Etwas Umgangssprachlich:
	Der Standard untersagt die Verwendung.

* View: Zusammengehörige Visualisierungen eines bestimmten OpenCV-Features (oder Featureart).

* Visual Studio: Integrierte Entwicklungsumgebung, d.h. Programm zur Softwareentwicklung, das zur 
	Vereinfachung der Arbeit verschiedene Anwendungsprogramme, die sonst einzelnen aufgerufen 
	werden müssten, vereint, welche von Microsoft entwickelt wurde und verschiedene 
	Programmiersprachen unterstützt.

###OpenCV:
* adaptiveThreshold: OpenCV-Methode, die mittels eines adaptiven threshold (s. unten) Graustufenbilder 
	in (u.U. invertierte) Binärbilder umwandeln kann.

* calcHist: Berechnet Histogramm.

* Canny: Kantenerkennung (mithilfe des Canny86-Algorithmus).

* Dilatation: Berechnung des Bereiches in einem Bild, der von einer Maske abgedeckt wird, wenn sich deren
	Bezugspunkt durch den ganzen zu untersuchenden Bildbereich bewegt.

* DMatch: Klasse für das Matching (vgl. Matches)

* Erosion: Prüft, ob eine Maske, etwa eine geometrische Figur, vollständig in ein Bild 
	bzw. einen Bildbereich passt und gibt u.U. ein Bild zurück,
	 in dem nur die überdeckten Teile erhalten sind. 
	Bildet zusammen mit der Dilatation zwei der grundlegenden Bilverarbeitungsmethoden.

* floodFill: Bei dieser Methode wird ein zusammenhängender Bereich des Bildes 
	mit der übergebenen Farbe ausgefüllt.

* HoughCircles: Findet Kreise in einem Graustufenbild (unter Benutzung der Hough-Transformation).

* KeyPoint: Klasse, die Daten eines Punktes (Koordinaten, Nachbarschaftsgröße etc.) enthält.

* morphologyEx: diese Methode von OpenCV erlaubt fortgeschrittene morphologische Transformationen
	unter Benutzung und mehrfacher Anwendung von Dilatation und Erosion.

* ocl:  Das OCL-Modul stellt Implementierungen von OpenCV-Funktionalität für Geräte, 
	welche die Open Computing Language (kurz OpenCL), ein Interface über Parallelrechner, benutzen, 
	zur Verfügung.

* Sobel-Operator: Ein Kantenerkennungs-Filter.

* Stitching: Zusammenfügen mehrerer Bilder mit zusammenhängnden Bereichen an den Rändern 
	zu einem großen Bild, etwa von Einzelfotografien zu einem Panorama.

* threshold: Diese Methode eröffnet verschiedene Möglichkeiten, die Elemente eines Arrays auf ein 
	bestimmtes Niveau zu trimmen, auf binäre Werte herunterzubrechen und ähnliches.


##Literatur
- Technisches Schreiben -- (nicht nur) für Informatiker / Peter Rechenberg:
	Ein anschaulich und verständlich geschriebenes Buch, dass hilft den eigenen Schreibstil zu verbessern. Und damit die Verständlichkeit 
	der geschriebenen Dokumentation (vgl. Produktdaten) zu erhöhen.
- Designed for Use -- Create Usable Interfaces for Applications and the Web / Lukas Mathis:
	Die vorliegenden GUI-Entwürfe (vgl. Quarktasche) sind stark von diesem Buch beeinflusst, da es wichtige Techniken, Methoden und Denkmuster
	der UI-Entwicklung vermittelt. (Und das in einer für Informatiker verständlichen Sprache.)
