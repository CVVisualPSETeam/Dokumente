hier k�nnen alleinstehende funktionen eingetragen werden (+ was sie machen)

-point absolute2relativePoint(rectangle, point)
-point relative2absolutePoint(rectangle, point)
	-wandelt einen absoluten/ relativen punkt eines bildes/bildausschnittes in das entsprechende gegenst�ck um
	- eine version f�r mehrere punkte 
	
-rectangle surroundingRectangle(vec<point>, int deltaTop=0, int deltaBottom=0, int deltaLeft=0, int deltaRight=0)
	- erzeugt ein rechteck, welches die angegebenen punkte einschlie�t (r�nder werden um delta verschoben)
	
- vec<point> getCorrespondingPoints(vec<int> index, vec<match>, vec<point>, vec<point>, bool getPointsFormTrain)
	- sucht zu den durch index angegebenen punkten die korrespondierenden punkte
	- auswahl welche gesucht sind durch get PointsFrom Train
	- evt r�ckgabewert: vec<tuple<point,point>>
	
- vec<T> filter( vec<T> in, bool(filterfunc*)(T&)
	- filtert aus dem vektor in anhand der filterfunktion elemente raus 

- minmax
	- gibt es schon
	
- avg
	- gibt es evt schon

	