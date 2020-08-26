# cs240-team-project

Jake Mohrmann (jmohrma1), William Huebner (whuebne1), and Joseph DeFlorio (jdeflor1)

This project aims to analyze the differences in time complexity of various password cracking algorithms. In this case, the three different algorithms implemented are brute force cracking, dictionary attacks, and random cracking.

### Brute Force Cracking

The brute force method of password cracking iterates through all possibilities of a string until finding the correct password.

### Dictionary Cracking

In order to do dictionary cracking, you need to put a password\_dictionary.txt file in the same directory as the executable.

This should be a txt file with a single entry on each line.

For the one used for the testing of this project, you can download it [here](https://www.kaggle.com/wjburns/common-password-list-rockyoutxt). It is 134 MB uncompressed, and contains around 14 million passwords.

For the purpose of comparison to brute force attacks, all of the single character passwords were removed.

In order to achieve maximum performance from dictionary attacks, the dictionary file should be sorted by line length, in ascending order. If this is the case, the --dict\_sorted option should be provided to the executable.

### Random Cracking

The random cracking method picks random chars (consisting of capital letters, lowercase letters, or digits) to create a possible password of random length, less than or equal to the required length.

## Testing Results

The random passwords were generated using a small Python script. The common passwords were obtained by trimming down the list provided [here](https://github.com/DavidWittman/wpxmlrpcbrute/blob/master/wordlists/1000-most-common-passwords.txt).

| Random Passwords (max 5 chars) | Brute Force (ms) | Dictionary    | Random (ms) |
|--------------------------------|------------------|---------------|-------------|
| pkD                            | 13.0955          | Did Not Crack | 29.6252     |
| HTx                            | 26.9518          | Did Not Crack | 248.871     |
| 18N                            | 42.7119          | Did Not Crack | 77.806      |
| 2l9                            | 42.8752          | Did Not Crack | 226.398     |
| k88                            | 9.4251           | Did Not Crack | 747.24      |
| EmL                            | 24.1397          | Did Not Crack | 125.842     |
| gN7                            | 6.0105           | Did Not Crack | 943.017     |
| cCC                            | 2.6927           | Did Not Crack | 382.503     |
| Tt9                            | 36.3523          | Did Not Crack | 16.5512     |
| rWks                           | 917.452          | Did Not Crack | 8508.15     |
| b1fE                           | 141.61           | Did Not Crack | 8472.21     |
| Bw39                           | 1412.05          | Did Not Crack | 9961.59     |
| 7vi5                           | 2966.77          | Did Not Crack | 12351.60    |
| Ug1Y                           | 2314.83          | Did Not Crack | 34835.70    |
| HC3U                           | 1697.87          | Did Not Crack | 29263.72    |
| AVUA                           | 1364.99          | Did Not Crack | 1656.62     |
| oB9V                           | 755.809          | Did Not Crack | 19542.13    |
| YjCx                           | 2510.59          | Did Not Crack | 26136.74    |
| YhzZ                           | 2512.32          | Did Not Crack | 36712.31    |
| SrWPc                          | 137371           | Did Not Crack | 94323.8     |
| 5IuZA                          | 178383           | Did Not Crack | 532076      |
| HeCAy                          | 118694           | Did Not Crack | 1.92E+06    |
| ATJA7                          | 103939           | Did Not Crack | 248933      |
| KAQgh                          | 133284           | Did Not Crack | 99245.7     |
| SS6yH                          | 148377           | Did Not Crack | 2.05E+06    |
| TEyqR                          | 189344           | Did Not Crack | 4.03E+06    |
| Pja76                          | 159482           | Did Not Crack | 513011      |
| aCbaA                          | 144931           | Did Not Crack | 192003      |
| NbTUb                          | 163221           | Did Not Crack | 402934      |

| Common Passwords (max 5 chars) | Brute Force (ms) | Dictionary (ms) | Random (ms) |
|--------------------------------|------------------|-----------------|-------------|
| pass                           | 778.983          | 0.0969          | 2902.65     |
| love                           | 598.939          | 0.0894          | 7254.99     |
| test                           | 974.481          | 0.111           | 23786.6     |
| sexy                           | 932.84           | 0.0911          | 28443.5     |
| golf                           | 354.489          | 0.1003          | 18095.6     |
| mike                           | 668.989          | 0.0901          | 2139.39     |
| bear                           | 101.645          | 0.1055          | 43174.5     |
| jack                           | 497.938          | 0.1225          | 1938.7      |
| razz                           | 916.608          | 0.2132          | 4408.48     |
| asdf                           | 64.8435          | 0.0913          | 38935.1     |
| john                           | 512.635          | 0.0907          | 27908.1     |
| blue                           | 111.019          | 0.09            | 1360.08     |
| alex                           | 59.6046          | 0.0853          | 9012.41     |
| black                          | 145045           | 0.6503          | 1392834     |
| david                          | 145905           | 0.6471          | 293013      |
| lucky                          | 145769           | 0.618           | 930283      |
| jason                          | 149024           | 0.6157          | 933203      |
| bubba                          | 145157           | 0.6296          | 1039422     |
| happy                          | 146023           | 0.6381          | 670492      |
| qwert                          | 150001           | 0.674           | 289301      |
| apple                          | 144856           | 0.6691          | 91104.3     |
| tiger                          | 150163           | 0.6836          | 830229      |
| magic                          | 145524           | 0.6716          | 394002      |
| girls                          | 146753           | 0.6593          | 203912      |
| hello                          | 148569           | 0.6586          | 1203933     |
| money                          | 145873           | 0.6184          | 90234.5     |
| angel                          | 143648           | 0.635           | 766429      |
| enter                          | 146108           | 0.6576          | 920281      |
| chris                          | 145105           | 0.6446          | 3088729     |

| Average Time In ms    | Brute Force | Dictionary   | Random      |
|-----------------------|-------------|--------------|-------------|
| Random (3 Characters) | 22.69496667 | infinity     | 310.8726    |
| Random (4 Characters) | 1659.4291   | infinity     | 18744.077   |
| Random (5 Characters) | 147702.6    | infinity     | 1007632.05  |
| Common (4 Characters) | 505.6164692 | 0.1059461538 | 16104.62308 |
| Common (5 Characters) | 138113.125  | 0.6481625    | 821087.6125 |
