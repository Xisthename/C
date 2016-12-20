Task1501c
=========
Code repository for task 1501c in DA264A "Inbyggda system & signaler" in 2015

Syfte med uppgiften:
------------
Studenten ska använda moderna utvecklingshjälpmedel, som IDE (Integrated Development Environment), för programutveckling av inbyggda system.

Studenten ska självständigt konstruera programvara för inbyggda system som läser och skriver till externa enheter.

Krav för godkänt:
--------------

Ha genomfört följande labbmoment enligt [denna handledning](Instruction/Uppgift1501cHT15.md):

1. Ladda ner labbens kodexempel från github (fork + clone)
2. Kompilera och ladda ner det existerande programmet till Due-kortet
3. Köra programmet och se testerna fallera
4. Implementerat funktioner för LCD-displayen så att testerna passeras:
    - Rensa LCD
    - Skriva ut fyra siffror på LCD
5. Implementera funktioner för A/D-omvandlaren så att testerna passeras:
    - Initialisera A/D-omvandlaren
    - Läsa värde från A/D-omvandlaren
6. Implementera funktioner för knappsatsen på LCD-shielden så testerna passeras:
    - Tolka värde från A/D-omvandlaren till en specifik knapp
7. Ta bort kommentarerna för den oändliga loopen i `main.c` och se värdet på LCD:n ändras beroende på vilken knapp som trycks in
8. Checka in kod + tester till ett centralt GIT-repo (pull request). Glöm inte att ange namn på de som medverkat till inlämningen.

Du visar upp för läraren för bedömning först när du är helt klar med alla stegen.
