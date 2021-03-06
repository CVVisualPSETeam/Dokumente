﻿Änderungen gegenüber dem Entwurf
================================

API und Funktionalität
----------------------

* Keine Thread-safety, da Qt keine GUI außerhalb eines main-threads mag
* `finalShow()` nötig, da geleakte QApplications verboten sind
* `FinalShowCaller` hinzugefügt um `finalShow` via RAII aufrufen zu können
* `debugDilate/Erode/…` als `debugFilter()` vereinheitlicht, da Funktionalität
  identisch
* Möglichkeit ein einzelnes Bild anzuzeigen hinzugefügt (`showImage()`)

Interna
-------
* deutlich erhöhter Gebrauch blanker Pointer, da Qt dies effektiv erzwingt.
* inkonsistentere Verwendung der Qt Containerklassen, da diese öfters Probleme
  machten und deswegen durch Standardkontainer ersetzt wurden

Interne Details (Auszug)
------------------------
* `FilterCall::input()` umbenannt nach `original()`.
* `FilterCall::output()` umbenannt nach `result()`.
* `MatchCallTab::addMatchViewToMap()` wurde durch das einfacher zu
  verwendende `registerMatchView() `ersetzt; `registerElement()`,
  das `MatchCallTab` von `RegisterHelper` erbt, stellt die originale
  Funktionalität noch zur Verfügung.
* `FilterCallTab::addFilterViewToMap()` ebenso (ersetzt durch
  `registerFilterView()`).
* `PointTranslationView` umbenannt nach
  `TranslationMatchView`
* `KeyPoint-Match` Es gibt eine sehr stark parrallele Entwicklung,
  da Qt keine Templates akzeptiert
* `STFLEngine`: Es sind diverse Methoden hinzugekommen, um die
  Benutzung zu vereinfachen (der Konstruktor war mit den vielen Argumenten
  einfachen nicht verwendbar), außerdem wurde die QList Klasse an manchen
  Stellen durch die std::vector Klasse ersetzt.
* `IntervalSelectorWidget` umbenannt nach `IntervallSelector`
  Interface komplett geändert: bietet nun eine Funktion `select` an, die
  eine angegebene Menge filtert.
* `RelativePortionSelectorWidget` umbenannt nach `PortionSelector`
  Interface komplett geändert: bietet nun eine Funktion `select` an, die
  eine angegebene Menge filtert.
* `AutoFilter`: Interface wurde erweitert, um die Benutzung
  zu vereinfachen.
* `FilterSelectorWidget`: Interface wurde erweitert, um die
  Benutzung zu vereinfachen.
* `ZoomableImage`: Interface wurde erweitert, um die Benutzung
  zu vereinfachen.
* Jegliche `Collumn`-Klassen wurden zu `Row`-Klassen, da dies deren
  Bedeutung besser abbildet (einhergehend wurden auch sämtliche Methodenname,
  etc. geändert)
* `RawviewTableRow`: Unterscheidung zwischen simplem KeyPoint und einem Match in
  Kombination mit zwei KeyPoints, `rowsToText(...)` zur textuellen Ausgabe
  hinzugefügt.
* `ViewController`: Einbau verschiedener Betriebsmodi.

Nicht implementierte Klassen
-----------------------------
* `Optional`: wurde nicht verwendet
* `GroupOperatorWidget`: Die Funktionalität erschien eher überflüssig.
* `HelpButton`: Innerhalb von `MultiViewCallTab` durch einen normalen
  `QPushButton` realisiert.
* `ProjectionView` Funktionalität wurde nicht programmiert
* `SelectableHistogram`: wurde durch die änderung von `IntervalSelectorWidget`
  nicht mehr benötigt.

Zusätzliche Klassen
--------------------
* `ObserverPtr`: Effektiv ein Pointer der durch seinen Typ signalisiert,
  dass er nicht ownend ist. Wurde nötig, da an einigen Stellen spät
  initialisierte Referenzen benötigt wurden.
* `RegisterHelper`: Da das Registieren von Fabrikmethoden und die Auswahl
  dieser durch eine ComboBox mehrmals benötigt wurde.
* `Signal`, `Slot` und ihre Varianten: Da Qt den Einsatz von Templates und
  Signal oder Slots in einer
  Klasse verbietet, wurden diese Klassen als Wrapper für Signale und Slots
  verwendet.
* `ImageView`: Visualisierung eines einzelnen Bildes; im Zusammenhang mit
  `showImage()`(s. oben) verwendet.
* `ImagecallTab`: Tab für den `ImageView`.
* `MultiViewCallTab`: Oberklasse über Tabs, die mehr als einen View
  unterstützen. Wurde hinzugefügt, um die gemeinsame Funktionalität dieser an
  einer Stelle zu bündeln und durch Templates die Erweiterbarkeit zu verbessern.
  Erbt von `CallTab` und `RegisterHelper`(und verwendet davon die `QComboBox`
  zur Auswahl der Views). Bietet zusätzlich über den Entwurf hinausgehend einen
  `Set as default`-Button und eine Historie, in der die Zustände der
  ausgewechselten Views erhalten bleiben, da sich beides während der
  Implementierungs- und Testphase als sinnvoll herausgestellt hat.
* `ZoomabelOptPanel`: ergab sich bei der Schaffung der Konvertierungsfunktion
  `cv::Mat` __=>__ `QPixmap`.
* `SyncZoomWidget`: Die Synchronisierung des Zoomes wurde im Entwurf nicht
   geschaffen da die benötigten Details noch nicht klar waren.
* `DepthMatchView`: Bei der Implementierung der anderen Views ergab sich dieser
   View durch geringfügige Änderungen.
* `CVVMatchPoint`: Unter Klasse von CVVMatch für den DepthMatchView.
* `MatchSettings/KeyPointSettings`: Im Entwurf war noch nicht klar wie diese
  Funktionalität aussehen würde, und wurde somit erst in der Implementierung
  geschaffen.
* Unterklassen von `MatchSettings/KeyPointSettings`:
	* `FalseColorMatchPen/-KeyPoint`: Setzt die Farbe des Matches/KeyPoints
	  nach einer Falschfarbenskalar in colorutil.hpp.
	* `SingleColorMatchPen/-KeyPoint`: Gibt den Benutzer die Möglichkeit
	  die Farbe der Matches/KeyPoints zu wählen.
	* `Match-/KeyPointsShowSetting`:Wurde durch umstrukturierung auskommentiert
	  könnte später bei Änderung der Selection benutzt werden.
	* `Match-/KeyPointsSettingSelector`:Gibt den benutzer die Auswahlmöglichkeit
	  verschiedene Match-/KeyPointSettings zu benutzen, verhält sich nach außen 
	  als wäre es das ausgewählte Setting
	* `Match-/KeyPointManagement`: Ist durch die Settings Schnitstelle 
	  mit den Matches/KeyPoints verbunden und wird weiter unten erklärt.
* `MatchSelection/KeyPointSelection`: Die QGraphicScene hatte ein anderes
  Verhalten als beim Entwurf angenohmen. Die Selection funktioniert zurzeit nur
  mit den Datentypen von OpenCV und nicht mit den intern benutzten Typen
  `CVVMatch`/`CVVKeyPoint`, dies kann "einfach" geändert werden da
  CVVMatch/CVKeyPoint von `cv::DMatch`/`cv::KeyPoint` erben, allerdings
  existieren teilweise Matches/KeyPoints doppelt (z.B. im Translationview).
* Unterklassen von `MatchSelection/KeyPointSelection`:
	* `Match-/KeyPointPortionSelector`:Wrapper für PortionSelector welcher im 
	  Match-/KeyPointSelectionSelector benutzt wird.
	* `Match-/KeyPointIntervallSelector`: Wrapper für IntervallSelector welcher im 
	  Match-/KeyPointSelectionSelector benutzt wird.
	* `Match-/KeyPointSelectionSelector`: Gibt dem Benutzer die Möglichkeit
	  verschiedene Match-/KeyPointSelection zu benutzen, verhält sich wie das 
	  ausgewählte Match-/KeyPointSelection.
* `MatchManagement`/`KeyPointManagement`: ergab sich aus den beiden oberen
  Klassen.
* `RawviewWindow`: Vereinfacht die Benutzung des Rawviews als Matchselector.
* `RawviewGroupSubtable`: Kam hinzu, da der Rawview analog zum OverviewPanel
  aufgebaut wurde. Sie ermöglicht es, dass Elemente im Rawview auch gruppiert
  dargestellt werden können.
* `STFLQueryWidgetCompleter`, `STFLQueryWidgetLineEdit`: Ein LineEdit mit
  eingebauter Vorschlagsfunktion war wieder erwarten nicht in Qt selbst
  implementiert.
* `TabWidget`: Eine QTabWidget die den Zugriff auf die geschützte Methode
  `tabBar()` erlaubt.
* Unterklassen von `FilterFunctionWidget`:
	* `ChangedPixelsWidget`: Filter der eine Matrix erzeugt in der alle
	  veränderten Pixel schwarz und alle unveränderten weiß sind.
	* `ChannelReorderFilter`: Filter der es erlaubt die Kanäle einer
	  Matrix neu anzuordnen.
	* `DiffFilterFunction`: Filter der verschiedene Differenzbilder berechnet.
	* `GrayFilterWidget`: Ein Graufilter.
	* `OverlayFilterWidget`: Filter der ein Überlagerungsbild erstellt.
	* `SobelFilterWidget`: Der OpenCV Soebelfilter.

Sonstige Änderungen
===================

* Ubuntu als primäre Zielplattform konnte aufgrund von Bugs in der dort
  verwendeten Qt-version nicht uneingeschränkt umgesetzt werden. Es traten zwei
  Sorten von Problemen auf, von denen wir hoffen, dass sie in zukünfigen
  Versionen gefixt werden:
	* Fehler (Programm hängt fest) bei der Verwendung unter unity.
	  Empfohlener Workaround: andere Desktop-Umgebung, da zumindest XFCE
	  keine Probleme macht.
	* Leere „Geisterfenster“. Empfohlener Workaround: Ignorieren (und auf
	  Ubuntu 14.04 hoffen).
* Die Dokumentation wird nicht mit sphinx erzeugt, sondern mit jekyll und
  Shell-Skripten.
