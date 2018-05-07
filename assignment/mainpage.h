/** @file mainpage.h
* @brief Description of lottery.
*/ 
/** @mainpage lottery -- Reading and analyzing lottery tips
*
* @author Peter Bauer
*
* @section intro Einf&uuml;hrung
* Es ist eine Bibliothek zur Analyse von Lottotipps zu implementieren. Die Lottotipps liegen
* in Form einer csv-Datei vor. Der Name der csv-Datei wird der Bibliothek bei der Initialisierung
* angegeben. Die Bibliothek l&auml;sst auf einzelne Tipps mittels eines Index (von 0 beginnend)
* zugreifen (get_tip()).
*
* Weiters kann der Bibiliothek das Ergebnis einer Ziehung mitgeteilt werden (set_drawing()). Nun
* kann das Ergebnis eines Tipps (wieviele richtige Zahlen getippt wurden) ermittelt werden
* (get_tip_result()). Weiters kann noch das Gesamtergebnis einer Ziehung (wieviele 0er, 1er, ...
* 6er) ermittelt werden (get_right_tips_count()).
*
* Da die csv-Datei im Normalfall eine sehr hohe Anzahl von Tipps beinhalten wird, ist es nicht
* zul&auml;ssig, alle Tipps bei der Initialisierung in den Hauptspeicher zu laden.
*
* @section functions Die Funktionen der Library
* - init_lottery() initialisiert die lib mit dem csv-File.
*
* - get_tip() liefert die Zahlen (digits) eines einzelnen Tipps. Auf die Tipps wird &uuml;ber einen
* Index (von 0 beginnend) zugegriffen.
*
* - set_drawing() setzt das Ergebnis einer Ziehung. Die Zahlen m&uuml;ssen nicht sortiert sein.
*
* - get_tip_result() gibt das Ergebnis eines Tipps aufgrund der mittels set_drawing() angegebenen
* Ziehung zur&uuml;ck. Auf die Tipps wird wieder mittels Index zugegriffen.
*
* - get_right_tipps_count() gibt die Anzahl der einzelnen Ergebnisse einer Lotterieziehung
* zur&uuml;ck. Die gew&uuml;nschte Zahl wird als Argument mitgegeben. Beispielsweise wird, wenn
* die Anzahl der 5er ermittelt werden soll, das Argument right_digits_count auf 5 gesetzt.
*
*/