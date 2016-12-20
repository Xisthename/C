Uppgift 1501a
======
------
------




1. Om annan dator än labbsalens dator används (t.ex. egen dator) måste följande program finnas installerat på den datorn:


Grunderna hur man arbetar med git-klienten för Windows finns på



### Skapa ett personligt repo för denna programmeringsuppgift med hjälp av Git

![Figur 1: Fork-knappen på githubs webbsida](fork.png)

2. Ange att du skall forka repot till din egen användare på github (den har du redan skapat). I resten av handledningen kallas denna användare _StudentNN_.

3. Än så länge finns bara ditt nya repo på github-servern, men du vill ju kunna jobba med projektet lokalt på din dator. Därför måste du klona det nyligen skapade repot till din lokala dator, vilket betyder att du skapar en identisk kopia som hela tiden kan synkas med github med kommandona pull och push.  
Välj en katalog på datorn där du vill ha din lokala kopia av repot.  
Klona repot på github repo till din valda katalog på datorn med hjälp av github-bash.  Adressen du ska använda finns under HTTPS clone URL. Kommandoraden blir i Unix eller gitbash om man står i önskad katalog:
    
    >git clone https://github.com/StudentNN/Task1401f.git

![Figur 2: Adressen till ett kodreps på githubs webbsida.](cloneAddress.png)

Under labben är det enklast om man jobbar mot ett och samma forkade repo i hela labben, även om det tillhör bara en specifik student. Om ni är två som vill jobba med varsitt lokalt repo kan ni ge båda studenterna rättigheter att jobba mot samma repo och sen klona repot på github till två olika datorer.

![Figur 3: Översikt över hur man forkar, klonar och synkar kodrepor i kursen. Kursens gemensamma repo är rött, ditt privata repo är blått.](repoOverview.png)

I katalogen `Task1501a` finns denna handledning i mappen `Instruction` och en projektmapp för Atmel studio vid namn `ProjectDigitalIO`



    >git commit –am ”mywork”

Varje commit bör vara en ”unit of functionality” som alltid kompilerar, t.ex. refaktorera namnet på en funktion, en ny feature, eller förbättrad dokumentation. Varje commit måste också ha en beskrivande kommentar så man vet vad det faktiskt var man ändrade (Ett fullt realistiskt exempel kan ses på <http://xkcd.com/1296/>).  
Git sparar alla tidigare commits, så man kan närsomhelst backa till ett tidigare commit-tillfälle om det skulle behövas.

Om en fil aldrig har blivit committad tidigare måste man ange att den ska adderas till Git-repot.

    >git add filnamn.xxx

eller
 
    >git add --all
    
Efter man gjort det första gången håller Git reda på att filen ”ingår” i repot (men den måste committas första gången ändå!). Git-klienterna burkar hålla reda på nyskapade filer i katalogerna som tillhör repot och frågar om de ska adderas.


- Utvecklingskort Arduino Due
Finns inte det kommandot i menyn följ instruktionerna här, eller som kommentarer i bat-filen: <https://github.com/ctbenergy/BossacArduinoDue>  



Testrunner-filen och filen(erna) med testerna ligger i katalogen test. Testramverket unity ligger i katalogen unity.  
När man sen vill använda sina testade filer i produktionssystemet behöver man bara filerna i src-katalogen. Testfilerna används alltså bara under utveckling.




void pinMode(int pinNumber, mode_definition mode)

men det första testfallet gäller bara den första av dessa funktioner.
0x0010 | Output Enable Register | PIO_OER | Write-only | -
/* defines the address for enabling the output pins of port B register with base adress 0x400E1000*/
```
 
*p_PIOB_OER |= 0x000000040;
```

```c
int i; /* loop counter for the delay */	

Lagra arbetet på github och lämna in för bedömning

    >git add –all
    
säger till git att hålla reda på alla nya filer som skapats om man står i repots huvudkatalog.

Det går att fråga git-klienten om några nya filer har tillkommit i repots katalog.

    >git status
    
Innan man har lagt till filerna så uppdaterar en commit bara de filer som redan finns i repot.

    >git push origin

Din gitklient är oftast så smart att den kommer ihåg varifrån man klonade repot, därför kan man oftast använda origin istället för den långa webbaddressen (<https://github.com/StudentNN/Task1501a.git>). 
======