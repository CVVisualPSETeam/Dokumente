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
Nicht implementierte Klassen
-----------------------------
* `Optional`: wurde nicht verwendet
* `GroupOperatorWidget`: Die Funktionalität erschien eher überflüssig.
* `HelpButton`: Innerhalb von `MultiViewCallTab`durch einen normalen `QPushButton` realisiert.

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
* `MutliViewCallTab`: Oberklasse über Tabs, die mehr als einen View unterstützen. Wurde hinzugefügt, um die gemeinsame Funktionalität dieser an einer Stelle zu bündeln und durch die Templates die erweiterbarkeit zu verbessern. Erbt von `CallTab` und `RegisterHelper`(und verwendet davon die `QComboBox` zur Auswahl der Views). Bietet zusätzlich über den entwurf hinausgehend einen `Set as default`-Button und eine Historie, in der die Zustände der ausgewechselten Views erhalten bleiben, da sich beides während der Implementierungs- und Testphase als sinnvoll herausgestellt hat.
  
Sonstige Änderungen
===================

* Ubuntu als primäre Zielplattform konnte aufgrund von Bugs in der dort verwendeten Qt-version nicht
  uneingeschränkt umgesetzt werden. Es traten zwei sorten von Problemen auf, von denen wir hoffen,
  dass sie in zukünfigen Versionen gefixt werden:
	* Fehler (Programm hängt fest) bei der Verwendung unter unity. Empfohlener Workaround: andere Desktop-Umgebung.
	* Leere „Geisterfenster“. Empfohlener Workaround: Ignorieren.
