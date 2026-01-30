# Simulator Investitii Financiare (Tema 11)

Proiect realizat pentru materia MAP.

## Autor
**Nume:** Tomescu Andrei
**Grupa:** 3.2 

##  Descrierea Proiectului
Această aplicație este un simulator financiar CLI (Command Line Interface) scris în limbajul **C**. Scopul ei este să ajute utilizatorii să vizualizeze evoluția unei investiții pe termen lung, luând în calcul dobânda compusă, contribuțiile lunare, inflația și volatilitatea pieței.

Proiectul include automatizare prin **Makefile**, containerizare prin **Docker** și un pipeline CI/CD prin **GitHub Actions** care publică automat imaginea pe GitHub Container Registry.

---

## Funcționalități Implementate
1.  **Calcul Dobândă Compusă:** Calcul precis, lună de lună, al evoluției soldului.
2.  **Contribuții Lunare:** Posibilitatea de a adăuga o sumă fixă în fiecare lună la investiție.
3.  **Ajustare la Inflație:** Calcularea valorii reale a banilor la finalul perioadei (puterea de cumpărare).
4.  **Analiză de Scenarii:** Generarea automată a două scenarii alternative (Pesimist: -2% dobândă / Optimist: +2% dobândă).
5.  **Vizualizare Grafică:** Generarea unui grafic ASCII în terminal pentru a vedea creșterea vizual.
6.  **Export Date:** Salvarea detaliată a evoluției anuale într-un fișier `.csv` compatibil cu Excel.

---

## Structura Proiectului
* `src/` - Conține codul sursă (`main.c`, `finance.c`, `utils.c` și headerele).
* `Dockerfile` - Configurația pentru construirea imaginii Docker.
* `Makefile` - Fișier pentru automatizarea compilării locale.
* `.github/workflows/build.yml` - Fluxul de lucru pentru GitHub Actions (Build & Push).

---

## Argumente de Utilizare
Aplicația primește următorii parametri în linia de comandă:

| Argument | Descriere | Exemplu |
| :--- | :--- | :--- |
| `--initial` | Suma inițială investită (RON/EUR) | `1000` |
| `--rate` | Dobânda anuală (ex: 0.05 pentru 5%) | `0.05` |
| `--years` | Durata investiției în ani | `10` |
| `--monthly` | (Opțional) Contribuția lunară adăugată | `100` |
| `--inflation` | (Opțional) Rata inflației pentru ajustare | `0.03` |
| `--scenarios` | (Flag) Activează calculul Pesimist/Optimist | (fără valoare) |
| `--export` | (Opțional) Numele fișierului CSV de ieșire | `raport.csv` |

---

## Rulare
```bash
docker run ghcr.io/vndrei21/simulatorinvestitiifinanciare:main --initial 1000 --rate 0.07 --years 20 --monthly 500 --scenarios

