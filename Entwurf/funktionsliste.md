hier können alleinstehende funktionen eingetragen werden (+ was sie machen)

-point absolute2relativePoint(rectangle, point)
-point relative2absolutePoint(rectangle, point)
	
-rectangle surroundingRectangle(vec<point>, int deltaTop=0, int deltaBottom=0, int deltaLeft=0, int deltaRight=0)
	- erzeugt ein rechteck, welches die angegebenen punkte einschließt (ränder werden um delta verschoben)
	
- vec<point> getCorrespondingPoints(vec<int> index, vec<match>, vec<point>, vec<point>, bool getPointsFormTrain)
	- sucht zu den durch index angegebenen punkten die korrespondierenden punkte
	- auswahl welche gesucht sind durch get PointsFrom Train
	- evt rückgabewert: vec<tuple<point,point>>
	
- vec<point> getInclosed(vec<point>, rectangle)
	- filtert die punkte, welche in dem rechteck liegen
	- über die allgemeine filterfunktion

###Mengenoperationen	
- minmax
	- gibt es schon
	
- avg
	- gibt es evt schon
	
- vec<T> filter( vec<T> in, bool(filterfunc*)(T&)
	- filtert aus dem vektor in anhand der filterfunktion elemente raus 
	
####merging
- union(a1, a2, ...)
- complement(a, All)
- intersection(a1, a2, ...)
- relativeComplement(a1, a2)
- SymmetricDifference(a1, a2)

	