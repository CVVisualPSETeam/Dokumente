
#Testszenario: Hauptfenster Filters 1
aufgerufen wird in dieser Reihenfolge `debugFilter` für:

	dilate
	erode
	sobel
	morphologyEx
sowie zuletzt

	finalShow();

#####Grundlegendes:
* __Programm startet__
* __Fenster__ öffnet sich, __Overview table__ sichtbar
* Doppelklick dilate call: __CallTab__ öffnet sich
	* __Help__ klicken: Hilfe öffnet sich
	* _Accordion-Test_
	* __Wechsle__ auf DualFilterView: Öffnet sich
	* _Accordion-Test_
	* Öffne Accordion-Collapsable
	* __Verlasse tab und betritt es wieder__: Collapsable noch offen
	* __Resume (vom dilate tab)__: Overview mit zwei Calls erscheint (dilate, erode)
#####Kontextmenüs und neue Fenster:
* Linksklick erode -> __Open in main window__: Öffnet sich
	* Öffne Accordion-Collapsable
	* __Öffne ComboBox, aber wechsle nicht__: Collapsable bleibt offen
* Main Window - Overview - erode __call -> Remove__ erode call: Verschwindet, Fenster?
* __Resume (vom Overview)__: dilate, sobel
* Linksklick sobel __call-> Open in new Window__: Öffnet sich.
* __Schließe sobel-window__: Schließt sich, nicht aber Hauptfenster
* Linksklick dilate __tab-> open in new window__: Öffnet sich.  
 __Funktionalität gleich wie im tab__:
	* Help klicken: Hilfe öffnet sich
	* Wechsle auf DualfilterView: Öffnet sich
	* Wechsle zurück auf DefaultFilterView: Öffnet sich
	* __Resume (vom dilate window)__: dilate, sobel, morphologyEx
#####Erweiterte Funktionalität:
* __Zoom__(Overview): rein- und rauszoomen funktioniert.
* _STFL-Test_
* Doppelklick morphologyEx call: Öffnet sich
* __Schließe tab__: Schließt sich.
* Öffne tab wieder. Versuche zusätzliches, __zweites tab__ von morphologyEx zu öffnen.
* __Doppelter Rechtsklick__ auf tab und call von morphologyEx,  __doppelter Linksklick auf tab__.
* Linksklick morphologyEx __tab -> Remove__: Funktioniert ordnungsgemäß.
* Versuche, __zweites window__ von dilate zu öffnen.
#####`Exit program`-button
* Resume (beliebig): __Button ändert sich__ in beiden Fenstern auf `Exit program`
* Öffne sobel __in neuem Fenster: `Exit program` button__ darin.
* Beliebiger `Exit program`: __Schließt alle Fenster__.
* __Programm__ ordnungsgemäß __beendet__.
#####Weiteres
* Selbes Programm unmttelbar danach __nocheinmal ausführen__: Funktioniert ordnungsgemäß; keine "Rückstände" vom letzten Mal.