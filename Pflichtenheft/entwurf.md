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
Funktionsumfang zurück, mit dem man Bilder direkt im Speicher ansehen kann.
Besonders für Neulinge stellt dieses weitestgehende Fehlen von Visualisierungsmöglichkeiten  
zu Debugzwecken eine große Hürde dar.  

Das sich daran etwas ändert, ist Ziel unserer Arbeit als PSE-Team an einer  
Open Source-Visualisierung für OpenCV. 

##Produktfunktionen
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

##Produkteinsatz
Die Software soll zunächst im universitären Forschungsumfeld des beauftragenden Institutes eingesetzt
werden. Später kann der Nutzerkreis potentiell auf alle OpenCV Benutzer ausgedehnt werden, welche
OpenCV mit Qt Unterstützung kompiliert haben.

##Produktumgebung
Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt5 laufen sowie ein
C++11-Compiler.

##Funktionale Anforderungen

###API (pflicht)
* __FA010__: Globale Auswahl zwischen Debug und Release Modus
* __FA020__: Auswahl der Visualisierung für Operationstyp
* Unterstützung folgender Operationen:
	* [imgproc/Image Filtering](http://docs.opencv.org/modules/imgproc/doc/filtering.html): 
		* __FA021__: [dilate (Dilatation)](http://docs.opencv.org/modules/imgproc/doc/filtering.html#dilate)
		* __FA022__: [erode (Erosion)](http://docs.opencv.org/modules/imgproc/doc/filtering.html#erode)
		* __FA023__: [morphologyEx](http://docs.opencv.org/modules/imgproc/doc/filtering.html#morphologyex)
		* __FA024__: [Sobel](http://docs.opencv.org/modules/imgproc/doc/filtering.html#sobel)
	* [imgproc/Miscellaneous Image Transformations](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html): 
		* __FA025__: [threshold](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#threshold)
		* __FA026__: [adaptiveThreshold](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#adaptivethreshold)
		* __FA027__: [floodFill (Ausfüllen)](http://docs.opencv.org/modules/imgproc/doc/miscellaneous_transformations.html#floodfill)
	* [feature2sd](http://docs.opencv.org/modules/features2d/doc/features2d.html): 
		* __FA028__: [KeyPoint](http://docs.opencv.org/modules/features2d/doc/common_interfaces_of_feature_detectors.html#keypoint) 
		* __FA029__: [DMatch](http://docs.opencv.org/modules/features2d/doc/common_interfaces_of_descriptor_matchers.html#dmatch)

###API (optional)
* __FA030__: Optionale Parameter für Einstellungen der Visualisierungen
* __FA040__: Lokale Auswahl Debug/Release
* __FA050__: Optionale nicht-blockierende Aufrufe für Streaming
* __FA060__: Unterstützung folgender Operationen:
	* __FA061__: imgproc/Histograms: [calcHist](http://docs.opencv.org/modules/imgproc/doc/histograms.html#calchist)
	* [imgproc/Feature Detection](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html): 
		* __FA062__: [Canny](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#canny)
		* __FA063__: [HoughCircles](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#houghcircles)
	* __FA064__: [stitching](http://docs.opencv.org/modules/stitching/doc/stitching.html)
	* __FA065__: [ocl](http://docs.opencv.org/modules/ocl/doc/introduction.html) (OpenCL)


###GUI (pflicht)
* __FA070__: Eine Visualisierung pro Operation (siehe API Kriterien)
* __FA080__: Drei Visualisierungen für features2d/DMatch (drei aus den Wunsch-Visualisierungen, siehe unten)
* __FA090__: Zoomfunktion

###GUI (optional)
* __FA100__: Permanente GUI mit Historie
* __FA110__: Datenfluss von GUI zu Code (sofern sinnvoll)
* __FA120__: Möglichkeit eine Operation mit geänderten Parametern erneut anzuwenden
* __FA130__: Hohe Zoomstufen mit Zusatzinformationen (z.B. Pixelwerte)
* __FA140__: Optionale Ausnutzung von mehreren Bildschirmen
* __FA150__: Interaktive Überlagerung von Zusatzinformationen (Mouse-Over)
* __FA160__: Flexibler Umgang mit unterschiedlichen Bildschirm- und Bildauflösungen
* __FA170__: Suchleiste für alle Tabellen (z.B. jener der Übersichtsseite oder der Rohdatendatenanzeige)
	* Zur einfachen Arbeit mit größeren Tabellen
	* __FA171__: Ermöglicht mit einer speziellen Syntax zum Beispiel die Sortierung oder Gruppierung von Datensätzen

###Mögliche Visualisierungen //TODO rewrite

####Allgemein
* __FA180__: Darstellung von Rohdaten
	* Abmessungen der Bilder
	* Farbraum der Bilder (der in OpenCV genutzte Datentyp)
	* Tabellarische Darstellung, z.B. der Matches, mit Filtermöglichkeit
	* Diagramme (wie Histogramme)
* __FA190__: Darstellung der Bilder nebeneinander

####Visualisierungen von Matches
* __FA200__: Basisvisualisierung _(ähnlich [´drawMatches´](http://docs.opencv.org/modules/features2d/
doc/drawing_function_of_keypoints_and_matches.html?highlight=drawmatches#drawmatches))_
	* Einzeichnen der Keypoints in die Bilder
	* Verbinden der Matches durch Linien oder Pfeile
	* Einfärben der Linien, Pfeile oder Punkte mit Falschfarben
	* Ausblenden der Keypoints ohne Matches
	* Auswahl von Matches anhand bestimmter Kriterien (z.B. via Histogramm)
	* Manuelle Auswahl von Matches
	* Automatische Zusammenfassung von Matches zu Gruppen
* __FA210__: Projektionen
	* Einzeichnen von Linien / Formen
	* Auswählen von zugehörigen Matches
	* Die Linien / Formen werden auf das zweite Bild projiziert
	* Automatische Gruppierung der Matches zu Flächen
* __FA220__: Darstellung von Punkttranslationen von einem Bild zum anderen mit Pfeilen
	* Pfeillänge und Richtung entsprechen der jeweiligen Translation
* __FA230__: Stereokopische Darstellung als Tiefenbild
	* Pixelfarbwerte entsprechen den jeweiligen Tiefenwerten
#### Visualisierungen für Filter
	* __FA240__: Differenzbilder 
		* [u.A.](http://www.imagemagick.org/Usage/compare/#metrics%29)
	* __FA250__: Überlagerungen
	* __FA260__: Direkte Anwendung von Filtern auf beide Bilder
		* Beispiel: Anwendung eines Kantenfilters um die Auswirkungen z.B. einer Kantenglättung zu visualisieren
	* __FA270__: Visualisierung über die Auswirkungen auf bestimmte Bildmetriken
		* z.B. Überlagerung von Histogrammen beider Bilder oder Vergleich der Kontrastwerte von bestimmten Bildbereichen

##Nichtfunktionale Anforderungen
###Produktleistungen (pflicht)
* __NF010__: Die GUI soll schnell starten und interaktiv bedienbar sein
* __NF020__: Möglichst kein Overhead im Release-mode.

###Produktleistungen (optional)
* __NF030__: Flexibler Umgang mit unterschiedlichen Bildschirm- und Bildauflösungen
* __NF040__: Integration in OpenCV Test Framework

###Qualitätsanforderungen (pflicht)
* __NF050__: Keine signifikanten Speicherlecks
* __NF060__: Erweiterbarkeit um zusätzliche OpenCV Operationen und Visualisierungen
* __NF070__: Modularer Aufbau (API und GUI)
* __NF080__: Modularer Aufbau (API und GUI)
* __NF090__: Einhaltung der OpenCV und Qt Konventionen
* __NF100__: Ausführliche Dokumentation der API und des GUI

###Qualitätsanforderungen (optional)
* __NF110__: Dokumentation des internen Codes mit Werkzeug
* __NF120__: OpenCV geeigneter Aufbau des Build-Systems
* __NF130__: Abdeckung durch Tests
* __NF140__: keine Resource-Leaks
* __NF150__: Threadsafety
* __NF160__: Tolleranz gegenüber fehlerhaften API-Aufrufen
* __NF170__: keine Resource-Leaks
* __NF180__: kein undefiniertes Verhalten

##Produktdaten
Rein aus der Konzeption unseres Projektes her, sind die meisten Produktdaten dem Typ der Dokumentation zu zurechnen. Diese ist auf Grund des OpenSource-Gedanken nicht wichtig genug einzuschätzen.

- __PD100__: Handbuch:
	Es umfasst Erklärungen zur Benutzung der GUI, der einzelnen Visualisierungen und der Bibliothek. Des Weiteren sind ein
	Wegweiser zum Schnelleinstieg und Anleitungen zur Entwicklung von Erweiterungen des Projekts, insbesondere durch
	das Hinzufügen neuer Views, enthalten.
- __PD200__: Dokumentation: Es ist im wesentlichen die Dokumentation, welche dem Quellcode des Projektes entstammt und klar stellt, wie z.B. die API zu verwenden ist.
- __PD300__: FAQ
- __PD400__: Einstellungen:
	Einstellungen der Übersichtsseite und der einzelnen Visualisierungen,
	welche vom Benutzer verändert wurden, sollen gespeichert werden.
- __PD500__: Rohdaten:
	In vielen Views wird es möglich sein, die Rohdaten in einem gewünschten Format (z.B. CSV oder JSON) in einer Datei abzuspeichern.
- __PD600__: Ursprungsbilder sowie Visualisierungen in Form von Schnappschüssen

##Systemmodell
* Das Interface wird aus öffentlichen Funktionen bestehen, die im Release-Modus nichts tun und im Debug-
	Modus, so gewünscht, die nicht-öffentlichen Debug-Methoden aufrufen
* Die nichtöffentlichen Debug-Funktionen erzeugen eine graphische Visalisierung und fügen diese dem
	Thread-lokalem Hauptfenster hinzu.

![Das Modul besteht aus drei Layern bei denen jeweils die Äußeren die
Inneren aufrufen](architektur_skizze.png "Architekturskizze")

##Bedienoberfläche

* Die Bedienoberfläche wird in Qt implementiert sein.
* Sie wird aus einem Hauptfenster pro Thread bestehen.
* Die verschiedenen Debug-Ansichten werden entweder im Hauptfenster oder in einzelnen Fenstern dargestellt.
* Daten von vorherigen API-Aufrufen werden auf einer Übersichtsseite tabellarisch dargestellt

###Skizzen //TODO write explanations

![Übersichtseite mit Tabs und ohne Vorschaubilder](GUI/overview_tabs_wo_images.png)
Übersichtseite mit Tabs und ohne Vorschaubildern.
Dem Benutzer ist mit Hilfe der Sucheleiste möglich in den vorhandenen Datensätzen zu suchen.


![Übersichtseite mit Tabs und Vorschaubildern](GUI/overview_tabs_images.png)

Übersichtseite mit Tabs und Vorschaubildern.



![Übersichtseite mit Fenstern und Vorschaubildern](GUI/overview_windows_images.png)

Übersichtseite mit Fenstern statt Tabs und Vorschaubildern.



![Basisvisualisierung eines Match-Datensatzes](GUI/test_match_window.png)

Basisvisualisuerung eines Match-Datensatzes.

Unten in der Fensterleiste findet sich der aktuelle Zoomfaktor und die aktuelle Position in einem der beiden Bilder.
Wichtig: Die Position entspricht jener im gesamten Bild - nicht jener im angezeigten Ausschnitt.

Mit dem Button "View Raw" kann der Benutzer die Rohdatenanzeige für den aktuellen Datensatz anzeigen.
Der Button "Step further" wird angezeigt, sofern die zu debuggende Anwendung wegen dieser Visualisierung blockiert. Wobei damit
die Visualisierung nicht geschlossen wird.

Die View-Auswahl und die Zoom-Knöpfe am rechten Rand sind selbsterklärend. Bei Eindrücken des
Schlossknopfes versucht das Programm die Anzeigen beider Bilder zu synchronisieren.



![Rohdatenanzeige](GUI/test_match_raw_window.png)

Tabellarische Anzeige der Rohdaten, nach dem der Benutzer in der vorherigen Skizze auf den "View Raw"-Knopf gedrückt hat.

Dem Benutzer ist es wieder möglich mit Hilfe der Suchleiste in den Daten zu suchen und mit gedrückter STRG-Taste auch mehrere Einträge
zu markieren. Über das Kontextmenu ist es weiterhin möglich entweder die ausgewählten Einträge in der Visualisierung hervorzuheben oder sie
als JSON oder CSV in die Zwischenablage zu kopieren.



![Hohe Zoomstufen mit Zusatzinformationen](GUI/test_match_deep_zoom_window.png)

Der Benutzer sieht bei einem hohen Zoomfaktor Zusatzinformationen im Bild, in diesem Fall die Werte für Rot, Grün, Blau für jedes einzelne Pixel.



![Projektion](GUI/test_match_area_tab.png)

Projektion einer automatischen Gruppierung von Matches von einem auf das andere Bild.
Hierbei wird jeweils das Histogramm des vom Benutzer ausgewählten Bereichs angezeigt. 



![Darstellung von Punkttranslationen](GUI/match_movement_parrot_window.png)

Darstellung von Punkttranslationen von einem Bild zum anderen mit Pfeilen.
Die Länge und Richtung des jeweiligen Pfeils entsprechen der Translation oder Verschiebung des Startpunktes im anderen Bild.


##Testfälle und Testszenarien

Unser Projekt ist eine reine Debug-Bibliothek, die es dem Benutzer möglichst einfach macht,
seine Bilddaten zu visualisieren. Deshalb enthält der Funktionsumfang im Grunde genommen nur
Visualisierungen und die meisten Testszenarios besitzen auf Grund dessen die folgende Struktur: 
* -> der Programmierer schreibt den gewünschten API-Aufruf an die gewünschte Stelle in seinen Quelltext.
* -> Ein Fenster öffnet sich und visualisiert die beim Aufruf übergebenen Daten.
* -> Nun kann er mit der Visualisierung arbeiten, sie in den Einstellungen anpassen oder die Visualisierung wechseln.
* -> Bei blockierenden Aufrufen klickt er nun auf einen Button, der das aufrufende Programm weiterlaufen lässt.
* -> Er sucht entweder weiter Fehler in seinem Programm, oder sieht die angefallenen Datensätze in der Übersichtsseite durch und visualisiert die gewünschten.
* -> Der Programmierer ist jetzt hoffentlich glücklich, weil er seinen Bug gefunden oder OpenCV wieder etwas besser verstanden hat.
* -> Die Debugumgebung lässt sich ohne Fehler beenden.

###Tests für Filterview 
* Anzeige des Bildes/der Bilder
* Auswählen und wechseln vom Filter
* Ändern der Werte eines Filters
* Bedienung bei einem Großen Bild und geringer Rechenleistung
* Benutzung mit mehr als einem Bild


###Tests für Matchview
* Anzeige des Bildes/der Bilder
* Auswählen und wechseln von Views
* Sämtliche Buttons und Schieberegler testen
* Bedingung auch mit großen Bildern und mit geringer Rechenleistung

##Abgrenzungskriterien
Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ ab. Darüber hinaus ist uns
keine andere Lösung bekannt die Open Source ist, die mit unserer vergleichbare Ziele verfolgt.

Wichtig: Unser Projekt ist kein Standaloneprogramm und wird voraussichtlich keinen rückläufigen Datenfluss unterstützen.

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
* SPHINX: Ein in Python geschriebenes Werkzeug mit dessen Hilfe das Handbuch und das FAQ geschrieben wird.
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
		* Neither the name of the cvvisual project nor the
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
* API: Application Programming Interface. Eine Schnittstelle (s. Interface), über welche andere Programme 
	auf der Quelltextebene auf dahinter verborgene Funktionalität zugreifen können.

* Augmented Reality: "Erweiterung der Realität" durch einen Computer, etwa bei der Einblendung von
	Informationen in ein Bild der Umgebung, das etwa auf einem Smartphone angezeigt wird.

* Bug: Fehlerhaftes Verhalten eines Programmes.
		
* Binärform: Hier das Programm in für den Computer direkt verwendbarer Form im Gegensatz zum
	Quellcode. Anders als dort ist hier kaum sichtbar, wie das Programm genau arbeitet,
	weshalb bei Open-Source-Projekten gerade der Quelltext offen liegt (vgl. OpenSource).

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
	textbasierten Benutzerschnittstellen (vgl. Interface).

* Interface: Schnittstelle. Ein Zugriffspunkt auf Funktionalitäten von außen, der einerseits den Zugriff 
	erleichtern und andererseits die eigentliche Funktionalität verbergen soll.

* Matches: Durch OpenCV erzeugte Verknüpfungen zwischen zwei Bildbereichen bzw. Bildpixeln, 
	welche vom Benutzer an die API übergeben werden.

* OpenSource: Deutsch offene Quelle. Software, bei welcher der Quellcode frei zugänglich gemacht wird.
	Dies erlaubt unter anderem die Weiterverwendung und -entwicklung durch andere.
 
* Overhead: Zusätzlicher Speicher- oder Zeitaufwand.

* Plug-in: Erweiterungsmodul zur Bereitstellung zusätzlicher Funktionalität für Anwendungssoftware.

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

* Stand-Alone-Programm: Programm, das für sich alleine funktioniert.

* Streaming: Hier das Weiterlaufen des Datenstroms.

* Thread: Ausführungsreihenfolge in einem Programm. Der Begriff wird insbesondere im Zusammenhang mit
	Mehrfachkernsystemen, wo mehrere Threads gleichzeitig laufen können, oft verwendet.

* Threadsafety: Es ist sichergestellt, das mehrere Threads sich nicht gegenseitig stören, etwa
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
