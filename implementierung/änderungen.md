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

* `Optinal` entfernt: wurde nicht verwendet
* deutlich erhöhter Gebrauch blanker Pointer, da Qt dies effektiv erzwingt.
* Zusätzliche Klasse `ObeserverPtr`, effektiv ein Pointer der durch seinen Typ signalisiert, dass er nicht
  ownend ist. Wurde nötig, da an einigen Stellen spät initialisierte Referenzen benötigt wurden.

Interne Details (Auszug)
------------------------

* cvv::impl::FilterCall::input() umbenannt nach original()
* cvv::impl::FilterCall::output() umbenannt nach result()

Sonstige Änderungen
===================

* Ubuntu als primäre Zielplattform konnte aufgrund von Bugs in der dort verwendeten Qt-version nicht
  uneingeschränkt umgesetzt werden. Es traten zwei sorten von Problemen auf, von denen wir hoffen,
  dass sie in zukünfigen Versionen gefixt werden:
	* Abstürze bei der Verwendung unter unity. Empfohlener Workaround: andere Desktop-Umgebung.
	* Leere „Geisterfenster“. Empfohlener Workaround: Ignorieren.
