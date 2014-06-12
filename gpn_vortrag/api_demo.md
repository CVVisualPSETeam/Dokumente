Code-Demo
========

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

