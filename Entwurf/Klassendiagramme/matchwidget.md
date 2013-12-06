#matchwidget (extedns Qwidget)
##member
- data& basisdaten 


- void (callbackMatchUpdate)(matchindexer&)
- matchindexer currentSelection
- matchindexer selectionInUse
- vector<tupel<string,matchindexer>> groups

- QTable groupTable

##functions
- selectCurrent(matchindexer)

- matchindexer groupUnion(matchindexer...)
- matchindexer groupIntersection(matchindexer...)
- matchindexer groupComplement(matchindexer)
- matchindexer groupRelativeComplement(matchindexer a, matchindexer b)
- matchindexer groupSymmetricDifference(matchindexer a, matchindexer b)






