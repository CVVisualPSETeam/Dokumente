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

* cvv::impl::FilterCall::input() umbenannt nach original()
* cvv::impl::FilterCall::output() umbenannt nach result()

Nicht implementierte Klassen
-----------------------------
* `Optinal`: wurde nicht verwendet
* `GroupOperatorWidget`: Die Funktionalität erschien eher überflüssig.

Zusätzliche Klassen
--------------------
* `ObeserverPtr`: Effektiv ein Pointer der durch seinen Typ signalisiert, dass er nicht
  ownend ist. Wurde nötig, da an einigen Stellen spät initialisierte Referenzen benötigt wurden.
* `RegisterHelper`: Da das Registieren von Fabrikmethoden und die Auswahl dieser durch eine ComboBox
  mehrmals benötigt wurde.
* `Signal`, `Slot` und ihre Varianten: Da Qt den einsatz von Templates und Signal oder Slots in einer
  Klasse verbietet, wurden diese Klassen als Wrapper für Signale und Slots verwendet. 
  
Sonstige Änderungen
===================

* Ubuntu als primäre Zielplattform konnte aufgrund von Bugs in der dort verwendeten Qt-version nicht
  uneingeschränkt umgesetzt werden. Es traten zwei sorten von Problemen auf, von denen wir hoffen,
  dass sie in zukünfigen Versionen gefixt werden:
	* Abstürze bei der Verwendung unter unity. Empfohlener Workaround: andere Desktop-Umgebung.
	* Leere „Geisterfenster“. Empfohlener Workaround: Ignorieren.
