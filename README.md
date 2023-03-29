# Informationssicherheit

- **Kryptologie**
  - [1. Was ist die Kryptologie?](#1-Was-ist-die-Kryptologie) 
  - [2. Was ist die Kryptographie?](#2-Was-ist-die-Kryptographie)
  - [3. Was ist die Kryptoanalyse?](#3-Was-ist-die-Kryptoanalyse)

- **Hashfunktionen**
  - [1. Was ist eine Hashfunktion?](#1-Was-ist-eine-Hashfunktion)
  - [2. Anwendungen](#2-Anwendungen)
  - [3. Kriterien einer guten Hashfunktion](#3-Kriterien-einer-guten-Hashfunktion)
  - [4. Das Salz in der Hashsuppe](#4-Das-Salz-in-der-Hashsuppe)
  - [5. Pfeffer einer Hashfunktion](#5-Pfeffer-einer-Hashfunktion)

- **Verschlüsselung**
  - [1. Was ist eine Verschlüsselung?](#1-Was-ist-eine-Verschlüsselung)
  - [2. Kriterien einer guten Verschlüsselung](#2-Kriterien-einer-guten-Verschlüsselung)
  - [3. Symmetrie vs Asymmetrie](#3-Symmetrie-vs-Asymmetie)
  - [4. RSA](#4-RSA)
  - [5. Sicherheit von RSA](#5-Sicherheit-von-RSA)
  - [6. Anwendungen von RSA](#6-Anwendungen-von-RSA)

 - **Implementation**
   - [1. GUI](#1-GUI)
   - [2. Testen](#2-Testen)
# Kryptologie

## 1. Was ist Kryptologie?
Die [Kryptologie](https://www.kryptowissen.de/kryptologie.html) ist die Wissenschaft der Informationssicherheit. Sie beschäftigt sich mit dem Verschlüsseln und dem Entschlüsseln der Daten. Kryptologie teilt sich in zwei Bereiche: [Kryptographie](https://de.wikipedia.org/wiki/Kryptographie) und [Kryptoanalyse](https://de.wikipedia.org/wiki/Kryptoanalyse). Die Bereiche haben unterschiedliche Ziele und Methoden, aber sie sind natürlich sehr eng miteinander verbunden.
## 2. Was ist die Kryptographie?
Die [Kryptographie](https://de.wikipedia.org/wiki/Kryptographie) beschäftigt sich, wie man einen sicheren der Datenaustausch ermöglicht. Dabei das Wort "sicher" ist durch die Ziele der [Kryptographie](https://de.wikipedia.org/wiki/Kryptographie) definiert.

**Ziele der Kryptographie**:

- **1. Vertraulichkeit** 

Die Daten müssen auf einem vertraulichen Kanal ausgetauscht werden. Also, ein Dritte, der nicht berechtigt ist, soll nicht an dem Datenaustausch teilnehmen können.

- **2. Integrität**

Selbst auf einem vertraulichen Kanal kann der Datenaustausch manipuliert worden sein. Denn ein Angreifer kann vielleicht die Daten nicht verstehen, aber dennoch zu seinen Gunsten so verändern, dass die Daten entweder unnutzbar sind oder gar gefährlich sind.

- **3. Authentizität**

Es kann sein, dass integre Daten auf einem vertraulichen Kanal empfangen werden, aber sie nicht von der Person kommen, von der man sie erwartet hätte. Also, das kann auch schlimme Folgen für den Empfänger haben.

Nun ist die Frage, mit welchen Mitteln erreicht man solche Ziele?

**Methoden der Kryptographie**:

**1. Symmetrische Methoden**

Die bekannteste symmetrische Methode ist die [Caesar-Verschlüsselung](https://de.wikipedia.org/wiki/Caesar-Verschl%C3%BCsselung). Also, man braucht zum Verschlüsseln und Entschlüsseln denselben Schlüssel:
<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/CaesarVerschluesselung.png">

Hier auf dem Bild sieht man, dass die deutsche Alphabet um 3 Buchstaben nach links verrutscht sind. Die ersten 3 Buchstaben *A, B, C*  kommen dann ans Ende der Tabelle. Somit kann man der Sender Nachrichten verschlüsseln und der Empfänger kann dann dies mit derselben Tabelle entschlüsseln. Das ist aber nicht vertraulich genug, denn der Angreifer muss nur noch den Schlüssel 3 kennen.

Vorteile:
- Sie ist i.d.R. einfach zu verstehen und jede Person kann sie ohne großes Wissen verwendet.
- braucht i.d.R. keine große Rechenzeit.

Nachteile:
- Die Einfachheit ist wiederum ein Nachteil. So kann auch der Angreifer diese Einfachheit nutzen.
- Datenaustausch nur mit einem Schlüssel

**2. Asymmetrische Methoden**

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/AsymmetrischeVerschl%C3%BCsselung.png" width="519" height="616" >

Bei den asymmetrischen Methoden verwendet man zwei Schlüssel Paare: öffentlicher und private Schlüssel. In der Regel verwendet der Empfänger den privaten und der Sender den öffentlichen Schlüssel. Also, jeder, der dem Empfänger eine Nachricht schreiben will, verschlüsselt diese Nachricht mit dem öffentlichen Schlüssel und sendet sie an den Empfänger. Diese Nachricht kann nur mit dem privaten Schlüssel entschlüsselt werden und ihn hat nur der Empfänger. Das ist wesentlich eine vertrauliche Methode als die symmetische Methode. Das eine der bekanntesten asymmetischen Verlüsselungen ist die von [RSA](https://de.wikipedia.org/wiki/RSA-Kryptosystem)


Vorteile:
- Parteien müssen nicht denselben Schlüssel haben. Ein Dritte kann nicht den allgemeinen Schlüssel durch irgendwelche Methoden wissen, da es ja ihn nicht gibt.
- Es stellt in gewissermaßen sicher, dass die Nachricht tatsächlich vom Sender kommt. Siehe [Autäntizität](#Autäntizität).

Nachteile:
- Es ist schwer zu verstehen
- Es ist aufwendig zu verschlüssel bzw. zu entschlüsseln. 

 **3. Hybride Methoden**
 
Sowohl die symmetrische als auch die asymmetrische Methoden haben ihre Vor und Nachteile. Bei der hybriden Methoden will man diese Nachteile vermeiden und die Vorteile nutzen.


## 3. Was ist die Kryptoanalyse?
Die [Kryptoanalyse](https://de.wikipedia.org/wiki/Kryptoanalyse) versucht die Schwachstellen eines kryptographischen Systems zu finden und zu knacken. Also, die Ziele der [Kryptoanalyse](https://de.wikipedia.org/wiki/Kryptoanalyse) sind Gegenteil von Zielen der [Kryptographie](https://de.wikipedia.org/wiki/Kryptographie). Generell gibt es zwei Methoden:
- **Brute-Force**

Die [Brute-Force-Methode](https://de.wikipedia.org/wiki/Brute-Force-Methode) ist nichts anderes, als reines Durchprobieren aller Möglichkeiten eines kryptographischen Systems. Natürlich bei einer niedrigen Anzahl der Möglichkeiten wird man in angemessener Zeit den Datenaustausch fangen.
- **Analystische Methoden**

Zu den analytischen Methoden gehören z.B. algebraische oder statistische Modelle, mit denen man die Schwachstellen findet.


# Hashfunktionen

## 1. Was ist eine Hashfunktion?
Eine [Hashfunktion](https://de.wikipedia.org/wiki/Hashfunktion) ist eine mathematische Einwegfunktion. Eine Einwegfunktion ist deswegen interresant, da man aus den Ausgabewerten der Funktion schwer bis praktisch unmöglich die Eingabewerte bestimmen kann. Die Betonung liegt hier auf den Eingabewerten, denn sie gelten zu verheimlichen bzw. verstecken. Schauen wir uns ein Beispiel an:

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/2hochkFunktion.png" >
<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/Einwegfunktion.png" >

Es ist eine Abbildung von {1,...,10} auf {1,...10}. Man sieht, dass die Werte irgendwie gestreut sind.
Das erreicht man dadurch, indem man für jeden k aus {1,...,10} 2 hoch k mod 11 (Primzahl) berechnet. Z.B. 2 hoch 4 = 16 und 16 mod 11 = 5. Also, f(4) = 5. 

Man kann zeigen, dass für jede Primzahl *n* eine Basis *a* gibt,  sodass eine solche Funktion möglich ist. Da wir hier eine kleine Primzahl nämlich *n* = 11 gewählt haben, ist es nicht so schwierig mit [Brute-Force](https://de.wikipedia.org/wiki/Brute-Force-Methode) die Eingabewerte zu berechnen. Aber wenn dies auf eine große Primzahl angewendet wird, kommt man auch mit [Brute-Force](https://de.wikipedia.org/wiki/Brute-Force-Methode) nicht voran. Denn bis jetzt ist keine Methode bekannt, die wesentlich schneller ist als reines Durchprobieren.
## 2. Anwendungen
Eine Hashfunktion werden in vielen Bereichen eingesetzt. Einige davon sind:
- [Digitale Signatur](https://de.wikipedia.org/wiki/Digitale_Signatur)

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/DigitaleSignaturOhneHash.png">

Anwendung der Hashfunktionen bei einer digitalen Signatur findet zusammen mit RSA statt. Zunächst möchte ich aber ohne Hashfunktion die [Digitale Signatur](https://de.wikipedia.org/wiki/Digitale_Signatur) erklären und dadurch entstehende Schwächen zeigen.

Es geht um die Authentizität des Senders. Möchte der Sender als eine sichere Quelle auftreten, verwendet er eine asymmetrische Verschlüsselung. Dafür verwendet man i.d.R. die RSA. Deshalb erstellt der Sender einen PS und einen ÖS und gibt den ÖS bekannt. Nun möchte der Sender eine Nachricht *m* senden und dabei beweisen, dass er tatsächlich die Nachricht gesendet hat. Er verwendet dabei den PS und verschlüsselt die Nachricht *m* mit RSA, also *RSA(m,PS) = n*. Man kann *n* offensichtlich nur mit ÖS entschlüsseln. Nun also, gibt es zwei Möglichkeiten: entweder *n* lässt sich mit ÖS entschlüsseln, also *RSA(n,ÖS) = m* und somit ist der Sender authentifiziert also er hat die Nachricht *m* signiert, oder *RSA(n,ÖS) ≠ m* somit ist der Sender ist nicht die tatsächliche Quelle, die den PS hat.

Ein Problem bei obigen Vorgehen ist, dass ein Dritte kann sich auch als sichere Quelle für eine Nachricht *m* authentifizieren, obwohl er nicht den PS hat. Dabei verwendet er die [Homomorphieeigenschaft](https://de.wikipedia.org/wiki/Homomorphismus) von RSA. Angenommen, ein Dritte hat zwei Nachrichten mit *m1* und *m2* und hat dementsprechend auch die *RSA(m1,PS) = n1* und *RSA(m2,PS) = n2*. Da RSA eine [Homomorphie](https://de.wikipedia.org/wiki/Homomorphismus) ist , es gilt: 

*RSA(m1·m2,PS) = RSA(m1,PS)·RSA(m2,PS) = n1·n2*. Damit wäre *m = m1·m2* erfolgreich signiert, denn der Empfänger wird beim Entschlüsseln auch auf den Wert *m1·m2* kommen:

*RSA(n1·n2,ÖS) = RSA(n1,ÖS)·RSA(n2,ÖS) = m1·m2* und somit wird der Empfänger denken, dass ein Dritte sein der Sender.

Ausweg aus diesem Problem ist eine kollisionsfreie Hashfunktion. Man signiere nicht direkt eine Nachricht *m* sondern, ihren Hashwert *v*. Angenommen hat ein Dritte wieder die Signaturen *v1* und *v2* für Haswerte *n1* und *n2*. Dabei gilt es auch natürlich wegen der [Homomorphie](https://de.wikipedia.org/wiki/Homomorphismus) von RSA:

*RSA(v1·v2,PS) = RSA(v1,PS)·RSA(v2,PS) = n1·n2*. Nun muss er aber wissen, was das Urbild von *n1·n2* bezüglich dieser Hashfunktion ist. Es sehr unwahrscheindlich, dass er es herausfindet, da eine Hashfunktion eine Einwegfunktion ist.

Ein anderer Grund nicht direkt die Nachricht *m* zu signieren, sondern ihren Hashwert, ist die Größe der Nachricht *m*. Wenn die Nachricht zu groß ist, ist es aufwendig sie zu verschlüsseln und zu entschlüsseln. Stattdesswen berechnet man den Hashwert, der kleiner ist als die Nachricht *m* und signiert man diesen Hashwert.

**Note**: Viel recherchiert, aber ich habe keine Antwort darauf gefunden, wieso ein Dritte nicht einfach alle Hashwerte von der Definitionsmenge berechnet und schaut, was das Urbild von *n1·n2* ist.


<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/DigitaleSignatur.png">


- Passwortspeicherung

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/Passwort.png" >
Die Passwörter werden in der Datenbank nicht im Klartext geschrieben, sondern es werden die Hashwerte der Passwörter in der Datenbank festgehalten. Man kann meinen, dass man die Passwörter auch verschlüsselt in der Datenbank festhalten kann. Das Verschlüsseln hat den ersten Nachteil gegenüber dem Hashen, nämlich man kann sie wieder entschlüsseln, falls sie nicht so aufwendig verschlüsselt sind. Man kann nun sagen, dass man auch aus den Hashwerten die Passwörter auch erraten kann. Das stimmt, allerdings da kommt auch der zweite Nachteil vom Verschlüsseln, nämlich die Berechenbarkeit. Hashfunktionen sind schneller zu berechnen als Verschlüsseln bzw. Entschlüsseln. Aber in der Praxis kommt es auch vor, dass man auch die Hashwerte verschlüsselt.

- [Prüffsumme](https://de.wikipedia.org/wiki/Pr%C3%BCfsumme)

Hier findet ihr ein Beispiel für [Prüfsumme](https://www.mathematik.uni-kl.de/~gathmann/class/ags-2019/ags-2019.pdf)

## 3. Kriterien einer guten Hashfunktion
Es gibt mehrere Hashfunktionen und manche davon sind mittlerweile nicht mehr sicher, die [Liste](https://ehash.iaik.tugraz.at/wiki/The_Hash_Function_Zoo) jener Hashfunktionen. 

Es gibt unterschiedliche Kriterien, die je nach Einsatz bei einer Hashfunktion gefordert sind:
- Es ist eine Einwegfunktion - dies gilt für alle Hashfunktionen
- keine Kollision bzw. sehr geringe Wahrscheinlichkeit für eine Kollision. Siehe [Kollisionsangriff](https://de.wikipedia.org/wiki/Kollisionsangriff)
- jeder Wert in der Zielmenge muss getroffen werden können, damit möglichst eine Gleichverteilung gibt. Also eine [Surjektivität](https://de.wikipedia.org/wiki/Surjektive_Funktion) ist verlangt.
- Schnelle Berechenbarkeit.

In der Passwortspeicherung gibt es noch ein Kriterium, das erfüllt werden muss, nämlich das sogenante [Lawineneffekt](https://de.wikipedia.org/wiki/Lawineneffekt_(Kryptographie)). Also, kleine Veränderungen in Eingabewerten müssen zu völlig unterschiedliche Ausgaben führen.

## 4. Das Salz in der Hashsuppe

Es gibt mehrere Angriffsmöglichkeiten, wenn die als Hashwerte gespeicherte Passwörter geklaut werden. Eine davon ist die Nutzung von sogenannter [Rainbow-Table](https://de.wikipedia.org/wiki/Rainbow_Table), in der die Hashwerte der beliebtesten Passwörter mit vielen möglichen Hashfunktionen berechnet sind. Der Angreifer muss nur lediglich die geklauten Hashwerte mit allen möglichen Hashwerten der [Rainbow-Table](https://de.wikipedia.org/wiki/Rainbow_Table) vergleichen und somit kann er die Passwörter erraten.

Dieses Verfahren scheiter aber, wenn die Hashwerte auch gesalzt sind. Die Idee ist jedem Passwort eine neue zufällig generierte Zeichenfolge hinzuzufügen und dessen Haswert zu berechnen und dem Benutzer zuzuordnen. Diese zufällig generierten Zeichenfolgen werden im Klartext in der Datenbank festgehalten. Falls ein Benutzer sich anmelden will, wird von ihm geschriebenen Passwort die für ihn zufällig generierte Zeichenfolge hinzugefügt und der Hashwert berechnen. Stimmen dieser Hashwert mit dem Hashwert in der Datenbank überein, so ist dann die Anmeldung erfolgreich.

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/Salz.png">

Nun kann man nicht eine zweite [Rainbow-Table](https://de.wikipedia.org/wiki/Rainbow_Table) erstellen, in der eine zufällig generierte Zeichenfolge jem beliebtesten Passwort hinzufügen und dessen Hashwert speichen. Der Aufwand ist zu groß dafür und ist nicht mehr wirtschaftlich.
## 5. Pfeffer einer Hashfunktion
Das Pfeffern eine Hashfunktion dient demselben Zweck vom salzen einer Hashfunkiton. Der Unterschied liegt darin, dass es in i.d.R. wird die selbe Zeichenfolge zum Passwort hinzugefügt und diese Zeichenfolge ist geheim und wird nicht in der Datenbank festgehalten, sondern z.B. in einer geheimen Datei.

<img src="https://github.com/Fazil-edu/Hash_RSA/blob/main/Bilder/Pfeffer.png">



# RSA

## 1. Überblick RSA
[RSA](https://de.wikipedia.org/wiki/RSA-Kryptosystem) ist eine Verschlüsselungsmethode, die in der Praxis häufig zum Einsatz kommt. Sie ist eine asymmetrische Verschlüsselung, also es gibt nicht den einen Schlüssel für Ver und Entschlüsseln, sondern es gibt zwei Schlüssel, als ein Sclüssselpaar(siehe oben asymmetrische Methode). RSA wird häufig für die Gewähleistung der Vertraulichkeit verwenden, aber man kann sie auch in den hybriden Methoden sowohl für die Integrität als auch für die Authentizität einer Nachricht verwenden.

Ihr Schwerpunkt liegt in dem [Faktorisierungsproblem](https://de.wikipedia.org/wiki/Faktorisierungsverfahren). Also, man verwendet zwei große Primzahlen(i.d.R. ab 100 Stellen vorwärts), einer für privaten und der andere für den öffentlichen Schlüssel, die sehr schwer zu faktorisieren sind. Es gibt momentan kein bekanntes Verfahren, um sie zu faktorisien.
## 2. RSA Verfahren
Das RSA Verfahren basiert auf den folgenden Satz:
Seien *p,q* zwei verschiedene Primzahlen und sei *N := p*\q*. Ferner sei *0<e<N* mit *ggt(e,phi(N))=1* und *0<d<N* mit *e\*d=1 (mod(ph(N))* Dann gilt für jedes *0<m<N*:
*(m^e)^d = m (mod N)*.

Ausgehend von diesem Satz sind folgende Schritte sind zu tun:

- **1. Schritt: öffentlichen Schlüssel anlegen:**

1a. Eine Schranke *N* ermitteln:
Wähle zwei große Primzahlen *p* und *q* mit *p≠q* und setze *N=p\*q*.

1b. Ermittle eine Zahl *e* als öffentlicher Schlüssel:
Berechne *phi(N) = (q-1)\*(p-1)* und wähle eine beliebige Zahl 1 < *e* < *phi(N)* mit *ggt(e,phi(N)* = 1. 
Die [Eulerische Phi Funktion](https://de.wikipedia.org/wiki/Eulersche_Phi-Funktion) berechnet für ein gegebenes *n* die Anzahl der Elemente, die mit *n* *ggt* 1 haben.
Der **ÖS** ist dann das *(e,N* Paar.
- **2. Schritt: privaten Schlüssel anlegen:** 

2a. Berechne mit Hilfe des euklidischen Algorithhmus eine Zahl *d* mit *e\*d = 1 (mod phi(N))*
Der **PS** ist dann das *(d,N)* Paar. Dieser muss geheim bleiben und gehört i.d.R. dies dem Empfänger.
- **3. Schritt: Nachricht verschlüsseln:** 

3a. Der Buchstabe *a* wird anhand einer Tabelle von einer Zahl repäsentiert z.B. mit ASCII Tabelle. Nehmen wir an *m* ist der Wert von *a* und Bob möchte diese Nachricht an Alice(Empfängerin) schicken. Die Nachricht *1<m<N* wird mit ihrer Restklassen in Z/N*Z* identifiziert.

3b. Die Nachricht wird durch *s:=m^e (mod N)* verschlüsselt. Bob schickt dieses *s* an Alice.
- **4. Schritt: Nachricht entschlüsseln:**

4a. Die Nachricht wird nach Konstruktion von *d* durch *m=s^d (mod N)* entschlüsselt.

## 3. Euklidischer Algorithmus
Zum [Euklidsichen Algorithmus](https://www.mathematik.uni-kl.de/~gathmann/class/ags-2019/ags-2019.pdf) finden Sie mehr (Seite 76).
Hierbei muss man einmal um den ÖS *e* zu bestimmen eine Zahl, die mit *ph(N)* keinen anderen Teiler als die 1 hat, mithilfe des euklidschen Algorithmus finden. Also, man berechne alle Zahlen, für die es gilt *ggt(e,phi(N)) = 1*. Pseudocode für den Algorithmus lautet:
```    
    Euclid(publicKeyCandidate,phi(N))
    
  an_1 <- phi(N)
  an_2 <- publicKeyCandidate
  qn   <- an_1 / an_2
  rn   <- an_1 % an_2
  gcd  <- an_2
  
  if rn == 0
      return gcd
  else
      while rn != 0
            an_1 <- rn // here rn equals rn_1 because we haven't calculated the current rn yet
            qn   <- an_2 / rn // qn is the current qn, see below rn
            gcd  <- rn // here rn equals rn_1 because we haven't calculated the current rn yet
            rn   <- (an_2 - qn\an_1)
            an_2 <- an_1

  return gcd
``` 


``` 
 EuclidianAlgorithm_2(a, b)

    r = a%b

    while (r != 0)
    {
        a = b
        b = r
        r = a%b
    }
    return b
``` 


Dieser Algorithmus hilft uns auch mit ein paar Extras den PS zu finden. Also, das Inverse *d* zu *e*: *e\*d = 1 (mod phi(N))*. Dieser heisst dann der erweiterter euklidscher Algorithmus:
```    
    Extended_Euclid(publicKey,phi(N))

  an_1 <- phi(N)
  an_2 <- publicKey
  qn   <- an_1 / an_2
  rn   <- an_1 % an_2
  dn <- -qn // e3
  dn_2 <- 1 // e2
  dn_1 <- -qn // e3
  d <- 0
  
  if rn == 0
      return gcd
  else
      while rn != 0
            an_1 <- rn
            qn   <- an_2 
            d <- dn
            dn <- dn_2 - qn*dn_1
            dn_2 <- dn_1
            dn_1 <- dn
            rn   <- (an_2 - qn*\an_1)
            an_2 <- an_1
if d > 0
    return d
else
    return phi(N) + d
``` 

## 4. Beispiel
Sei *p=47* und *q=71*. Somit ist *N=p\*q=3337* und *phi(N) = (p-1)\*(q-1) = 46\*70 = 3320*.
Abhängig von *ph(N)* wird eine zufällige Zahl *e* mit *phi(N)>e>1* gewähl, wobei *ggt(e,phi(N)) = 1* sein muss. Wir wählen z.B. *e=79*

Aus *e* und *phi* können wir nun *d* mit dem euklidischen Algorithmus ausrechnen:

*d\*e = 1 (mod phi(N))* also, euklidsicher Algorithmus liefert uns *79^-1 = 1019 (mod 3220)*

Somit haben wir die beiden Schlüssel:
      **ÖS** : *(e, N) = (79, 3337)*, **PS** : *(d, N) = (1019, 3337)*

Bob kann nun seine Nachricht *m = 668* verschlüsseln und an Alice schicken:

*s  = 688^79 = 1570 (mod 3337)*

Alice kann dann dieses Chiffrat entschlüsseln. Dafür verwendet sie den **PS** und sie bekommt:
*m = 1570^1019 = 668 (mod 3337)*
