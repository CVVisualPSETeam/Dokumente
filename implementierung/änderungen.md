Änderungen gegenüber dem Entwurf
================================

API und Funktionalität
----------------------

* Keine Thread-safety, da Qt keine GUI außerhalb eines main-threads mag
* `finalShow()` nötig, da geleakte QApplications verboten sind
* `FinalShowCaller` hinzugefügt um `finalShow` via RAII aufrufen zu können
* `debugDilate/Erode/…` als `debugFilter()` vereinheitlicht, da Funktionalität identisch
* Möglichkeit ein einzelnes Bild anzuzeigen hinzugefügt (`showImage()`)

Interna
-------
* deutlich erhöhter Gebrauch blanker Pointer, da Qt dies effektiv erzwingt.

Interne Details (Auszug)
------------------------

* `cvv::impl::FilterCall::input()` umbenannt nach `original()`.
* `cvv::impl::FilterCall::output()` umbenannt nach `result()`.
* `cvv::gui::MatchCallTab::addMatchViewToMap()` wurde durch das einfacher zu verwendende `registerMatchView() `ersetzt; `registerElement()`, das `MatchCallTab` von `RegisterHelper` erbt, stellt die originale Funktionalität noch zur Verfügung.
* `cvv::gui::FilterCallTab::addFilterViewToMap()` ebenso (ersetzt durch `registerFilterView()`).
* `cvv::view::PointTranslationView` umbenannt nach "cvv::view::TranslationMatchView"
* `KeyPoint-Match` Es gibt eine sehr stark parrallele Entwicklung, da Qt keine Templates akzeptiert

Nicht implementierte Klassen
-----------------------------
* `Optional`: wurde nicht verwendet
* `GroupOperatorWidget`: Die Funktionalität erschien eher überflüssig.
* `HelpButton`: Innerhalb von `MultiViewCallTab`durch einen normalen `QPushButton` realisiert.
* `ProjectionView` Funktionalität wurde nicht programmiert

Zusätzliche Klassen
--------------------
* `ObeserverPtr`: Effektiv ein Pointer der durch seinen Typ signalisiert, dass er nicht
  ownend ist. Wurde nötig, da an einigen Stellen spät initialisierte Referenzen benötigt wurden.
* `RegisterHelper`: Da das Registieren von Fabrikmethoden und die Auswahl dieser durch eine ComboBox
  mehrmals benötigt wurde.
* `Signal`, `Slot` und ihre Varianten: Da Qt den Einsatz von Templates und Signal oder Slots in einer
  Klasse verbietet, wurden diese Klassen als Wrapper für Signale und Slots verwendet. 
* `ImageView`: Visualisierung eines einzelnen Bildes; im Zusammenhang mit `showImage()`(s. oben) verwendet.
* `ImagecallTab`: Tab für den `ImageView`.
* `MutliViewCallTab`: Oberklasse über Tabs, die mehr als einen View unterstützen. Wurde hinzugefügt, um die gemeinsame Funktionalität dieser an einer Stelle zu bündeln und durch Templates die Erweiterbarkeit zu verbessern. Erbt von `CallTab` und `RegisterHelper`(und verwendet davon die `QComboBox` zur Auswahl der Views). Bietet zusätzlich über den entwurf hinausgehend einen `Set as default`-Button und eine Historie, in der die Zustände der ausgewechselten Views erhalten bleiben, da sich beides während der Implementierungs- und Testphase als sinnvoll herausgestellt hat.
* `ZoomabelOptPanel`: ergab sich bei der Schaffung der Konvertierungsfunktion cv::Mat=>QPixmap.
* `SyncZoomWidget`: Die Syncronisierung des Zoomes wurde im Entwurf nicht geschaffen da die benötigten Details nicht klar waren. 
* `DepthMatchView`: Bei der Implementierung der anderen views ergab sich dieser View durch geringfügige änderungen.
* `CVVMatchPoint`: Unter Klasse von CVVMatch für den DepthMatchView.
* `MatchSettings/KeyPointSettings`: Im Entwurf war noch nicht klar wie diese Funktionalität aussehen würde, und wurde somit erst in der implementierung geschaffen.
* `MatchSelection/KeyPointSelection`: Die QGraphicScene hatte ein anderes Verhalten als beim Entwurf angenohmen. Die Selection funktioniert zurzeit nur mit den Datentypen von OpenCV und nicht mit den intern benutzten Typen CVVMatch/CVVKeyPoint, dies kann "einfach" geändert werden da CVVMatch/CVKeyPoint von cv::DMatch/cv::KeyPoint erben, allerdings exitstieren teilweise Matches doppelt(z.B. im Translationview).
* `MatchManagemnt/KeyPointManagemnt`: ergab sich aus den beiden oberen Klassen.
  
Sonstige Änderungen
===================

* Ubuntu als primäre Zielplattform konnte aufgrund von Bugs in der dort verwendeten Qt-version nicht
  uneingeschränkt umgesetzt werden. Es traten zwei sorten von Problemen auf, von denen wir hoffen,
  dass sie in zukünfigen Versionen gefixt werden:
	* Fehler (Programm hängt fest) bei der Verwendung unter unity. Empfohlener Workaround: andere Desktop-Umgebung.
	* Leere „Geisterfenster“. Empfohlener Workaround: Ignorieren.
