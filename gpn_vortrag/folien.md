%CVVisual\
 Ein Debug-Framework für OpenCV
%Andreas; Clara; Erich; Florian; \
 Johannes; Nikolai; Raphael
%20. Juni 2014

Gliederung
----------

- Einführung in OpenCV <!--- Clara -->
- Motivation <!--- Andi-->
- Anwenderfeatures <!--- Raphael  -->
- Gui-Demo <!--- Johannes -->
- Doku und technische Features <!--- Nikolai -->
- Entwurf  <!--- Erich -->
- API + Demo <!--- Florian -->
- Ausblick (?)

Einführung in OpenCV
====================

Überblick
---------

- Bildverarbeitung
- weite Verbreitung
- Matrizen als Grundlage
- Filter + Matches (und vieles mehr!)

Matrizen
--------

- Bild = mehrdimensionale Matrix
- 3. Dimension = Channel
//Bsp. BGR-Bild: 1. Channel blau, 2. Channel grün usw.

Filter
------

- 2D-Bilder
- Berechnung auf Umgebung jedes Pixels
- Bsp: dilate, erode, Sobel
//erode -> kleine Details weg

Matches
-------

- FeatureDetector -> Keypoints = charakteristische Punkte
- Match = Paar aus Keypoints

Motivation
==========

Debuggen von OpenCV
-------------------

Systematisches Debugging statt „Random Code“
//Hinweis auf showMatches/showKeypoints

GUI
---

Visualisierung von Matritzen, Filtereffekten und Matches

Anwenderfeatures
================

GUI-Demo
========

Dokumente und technische Features
======

Entwurf
=======

API
===

Anwender API
------------

* Triviale Benutzung auch in C++98
* Sehr klein und übersichtlich

Interne API
-----------

* Leichtes, zentralisiertes Hinzufügen von Visualisierungen, Filtern, …

Ausblick
========



