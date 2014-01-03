#Klassenbeschreibungen f�r den Bereich CallTabs  
##CallTab  
CVVisual::management::CallTab  
Das Innere eines Tab oder eines Fensters, wenn das Tab in ein solches verschoben wurde.  
Die davon abgeleiteten Klassen enthalten je einen View. Ihre Hauptaufgabe ist es, Funktionalit�t zum
Wechseln der Views zur Verf�gung zu stellen. Zudem enthalten sie je einen Button, mithilfe dessen der Benutzer
sich die f�r diesen Bereich relevanten Informationen aus der Hilfe anzeigen zu lassen.  
Attribute:  
QString name: Der Name des Tabs, der etwa in der Tabauswahlleiste angezeigt wird.  
Methoden: Die zugeh�rigen getter und setter.  
  
##MatchCallTab  
CVVisual::management::MatchCallTab  
Eine von CallTab abgeleitete Klasse.  
Attribute:  
threadlocal map<QString, MatchView> matchViewMap: Speichert m�gliche Match-Views und erm�glicht den Zugriff darauf �ber eine QString-ID.  
ViewController viewController: MatchCallTab beuntzt einige Methoden des dar�ber stehenden ViewControllers, um etwa auf die Settings oder die Hilfe zuzugreifen.  
MatchView matchView: Das augenblicklich ausgew�hlte View, welches angezeigt wird, wenn das Tab angezeigt wird.  
MatchCall matchCall: Der Call, der die Informationen enth�lt, die im View dargestellt werden.  
QComboBox viewSelection: Erlaubt die Auswahl eines der Views aus matchViewMap f�r die Anzeige. Dabei kennt die ComboBox nur die IDs der Views, der Zugriff efolgt vermittelst des currentIndexChanged-Signals �ber die matchViewMap.
CVVisual::HelpButton helpButton: �ffnet bei Mausklick die relevante Hilfeseite. Die page (s. HelpButton) ist dabei wiederum der Name, dh. die ID des gerade ausgew�hlten MatchView.  
Methoden:  
size_t getId(): GIbt die ID des zugeh�rigen MatchCalls zur�ck, die gleichzeitig als ID des Tabs fungiert.  
threadlocal addMatchViewToMap(MatchView matchView, QString id): F�gt der matchViewMap matchView mit id hinzu.  
Konstruktoren:  
MatchCallTab(QString name, MatchCall matchCall, ViewController viewController): Benutzt den Standard-View aus den Settings.  
MatchCallTab(QString name, MatchCall matchCall, ViewController viewController, MatchView matchView): Benutzt matchView.  
Slots:  
currentIndexChanged: Mit dem gleichnamigen Signal von comboBox verbunden. Wechselt den View, um der Auswahl zu entsprechen.  
helpButtonClicked: Mit dem clicked-Signal verbunden, das HelpButton von QPushButton erbt.  
  
##FilterCallTab  
CVVisual::management::FilterCallTab  
Entspricht von der Funktionalit�t weitestgehend MatchCallTab bis darauf, dass FilterViews und FilterCalls
anstelle ihrer Match-Versionen verwendet werden.  
  
##MatchView  
CVVisual::MatchView::MatchView  
Ein Inteface �ber die Views f�r Matches.  
Erbt von QWidget.  
Signals:  
updateRightFooter(QString newText): Wird an das CallWindow gesendet, welches dann die rechte Seite der Fu�leiste aktualisiert.  
updateLeftFooter(QString newText): Aktualisiert analog die linke Seite.  
  
##FilterView  
CVVisual::FilterView::FilterView  
Ein zu MatchView analoges Interface �ber FilterViews.  
  
##HelpButton  
CVVisual::HelpButton  
Erbt von QPushButton.  
Ein Button, der bei Mausklick eine Hilfeseite �ffnet.  
Attribute:  
QString page: Die Seite bzw. der Themenbereich, der von diesem Button bei Mausklick in der Hilfe ge�ffnet wird.  
Methoden:  
setPage(QString newPage), QString getPage().
  
