Uppgift 1501f
======
Programmering med tid i labbsalen  
_Ulrik Eklund, 2015-11-11_

Syfte med uppgiften:
------
Den här laborationen handlar om man

- konstruera programvara i C som implementerar en tillståndsmaskin.
- hur man använder realtidsoperativsystemet [FreeRTOS](http://www.freertos.org) med Arduino Due.

Teori om realtidsoperativsystem
------
### Hur man använder tasks (processer) i FreeRTOS

![Bilden är tagen från FreeRTOS hemsida: http://www.freertos.org/tskstate.gif](taskStates.png)
Varje periodisk task definieras som en egen funktion.
void vTaskCode(void *pvParameters)
        /* vänta en förutbestämd tid */
```
int main(void)

------
Ha genomfört följande labbmoment enligt denna handledning:

1. Laddat ner kodexempel på implementationer av FSM från github
2. Implementera en tillståndsmaskin som passerar alla tester i test-projektet
3. Skrivit kod och tester för initialisering och styrning de digitala I/O som behövs för att styra kodlåset.
4. Modifiera det befintliga projektet i samma kodrepo. Detta projekt skall innehålla två tasks:
    - En task som innehåller den testade tillståndsmasken och I/O-koden. Denna ska ha högst prioritet
    - En task som blinkar lysdioden
5. Koppla upp kodlåset mot lämpliga digitala I/O på Due-kortet
6. Köra programmet och spela in en video av fungerande lås, antingen som länk till ett eget youtube klipp eller som två videofiler (obs max 30 sec per video), uppladdad till It´s learning
7. Checka in kod + tester till ett centralt GIT-repo

Du visar upp för läraren för bedömning först när du är helt klar med steg 6.

Krav innan uppgiften
------
Om annan dator än labsalens dator används (t.ex. egen dator) måste följande program finnas installerat på den datorn:

- Atmel Studio 6.1 eller senare (finns endast för Windows). Obs att 7.0 inte har något terminalfösnter för att skriva ut testresultat.
- Github client eller TortoiseGit, helst med en kommandotolk (för andra datorer än Windows finns andra Git-klienter)
- Bossac.exe och tillhörande bat-fil
- Rekommenderas också att ha ett USB-minne för att lätt kunna flytta sitt lokala repo

Själva uppgiften
------
När du är färdig har du ett program som kör två olika processer parallellt, den första är mer komplicerad som läser knappar och styr kodlåset och den andra är enkel och bara blinkar lysdioden.  
Tillståndsmaskinen för den första processen tas fram i ett separat projekt med egna testfall. När den passerar testfallen infogas den in det andra projektet.

### Skapa ett personligt repo för denna programmeringsuppgift med hjälp av Git.  

Det finns ett centralt repo för kursen på github med webbadressen: 
<https://github.com/MalmoUniversity-DA264A/Task1501f> 

Du gör en fork från detta repot, och klonar det till din utvecklingsdator på samma sätt som i tidigare labbar. Sen jobbar  du vidare i ditt eget repo och gör en pull request mot kursrepot när du är klar.

### Programmering: Tillståndsmaskin för kodlåset

På föreläsningen gick vi igenom tre olika sätt att implementera en tillståndsmaskin. Du kan se exempel i en katalog i labbens repo.

1. Med en tabell som definierar tillstånd och övergångar
2. Med en nästlad case/switch och en stor if-sats i main.c
3. Med tillståndsmaskinen som en dold datatyp och där varje event definieras som en egen funktion

I alla tre exemplen exekveras tillståndsmaskinen i en oändlig loop i `main()`. Det kan vara vettigt att ha en fördröjning i den loopen så att tillståndsmaskinen exekverar med en viss förbestämd periodicitet (typ var 100 ms). Det enklaste är att lägga in en fördröjning i huvudloopen, det finns redan funktioner för delay-timern i `DelayFunctions.c` och `DelayFunctions.h` från tidigare labbar.  
Observera att man måste använda ASF Wizard under ASF menyn för att inkludera Atmels bibliotek för timern (TC) för att dessa ska fungera.

Det är samma tillståndsmaskin som i den förra Matlab-uppgiften. Diagrammet nedan visar hur den ser ut för en viss sekvens av knapptryckningar. _Vilken är sekvensen?_

![Figur 4: Tillståndsmaskin för kodlås](lockFSM.png)

I den föregående matlab-uppgiften identifierade du mängden X av tillstånd och mängden E av händelser. Dessa två mängder har du stor nytta av i denna uppgift, både för 

1. att välja vilket av de tre sätten du tänker använde, och när du sen ska 
2. fylla i tabellen, skriva case/switch-satserna eller definiera event-funktionerna.

Projektet `TestFSM` har som syfte att testa tillståndsmaskinen för kodlåset. _Programmeringen av den går att göra utan att bygga någon labbsetup förutom Due-kortet och går alltså att förbereda innan du kommer till labsalen._

Precis som i den förra uppgiften kan du definiera den rätta koden som en valfri sekvens med fyra knapptryckningar som får det elektroniska låset att öppnas, t.ex genom en fördefinerad array med fyra element. Men testerna i `TestFSM` testar bara en enda sekvens, den som syns i bilden. Att kunna ändra kod gör ju att villkoren för att gå mellan tillstånd ser olika ut beroende på vilken kod du väljer. _Påverkar det vilken metod du vill använda för att implementera tillståndsmaskinen?_

### Bygga labbsetup

Utrustning:

- Utvecklingskort Arduino Due
- USB-kabel
- Knappsats för kodlås (samma som i förra uppgiften)
- Anpassningskablar mellan knappsats och Due-kortet

![Figur 5: Labutrustning med knappar och lysdioder](equipment.png)

Bilden ovan visar laborationsutrustningen med tre knappar, tre gröna (små) och en röd (stora) led.  
Anslutningar är via en flatkabel med 10 banankontakter, de borde vara markerade. Kontakterna har en tendens att flätas ihop, vänligen var mycket försiktig när du flätar upp dem. Om man tittar på kabeln med röda markeringen till vänster så är ordningen på kontakterna följande: 

Kontakt | Syfte
---|---
1 | Inte ansluten 
2 | GRND - ground 
4 | B3 – tredje knapp från vänster 
5 | L3 – tredje små grön led från vänster  
6 | B2 – knappen i mitten
8 | B1 – första knapp från vänster 
9 | L1 – första små grön led från vänster 
Det skiljer sig alltså mot förra uppgiften. Om ni har ett externt spänningsaggregat så behöver ni nog en gemensam jord.

Kontakterna #3-9 skall kopplas till de digitala in och utgångarna på Due-kortet. Det finns en kopplingssats för detta ändamål.  
Håll reda på vilka som är in- respektive utgångar så att det blir rätt när du programmerar portarna i Atmel-studio.

### Programmering: I/O-pinnarna

I den förra labben skrev ni ett Matlab-program som testar alla knappar och led-lampor. Skapa ett nytt Atmel-projekt (TestButtons) och skriv ett program som gör samma sak i C där ni skriver en c-fil och tillhörande h-fil med funktioner som initialiserar och styr I/O-pinnarna som behövs och med hjälp av dem testar alla knappar och led-lampor så att ni vet att ni har kopplat rätt.

### Programmering: Sätta samman allt för att styra kodlåset med hjälp av Arduino Due

1. Du ska nu använda dig av Atmel studio-projektet `ProjectCodeLockInC` i ert repo. Projektet ska innehålla kod från olika källor (dvs olika c och h-filer):
    - Den tillståndsmaskin med tillhörande definitioner och funktioner du skrivit och testat som behövs för att låset ska fungera korrekt.
    - Kod (c & h-filer) för I/O pinnarna som du redan skrivit och testat ovan.
    - Kod (c & h-filer) som använder sig av FreeRTOS. Du ska skapa två tasks, den första kör tillståndsmaskinen och ändrar utgångarna till kodlåset. Den andra blinkar den inbyggda lysdioden (PB27 = Due pin 13).
2. Använd ASF Wizard för att inkludera biblioteken för I/O-port och FreeRTOS.
3. Skriv en `main()` (i main.c) som startar de två tasks.

I första hand ska du skriva ett program som kan hantera den förutbestämda sekvensen för knapptryckningarna enligt tillståndsmaskinen ovan.  
Som extrauppgift kan du modifiera programmet så att du genom att ange sekvensen som en deklaration på ett enda ställe innan du kompilerar programmet. Blir det olika svårt beroende på vilken metod för att implementera tillståndsmaskinen som du valde?

#### ASF Wizard
Innan du börjar skriva kod behöver du lägga till några moduler till projektet via ASF. För att kunna använda sig av FreeRTOS måste man först importera källkoden till sitt projekt.  

ASF module | Beskrivning
--- | ---  
Generic board support (driver) | Innehåller kretskort-specifika definitioner och prototypfunktioner, såsom kretskort initiering funktionen.
En lista med **Available Modules** dyker upp. Där ska du hitta `FreeRTOS mini Real-Time Kernel` och markera den. Klicka sedan på knappen Add to selection. Nu kommer du kunna se modulen i Selected Modules, under denna lista ser du alla moduler som kommer att finnas med i ditt projekt. Klicka sedan på Apply. Kryssa i rutan I accept the license agreement när det behövs och gå vidare.

![](ASFWizard.png)
Bilden nedan visar i vilka kataloger var källkoden  till FreeRTOS hamnar i projektet.
![](freeRTOSfolder.png)

### Implementera RTOS tasks med tillståndsmaskinen

Skapa en ny c-fil för den första av de två tasks som ska köras. Denna c-fil innehåller följande funktion:
void task_codeLock(void *pvParameters)
    {
    	/* Insert your code for reading the buttons here */
    	/* Insert your code for controlling the code lock lamps here */
    }
```
Tillståndsmaskinen kommer alltså att köras var 200 ms.

#define TASK_CODELOCK_STACK_SIZE		(2048/sizeof(portSTACK_TYPE))

### Skapa ytterligare en c-fil för den andra tasken 

/**
    const TickType_t xTimeIncrement = 500;

    xLastWakeTime = xTaskGetTickCount(); /* Initialise the xLastWakeTime variable with the current time. */
    while (i) {
        gpio_toggle_pin(LED0_GPIO);
`vTaskDelayUntil()` gör att lysdioden blinkar med precis 1 sekunds periodtid (tänd 500ms, släckt 500ms), den räknar alltså tiden från början av while-loppen inklusive tiden det tar att ställa om lysdioden.

h-filen för LED-tasken behöver också innehålla några definitioner också, utöver deklarationen av task_led-funktionen:
#define TASK_LED_STACK_SIZE		(1024/sizeof(portSTACK_TYPE))
```

### Watchdog timer (WDT
Följande är hämtat från databladet för SAM3X8E:

> The Watchdog Timer (WDT) can be used to prevent system lock-up if the software becomes trapped in a deadlock. It restarts with initial values on processor reset.   

I klartext betyder det att om man inte gör något åt det så kommer processorn att göra en reset efter ett tag då WDT har räknat ner till noll. Om man inte behöver funktionen att detektera och förhindra låsning av programmet så kan man avaktivera WDT med följande funktion från ASF i början av sitt program: 

```c
void wdt_disable(void);
```

### Sätta samman allt i `main.c`
/* defines, includes of the h-files for the tasks

### Köra det färdiga programmet

Kör programmet och spela in en video av fungerande lås, antingen som länk till youtube-klipp eller som videofiler (obs max 30 sec per video), uppladdad till It’s learning.

Nu har du klarat av all programmering som behövs (men det är lite kvar med själva inlämningen för att få godkänt).  
Visa gärna upp Due-kortet med låset för handledaren om du befinner dig i labbsalen. Glöm inte att committa det färdiga programmet med git på din dator.

Tänk på att du måste ange vilken metod du använt dig av för att implementera en tillståndsmaskin i C, t.ex. både som kommentar i din kod och som meddelande i din pull request.  

### Lagra arbetet på github och lämna in för bedömning

Om du är klar med all programmering är det vara dags att synka ditt lokala repo med det som du har på github. Det görs med en push tillbaka till github. Din gitklient är oftast så smart att den kommer ihåg varifrån man klonade repot, därför kan man oftast använda origin istället för den långa webbaddressen (<https://github.com/StudentNN/Task1501f.git>. 

Har du kommit så långt har du ett uppdaterat repo som du kan se på githubs webbsida. Nu ska du skicka in en begäran att ägaren till det gemensamma kursrepot ska titta på dina ändringar genom en pull request (steg 5 i Figur 3). Där anger du en rubrik (till exempel att du är klar med en viss uppgift), och fyller i en beskrivning av vad dina ändringar består av.

**Glöm inte att ange namnen alla som bidragit med att göra klart uppgiften!** Det går inte att komma i efterhand och påstå att du varit med om ditt namn inte finns med på originalinlämningen! I så fall får du göra en egen pull request efteråt.

Ulrik kommer att titta på alla som har lämnat in till fredag. Om du lämnar in senare kommer de att bedömas vid tentamen.

Appendix: Output från sitt program
======
Eftersom det inte finns någon naturlig bildskärm kopplad till Due-kortet måste man få ut saker som vanligtvis skulle skrivas på en terminal på annat sätt.

I `ConsoleFunctions.c` finns ett exempel hur man initierar att Due-kortet skriver på COM-porten på PC:n via USB-kabeln (`configure_console(void)`). Det gör det möjligt att använda terminalfönstret inifrån Atmel Studio som output för printf().  
Det finns dock ingen motsvarande h-fil, så den måste man skriva själv!

Man måste dessutom inkludera Atmels biblotek för seriell I/O med hjälp av ASF wizard i Atmel Studio. Parametrarna för terminalkommunikationen måste man ange i filen config/conf_uart_serial.h som genereras av ASF wizard när man inkluderar biblioteket. Enklast är att använda default-parametrarna genom att bara ta bort kommentarssymbolerna.

Terminalfönstret konkurrerar med Bossac om COM-porten så när man laddar ner sin binärfil till DUE-kortet måste terminalfönstret vara o-connectat.  
Så fort man laddat ner sin binärfil till Due så startar ju programmet och därför missar man utskriften innan man gjort connect igen. Gör connect och tryck på reset-knappen för att starta programmet om igen.

Appendix: FreeRTOSConfig.h
======
Följande fil finns också inkluderad i huvudkatalogen i git-repot och kan ersätta den som finns i Atmel-projektet i en underkatalog till ASF när du ska använda FreeRTOS.

```c
```