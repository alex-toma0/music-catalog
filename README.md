# Descriere proiect
  Un catalog de albume, artisti si melodii care are diferite functionalitati (o functie de search si o functie de likeness).

## Functia search
Sintaxa: obiect.search(tip: "melodie" sau "album", item: "....");
Functie care cauta un album sau o melodie.

## Functia likeness
Sintaxa: obiect.likeness(obiect 2);
Functie care determina daca artistul A seamana cu artistul B dpdv muzical. (folosind genul muzical).
Ex: Pink Floyd (Rock Progresiv) seamana cu Led Zeppelin (Hard Rock) deoarece substringul "Rock" apare in ambele genuri.

