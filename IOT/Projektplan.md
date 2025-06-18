# 7-11 Bygg Projektplan
# Sensor Pro 
## Medlemmar:


### Frontend:

*Alex Raunert* Github: https://github.com/AlexanderRaunert

*Teodora Kricka* Github: https://github.com/Teo-02


### Fullstack:

*Andreas Zetterlund* Github: https://github.com/andreaszetter

*Frank Norqvist* Github: https://github.com/FrankNorq

*Sebastian Ritschevald* Github: https://github.com/bugstile

### IoT:

*Wilmer Forsman* Github: https://github.com/Wilmer-Chas

*Fabian Åman* Github: https://github.com/Jockomoko

*Nikki Norman* Github: https://github.com/StikkyNikki

*Viktor Kvick* Github: https://github.com/Viktorkvick

*Sandra Obradovic* Github: https://github.com/sandpand


## Obligatoriska delar i projektplanen


### Introduktion och bakgrund

**Kortfattad beskrivning av projektets syfte och mål.**

Puls, temperatur, ljudnivå, luftkvalité, rörelse  
Vårt projekt ämnar att ge byggarbetsplatser ett enkelt och användbart sätt att hålla byggarbetare säkra genom att kontinuerligt övervaka arbetsförhållanden och deras hälsostatus i realtid. Produkten mäter arbetsförhållandet med olika sensorer som mäter luftkvalitet, ljudnivåer, temperatur och puls, och kan identifiera potentiella risker för arbetarna. Produkten ska informera användarna via en app eller webbgränssnitt om dessa risker och ge varningar om någon parameter är för hög eller låg.

### Problem som löses genom projektet

Personer som jobbar i potentiellt farliga miljöer kan övervakas på både individnivå samt deras omgivning.  
Arbetsplatser inom byggbranschen innebär ofta att arbetarna utsätts för fysiskt påfrestande miljöer där luftkvalitet, ljudnivåer, temperatur och puls kan påverka deras hälsa negativt. Det finns ofta ingen effektiv övervakning av dessa faktorer i realtid. Därmed kan risken för olyckor eller ohälsa öka om det inte vidtas lämpliga åtgärder i tid.

- **Arbetarskydd:** Övervakar individens hälsodata och omgivning i realtid.
- **Riskidentifiering:** Upptäcker farliga nivåer av ljud, luftkvalitet eller temperatur.
- **Snabb respons:** Varna arbetsledare och arbetare direkt vid kritiska nivåer.
- **Effektiv övervakning:** Ger arbetsgivare bättre insikt i arbetsmiljön.

### Möjliga intressenter och målgrupper

- **Primära målgrupper:** Byggarbetsplatser, industriella arbetsmiljöer, saneringsteam.
- **Sekundära målgrupper:** Vården, där byggarbetare kan behöva hjälp vid fysisk påfrestning eller hälsoproblem.
- **Intressenter:** Företag som är ansvariga för arbetsmiljö och säkerhet på byggarbetsplatser, arbetsmiljö experter, och försäkringsbolag.

### Val av teknologi och arkitektur

- **Frontend:** React Native
- **Backend:** Kandidater: NodeJS, C, C++, C#, Python  
  Databaser (SQL, XML, JSON)
- **IoT:** Måste vara mellan språk C++, C, Arduino (Stödjer EJ andra programmeringsspråk)

#### Översikt över systemarkitekturen
- **IOT:** Hanterar datainsamling som skickas över till backend.
- **Backend:** Hanterar datan och utför instruktioner för datan som skickas vidare till frontend. Skapa API/REST-API
- **Frontend:** Visar resultatet från instruktionerna på ett användarvänligt sätt.

#### Beslut kring databas- och API-struktur
Vi kommer använda oss av Node.js och Express eftersom det är vad vi kommer att lära oss i kursen.  
SQL = PostgreSQL

### Hårdvara:
- DHT11 temperatur- och fuktighetssensormodul
- Ljudsensormodul
- GY-68 BMP180 barometer- och temperatursensormodul
- MQ-2 gaskänslig sensormodul (??)
- Pulse Sensor
- GPS
- WiFi 1010, Arduino Nano 33 IoT

## Teamstruktur och ansvarsområden

### Gruppens sammansättning – vilka ingår i varje team?

- **Systemutvecklare:** Viktor, Wilmer, Sandra, Nikki, Fabian
- **Fullstack:** Andreas, Frank, Sebastian, Moa
- **Front-end:** Alex och Teodora.

### Beskrivning av huvudansvar och arbetsuppgifter för varje team

- **Front-end:** Utveckla användargränssnittet och mobilapplikation. UX.
- **Fullstack:** Bygga API, databas och auth.
- **Systemutvecklare:** 
  - Konfigurera och kalibrera sensorer.
  - Programmera Arduino för att kommunicera med backend.
  - Implementera strömsnål dataöverföring.
  - Säkerställa robust hårdvarufunktionalitet.

### Hur teamen ska arbeta tillsammans och säkerställa kunskapsöverföring
Teamet kommer att hålla regelbundna stand-ups (1 gång i veckan) för att säkerställa att alla är på samma sida och lösa problem direkt. Vi kommer att använda kodgranskning via pull requests och dela dokumentation i vårt GitHub-repo.

## Arbetsmetodik och verktyg

### Val av agil metodik (Scrum, Kanban eller liknande)
Kanban i helgrupp men även scrum inom små-teamen.

### Vilka verktyg som ska användas för:
- **Kodhantering:** VS code, PlatformIO, Git & GitHub
- **Kommunikation:** Discord
- **Sprintplanering och uppgiftshantering:** GitHub kanban.

#### Hur teamet hanterar standups, sprintplanering, retros och demos
Varje dag som vi arbetar med projektet börjar vi med en standup, där vi kort går igenom vad som ska göras individuellt och planerar upp dagen.

#### Plan för code reviews och pull requests
Vi skapar nya feature-branches och skapar sedan pull requests när vi mergar in dessa i develop/main. När en pull request är skapad kan en annan person från samma lag code-review.

### Övergripande tidsplan (kan vara ett Gantt-schema eller en lista med sprintmål)
När ni förväntar er att vara klara med:

#### Fullstack:
- **Vecka 12-13:** Kravinsamling och planering.
- **Vecka 14-18:** Databasdesign och prototyping.
- **Vecka 19:** API och autentisering.
- **Vecka 20:** Integration och testning.
- **Vecka 21:** Utvärdering och förbättringar baserat på tester.

#### Systemutvecklare:
- **Vecka 12:** Planering av inköp, tidsplan, kravspecifikationer.
- **Vecka 13:** Bygga upp GitHub-repo och kanban tavla.
- **Vecka 14:** Bygga prototyp i TinkerCAD.
- **Vecka 15-18:** Kalibrera sensorer och programmering av Arduino.
- **Vecka 19-21:** Slutföra påbörjade delar och implementera nya funktioner.
- **Vecka 22:** Testning, optimering, förberedelser inför presentation.
- **Vecka 23:** Projektavslutning, presentation.

#### Frontend:
- **Vecka 13-14:** Skapa wireframes och UI-skisser i Figma.
- **Vecka 15-18:** Implementera grundläggande layout och struktur.
- **Vecka 19-21:** Implementera huvudfunktioner och API-anrop.
- **Vecka 22:** Bugfixar och responsivitetsproblem.
- **Vecka 23:** Förberedelse inför presentation.

## Riskanalys och Plan för Problemhantering

### Vilka risker kan uppstå?
- **Risk inom Frontend:** Att anpassa UI efter alla mobilupplösningar.
- **Risk för koordinationsbrist:** Otydlig kommunikation mellan grupper kan leda till missförstånd om vad som är gjort.
- **Sensorproblem:** Det finns en risk att sensorer inte fungerar, vilket leder till att nya sensorer behöver beställas.
- **Tekniska problem:** Hur en Arduino kopplas genom nätet till mjukvaran är osäkert.
- **Hårdvarufel:** Hårdvaran kan gå sönder under utvecklingen.
- **Fördröjningar:** Fullstack-utvecklare kanske inte vet vilken data som behövs för backend.

### Hur ska ni hantera problem som blockerar utvecklingen?
Vi håller öppen dialog och ser till att alla känner sig hörda och sedda för att lösa potentiella blockeringar.

### Vilka steg tar ni om en teammedlem inte levererar enligt plan?
Vi pratar med personen och undersöker vad som har gått fel och ser om det finns möjlighet att hjälpa till för att komma på rätt spår igen.

## Leveranser och dokumentation

### Slutproduktens minimikrav
En minimal prototyp med åtminstone en sensor som kan läsas och en fungerande app.

### Vad varje team måste leverera
- **Frontend:** Wireframes, Mockups & Prototyp (i Figma), UI, Mobilapp
- **Backend:** Databaser, uppkoppling mellan Arduino, databas och applikation.
- **Systemutvecklare:** Bygga hårdvaran och skriva koden för hårdvaran.

### Dokumentation
- **README.md:** Ansvaras av ALLA.
- **Accessibility.md:** Ansvaras av FrontEnd.
- **Kanban tavlan:** Ansvaras av ALLA.

### Plan för att hålla README och API-dokumentation uppdaterad
Ha en check-up i veckan och uppdatera README vid behov.

## Slutlig checklista för projektplanen
- Dokumenteras som PROJEKTPLAN.md i Git-repot.
- Ska innehålla alla ovanstående punkter innan inlämning vecka 12.
- Projektplanen skickas till respektive utbildare senast den 21/3 klockan 15.00.
- Godkännas av utbildare innan utvecklingsarbetet startar.

## Komponenter

- DHT11 temperatur- och fuktighetssensormodul
- Ljudsensormodul
- GY-68 BMP180 barometer- och temperatursensormodul
- MQ-2 gaskänslig sensormodul
- Li-po Battery with a JST connector
- Micro-usb cable to usb A

## Inköp
- [Pulse Sensor](https://www.electrokit.com/pulse-sensor?gad_source=1&gclid=Cj0KCQjws-S-BhD2ARIsALssG0ZHT4qrGGSZBAvNf7QUsEawEiVn10Ps1-5R3koA8Ee1uJWa8OKALSwaAoKrEALw_wcB)
- [Arduino MKR WiFi 1010](https://www.electrokit.com/arduino-mkr-wifi-1010?gad_source=1&gclid=Cj0KCQjws-S-BhD2ARIsALssG0YEc8SuMs2tlNIh_GSh-lgSGMNSgjgY7Fwwuy5J76C6Lp2cyn7i4RwaAgYZEALw_wcB)
- [Lipo Battery with JST connector](https://www.amazon.com/802040-Battery-Rechargeable-Lithium-Connector/dp/B09WN4XP59)
- [GNSS/GPS](https://www.electrokit.com/gps-modul-u-blox-neo-7m-for-arduino)
- [Batteri hylsa](https://www.electrokit.com/batterihallare-2x18650-sladdanslutning?gad_source=1&gclid=Cj0KCQjws-S-BhD2ARIsALssG0ZP3UC5KVU5rKhrko89EO-yGENIQqO5c4Rzpa3vapcQHz1miIjOKe0aAtAiEALw_wcB)
- [Micro USB](https://www.amazon.com/Amazon-Basics-Charging-Transfer-Gold-Plated/dp/B07232M876?th=1)
