# MKS
MPC-MKS 22/23

**NUCLEOF030R8
cv01 - Základní funkce (noHAL, prirazeni pinu etc.); 
cv02 - SysTick, GPIO manualne, manualni interrupt; 
cv03 - manualni vypis na 7-seg pres sct knihovnu;
cv03B - 7-seg s HAL, sct primitivni NEPOUZIVAT;
cv04 - ADC a bargraf - rotacni enkoder, prepinani displeje na teplotu a napeti pomoci tlacitek, FSM s TIMEOUT, NEBLOKOVACI;
cv05 - UART s DMA, EEPROM pres I2C - UART buffer + zpracovani zpravy, strcasecmp a printf strom, HAL zapis pinu, SPRAVNE NAMAPOVANE PINY A NASTAVENI: EEPROM UART;
cv06 - Teplotni cidla digital analog - knihovna 1WIRE a SCT, vycet z digitalu pres 1wire, analog NTC z lookup tabulky, FSM SPATNEJ s flagama (static se prece neprepise);
cv07 - FreeRTOS - LIS2DW12 knihovna pro akcelerometr, upraveny UART kompatibilni s RTOS, kod se pise dolu do Tasku hlavni while je prazdny;
**NUCLEOF429ZI
cv10 - Maticová klávesnice, kódový zámek - cteni klavesnice pres SWV, v navodu je jak naportit na F030R8;
cv11 - USB mys HID - hraní se smajlíkem;
cv12 - Ethernet, TCP klient a server - pripojeni desky do site, zalozeni serveru, klient co se pripoji na server a vypise terminal;
