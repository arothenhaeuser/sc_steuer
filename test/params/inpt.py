af = None  #: 1, wenn die Anwendung des Faktorverfahrens gewählt wurde (nur in Steuerklasse IV)
ajahr = None  #: Auf die Vollendung des 64. Lebensjahres folgendes Kalenderjahr (erforderlich, wenn ALTER1=1)
alter1 = None  #: 1, wenn das 64. Lebensjahr vor Beginn des Kalenderjahres vollendet wurde, in dem der Lohnzahlungszeitraum endet (§ 24a EStG), sonst = 0
entsch = None  #: In VKAPA und VMT enthaltene Entschädigungen nach § 24 Nummer 1 EStG in Cent
f = None  #: eingetragener Faktor mit drei Nachkommastellen
jfreib = None  #: Jahresfreibetrag für die Ermittlung der Lohnsteuer für die sonstigen Bezüge nach Maßgabe der elektronischen Lohnsteuerabzugsmerkmale nach § 39e EStG oder der Eintragung auf der Bescheinigung für den Lohnsteuerabzug 2017 in Cent (ggf. 0)
jhinzu = None  #: Jahreshinzurechnungsbetrag für die Ermittlung der Lohnsteuer für die sonstigen Bezüge nach Maßgabe der elektronischen Lohnsteuerabzugsmerkmale nach § 39e EStG oder der Eintragung auf der Bescheinigung für den Lohnsteuerabzug 2017 in Cent (ggf. 0)
jre4 = None  #: Voraussichtlicher Jahresarbeitslohn ohne sonstige Bezüge und ohne Vergütung für mehrjährige Tätigkeit in Cent. Anmerkung: Die Eingabe dieses Feldes (ggf. 0) ist erforderlich bei Eingaben zu sonstigen Bezügen (Felder SONSTB, VMT oder VKAPA).
jre4ent = None  #: In JRE4 enthaltene Entschädigungen nach § 24 Nummer 1 EStG in Cent
jvbez = None  #: In JRE4 enthaltene Versorgungsbezüge in Cent (ggf. 0)
krv = None  #: Merker für die Vorsorgepauschale (0 BBG West, 1 BBG Ost, 2 sonstige)
kvz = None  #: Kassenindividueller Zusatzbeitragssatz bei einem gesetzlich krankenversicherten Arbeitnehmer in Prozent (bspw. 1,10 für 1,10 %) mit 2 Dezimalstellen
lzz = None  #: Lohnzahlungszeitraum: 1 = Jahr 2 = Monat 3 = Woche 4 = Tag
lzzfreib = None  #: Der als elektronisches Lohnsteuerabzugsmerkmal für den Arbeitgeber nach § 39e EStG festgestellte oder in der Bescheinigung für den Lohnsteuerabzug 2017 eingetragene Freibetrag für den Lohnzahlungszeitraum in Cent
lzzhinzu = None  #: Der als elektronisches Lohnsteuerabzugsmerkmal für den Arbeitgeber nach § 39e EStG festgestellte oder in der Bescheinigung für den Lohnsteuerabzug 2017 eingetragene Hinzurechnungsbetrag für den Lohnzahlungszeitraum in Cent
pkpv = None  #: Dem Arbeitgeber mitgeteilte Beiträge des Arbeitnehmers für eine private Basiskranken- bzw. Pflege-Pflichtversicherung im Sinne des § 10 Absatz 1 Nummer 3 EStG in Cent; der Wert ist unabhängig vom Lohnzahlungszeitraum immer als Monatsbetrag anzugeben
pkv = None  #: 0 = gesetzlich krankenversicherte Arbeitnehmer 1 = ausschließlich privat krankenversicherte Arbeitnehmer ohne Arbeitgeberzuschuss 2 = ausschließlich privat krankenversicherte Arbeitnehmer mit Arbeitgeberzuschuss
pvs = None  #: 1, wenn bei der sozialen Pflegeversicherung die Besonderheiten in Sachsen zu berücksichtigen sind bzw. zu berücksichtigen wären
pvz = None  #: 1, wenn der Arbeitnehmer den Zuschlag zur sozialen Pflegeversicherung zu zahlen hat
r = None  #: Religionsgemeinschaft des Arbeitnehmers lt. elektronischer Lohnsteuerabzugsmerkmale oder der Bescheinigung für den Lohnsteuerabzug 2017 (bei keiner Religionszugehörigkeit = 0)
re4 = None  #: Steuerpflichtiger Arbeitslohn für den Lohnzahlungszeitraum vor Berücksichtigung des Versorgungsfreibetrags und des Zuschlags zum Versorgungsfreibetrag, des Altersentlastungsbetrags und des als elektronisches Lohnsteuerabzugsmerkmal festgestellten oder in der Bescheinigung für den Lohnsteuerabzug 2017 für den Lohnzahlungszeitraum eingetragenen Freibetrags bzw. Hinzurechnungsbetrags in Cent
sonstb = None  #: Sonstige Bezüge (ohne Vergütung aus mehrjähriger Tätigkeit) einschließlich Sterbegeld bei Versorgungsbezügen sowie Kapitalauszahlungen/Abfindungen, soweit es sich nicht um Bezüge für mehrere Jahre handelt, in Cent (ggf. 0)
sonstent = None  #: In SONSTB enthaltene Entschädigungen nach § 24 Nummer 1 EStG in Cent
sterbe = None  #: Sterbegeld bei Versorgungsbezügen sowie Kapitalauszahlungen/Abfindungen, soweit es sich nicht um Bezüge für mehrere Jahre handelt (in SONSTB enthalten), in Cent
stkl = None  #: Steuerklasse (1-6)
vbez = None  #: In RE4 enthaltene Versorgungsbezüge in Cent (ggf. 0) ggf. unter Berücksichtigung einer geänderten Bemessungsgrundlage nach § 19 Absatz 2 Satz 10 und 11 EStG
vbezm = None  #: Versorgungsbezug im Januar 2005 bzw. für den ersten vollen Monat, wenn der Versorgungsbezug erstmalig nach Januar 2005 gewährt wurde, in Cent
vbezs = None  #: Voraussichtliche Sonderzahlungen von Versorgungsbezügen im Kalenderjahr des Versorgungsbeginns bei Versorgungsempfängern ohne Sterbegeld, Kapitalauszahlungen/Abfindungen in Cent
vbs = None  #: In SONSTB enthaltene Versorgungsbezüge einschließlich Sterbegeld in Cent (ggf. 0)
vjahr = None  #: Jahr, in dem der Versorgungsbezug erstmalig gewährt wurde; werden mehrere Versorgungsbezüge gezahlt, wird aus Vereinfachungsgründen für die Berechnung das Jahr des ältesten erstmaligen Bezugs herangezogen
vkapa = None  #: Entschädigungen / Kapitalauszahlungen / Abfindungen / Nachzahlungen bei Versorgungsbezügen für mehrere Jahre in Cent (ggf. 0)
vmt = None  #: Entschädigungen und Vergütung für mehrjährige Tätigkeit ohne Kapitalauszahlungen und ohne Abfindungen bei Versorgungsbezügen in Cent (ggf. 0)
zkf = None  #: Zahl der Freibeträge für Kinder (eine Dezimalstelle, nur bei Steuerklassen I, II, III und IV)
zmvb = None  #: Zahl der Monate, für die im Kalenderjahr Versorgungsbezüge gezahlt werden [nur erforderlich bei Jahresberechnung (LZZ = 1)]