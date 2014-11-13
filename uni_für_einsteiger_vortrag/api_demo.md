% API-Demo
% Florian

Anwender API
============

* Funktionalität:
	* `debugDMatch(img1, keys1, img2, keys2, matches, ...)`
	* `debugFilter(orig, result, ...)`
	* `showImage(img, ...)`
* Meta/Boilerplate:
	* `finalShow()`
	* `FinalShowCaller` (RAII)
	* `CVVISUAL_LOCATION`
	* `setDebugFlag(bool)`
* Reinen Anwendern reicht das für alles!

Interne API
===========

Allgemein
---------

* Const-korrekt
* keine bekannten Leaks (Qt leakt immer -> Valgrind nutzlos)
* Relativ oft: `std::unique_ptr` statt besitzenden, blanken Pointern

cvv::extend
-----------

* `addCallType`: registriert eine Funktion die einen Tab zurück geben muss
* `addFilterView` und `addMatchView`: neue Visualisierungen für Filter und Matches
* `registerFilter`: Neue Filter für das `FilterSelectorWidget`

cvv::util
---------

* `Reference`: Referenzen die ändern können, worauf sie zeigen; nicht besitzend
* `ObserverPtr`: Wie `Reference`, kann aber null sein
* `make_unique` und `makeRef`
* häufig benötigte Includes in `util.hpp`

Flexible Liniendicken
---------------------

* „Problem“ zeigen
* Neuen Code zeigen
* Einfügen und in init.cpp registrieren
* „Lösung“ zeigen
