# guess-language

This little toy project is a small utility that tries to guess the written language of given data file.

It trains two vectors EN/FR by counting the percentage of the ascii occurence in a reference text (Candide by Voltaire).

Then it calculates the distance between calculated vector of a text and the trained ones.

# Usage

```sh
make
```

```
Distance between "EN" and "data/candide-EN.txt" is : 0.00
Distance between "FR" and "data/candide-EN.txt" is : 775.36
Guessed language: EN : data/candide-EN.txt

Distance between "EN" and "data/candide-FR.txt" is : 775.36
Distance between "FR" and "data/candide-FR.txt" is : 0.00
Guessed language: FR : data/candide-FR.txt

Distance between "EN" and "data/artFR01.txt" is : 837.26
Distance between "FR" and "data/artFR01.txt" is : 378.08
Guessed language: FR : data/artFR01.txt

Distance between "EN" and "data/artFR02.txt" is : 820.48
Distance between "FR" and "data/artFR02.txt" is : 283.81
Guessed language: FR : data/artFR02.txt

Distance between "EN" and "data/artFR03.txt" is : 812.15
Distance between "FR" and "data/artFR03.txt" is : 321.57
Guessed language: FR : data/artFR03.txt

Distance between "EN" and "data/artEN01.txt" is : 477.34
Distance between "FR" and "data/artEN01.txt" is : 759.57
Guessed language: EN : data/artEN01.txt

Distance between "EN" and "data/artEN02.txt" is : 405.91
Distance between "FR" and "data/artEN02.txt" is : 690.73
Guessed language: EN : data/artEN02.txt

Distance between "EN" and "data/artEN03.txt" is : 371.13
Distance between "FR" and "data/artEN03.txt" is : 640.54
Guessed language: EN : data/artEN03.txt

Distance between "EN" and "main.c" is : 1216.48
Distance between "FR" and "main.c" is : 1274.60
Guessed language: EN : main.c

Distance between "EN" and "Makefile" is : 1748.15
Distance between "FR" and "Makefile" is : 1843.37
Guessed language: EN : Makefile

Distance between "EN" and ".gitignore" is : 3481.22
Distance between "FR" and ".gitignore" is : 3642.76
Guessed language: EN : .gitignore
```
