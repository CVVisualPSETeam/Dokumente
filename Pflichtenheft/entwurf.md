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


###API Kriterien

####Musskriterien

//TODO: Überlegen ob nicht lieber deutsche Beschreibung der Feautures mit Verweis auf Bezeichnung
//->	Bei einigen die deutschen Begriffe hinzugefügt; komplexere im Glossar kurz erklärt.

#####Unterstützte OpenCV Features
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

#####Allgemeine API Features
* Auswahl der Visualisierung für Operationstyp
* Globale Auswahl zwischen Debug und Release Modus

####Wunschkriterien
#####Unterstützte OpenCV Features
* imgproc/Histograms: [calcHist](http://docs.opencv.org/modules/imgproc/doc/histograms.html#calchist)
* [imgproc/Feature Detection](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html): 
	* [Canny](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#canny)
	* [HoughCircles](http://docs.opencv.org/modules/imgproc/doc/feature_detection.html#houghcircles)
* stitching
* ocl (OpenCL)

#####Allgemeine API Features
* Optionale Parameter für Einstellungen der Visualisierungen
* Lokale Auswahl Debug/Release
* Optionale nicht-blockierende Aufrufe für Streaming


###GUI Kriterien
####Musskriterien
* Eine Visualisierung pro Operation (siehe API Kriterien)
* Drei Visualisierungen für features2d/DMatch (drei aus den Wunsch-Visualisierungen, siehe unten)
* Zoomfunktion

####Wunschkriterien
#####Visualisierungen
######Für Matches
// TODO: format anpassen! es kann keine weitere unterüberschrift genutzt werden

#######Verbindungslinien
_(ähnlich [drawMatches](http://docs.opencv.org/modules/features2d/doc/drawing_function_of_keypoints
_and_matches.html?highlight=drawmatches#drawmatches))_
* Einzeichnen der Keypoints in die Bilder
* Verbinden der Matches durch Linien
* Einfärben der Linien mit Falschfarben
* Ausblenden der Keypoints ohne Matches
* Auswahl von Matches anhand eines Schwellwertes (bzw. Intervalls)
* x% oder n besten/schlechtesten Matches
* Manuelle Auswahl von Matches

#######Rohdaten
* Abmessungen der Bilder
* Farbraum der Bilder (der in OpenCV genutzte Datentyp)
* Durchschnittlicher / größter / kleinster Abstand aller / der ausgewählten Matches
* Durchschnittliche / größte / kleinste Verschiebung aller / der ausgewählten Matches

#######Projektion
* Einzeichnen von Linien / Formen
* Auswählen von zugehörigen Matches
* Die Linien / Formen werden auf das zweite Bild projiziert 

######Für Filter
* Differenzbilder _([u.A.](http://www.imagemagick.org/Usage/compare/#metrics%29))_

#####Allgemein
* Hohe Zoomstufen mit Zusatzinformationen (z.B. Pixelwerte)
* Permanente GUI mit Historie
* Möglichkeit Operation mit geänderten Parametern erneut anzuwenden
* Datenfluss von GUI zu Code sofern sinnvoll
* Optionale Ausnutzung von mehreren Bildschirmen
* Interaktive Überlagerung von Zusatzinformationen (Mouse-Over)

##Abgrenzungskriterien
Unser Projekt grenzt sich durch existentes Design gegenüber „random code“ ab. Darüber hinaus ist uns
keine andere Lösung bekannt, insbesondere keine die Open Source ist, die mit unserer vergleichbare Ziele
verfolgt.

##Produkteinsatz
Die Software soll zunächst im universitären Forschungsumfeld des beauftragenden Institutes eingesetzt
werden. Später kann der Nutzerkreis potentiell auf alle OpenCV Benutzer ausgedehnt werden, welche
OpenCV mit Qt Unterstützung kompiliert haben. (Kopie Lastenheft)

##Produktumgebung
Nach Möglichkeit alle Plattformen auf denen moderne Versionen von OpenCV und Qt5 laufen sowie ein
C++11-Compiler.

##Produktfunktion
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

##Produktdaten
Handbuch
Dokumentation
Speicherstände von Einstellungen
Snapshots aus der Debug-Oberfläche

##Systemmodell
* Das Interface wird aus öffentlichen Funktionen bestehen, die im Release-Modus nichts tun und im Debug-
	Modus, so gewünscht, die nicht-öffentlichen Debug-Methoden aufrufen
* Die nichtöffentlichen Debug-Funktionen erzeugen eine graphische Visalisierung und fügen diese dem
	Thread-lokalem Hauptfenster hinzu.

![Das Modul besteht aus drei Layern bei denen jeweils die Äußeren die
Inneren aufrufen](architektur_skizze.svg "Architekturskizze")

##Produktleistungen
* Möglichst kein Overhead im Release-mode.

##Bedienoberfläche
* Die Bedienoberfläche wird in Qt implementiert sein.
* Sie wird aus einem Hauptfenster pro Thread bestehen.
* Die verschiedenen Debug-Ansichten werden im Hauptfenster dargestellt.

##Qualitätszielbestimmungen
* keine Resource-Leaks
* kein undefiniertes Verhalten
* Threadsafety
* geringe Verzögerungen durch Berechnungen

##Testfälle und Testszenarien
###Algemeine Tests
* Speicher/Ladefunktion
* Speicherdatei von Menschen lesbar
* Beenden des Programms

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
* Test mit Videos?

##Entwicklungsumgebung
* gcc-4.8.0 oder später
* Qt 5
* C++11 oder später
* GNU/Linux
* Cmake
* opencv

##Glossar
###Allgemein:
* Debug-Visualisierung: Eine Visualisierung die den Benutzer beim Debuggen unterstützt, in dem sie relevante
	Daten zu den übergebenen Bilder anzeigt und diese damit leicht verständlich darstellt.
 
* Filter: In der Bildverarbeitung die Veränderung eines Bildbereiches mithilfe eines bestimmten Algorithmus.

* Matches: Durch OpenCV erzeugte Verknüpfungen zwischen zwei Bildbereichen bzw. Bildpixeln, 
	welche vom Benutzer an die API übergeben werden.
 
* Overhead: Zusätzlicher Speicher- oder Zeitaufwand.

* „random code“: Individueller Wegwerfcode der nur für eine einzige Probleminstanz hilfreich ist und
	sich meist durch nichtexistentes Design auszeichnet.

* Resource-Leak: Das Auftreten der Situation, dass Ressourcen irgendeiner Art (Speicher, Dateien, usw.) zwar
	alloziert werden, aber nach Verwendung nicht mehr an das System zurückgegeben werden.

* Streaming: Hier das Weiterlaufen des Datenstroms.

* Undefiniertes Verhalten: Verhalten welches zwar erwartbar, aber nicht formal spezifiziert ist
 	(vgl. C++-Compiler Features, welche nicht im Standard definiert sind).

* View: Zusammengehörige Visualisierungen eines bestimmten OpenCV-Features (oder Featureart).

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
