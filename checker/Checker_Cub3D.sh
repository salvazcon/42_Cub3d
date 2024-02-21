#!/bin/bash

make re 2> /dev/null
norminette *.c
echo -e "\033[35m================================================================\033[0m
\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m|\033[0m        ██████╗░░█████╗░░█████╗░░█████╗░   ██╗░██████╗        \033[35m|\033[0m
\033[35m|\033[0m        ██╔══██╗██╔══██╗██╔══██╗██╔══██╗   ██║██╔════╝        \033[35m|\033[0m
\033[35m|\033[0m        ██████╔╝███████║██║░░╚═╝██║░░██║   ██║╚█████╗░        \033[35m|\033[0m
\033[35m|\033[0m        ██╔═══╝░██╔══██║██║░░██╗██║░░██║   ██║░╚═══██╗        \033[35m|\033[0m
\033[35m|\033[0m        ██║░░░░░██║░░██║╚█████╔╝╚█████╔╝   ██║██████╔╝        \033[35m|\033[0m
\033[35m|\033[0m        ╚═╝░░░░░╚═╝░░╚═╝░╚════╝░░╚════╝░   ╚═╝╚═════╝░        \033[35m|\033[0m
"
echo -e "\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m|\033[0m          ██████╗░░█████╗░░█████╗░██╗░░██╗░░░                 \033[35m|\033[0m
\033[35m|\033[0m          ██╔══██╗██╔══██╗██╔══██╗██║░██╔╝░░░                 \033[35m|\033[0m
\033[35m|\033[0m          ██████╦╝███████║██║░░╚═╝█████═╝░░░░                 \033[35m|\033[0m
\033[35m|\033[0m          ██╔══██╗██╔══██║██║░░██╗██╔═██╗░██╗                 \033[35m|\033[0m
\033[35m|\033[0m          ██████╦╝██║░░██║╚█████╔╝██║░╚██╗╚█║                 \033[35m|\033[0m
\033[35m|\033[0m          ╚═════╝░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝░╚╝                 \033[35m|\033[0m
"
echo -e "\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m|\033[0m           ██╗░░░░░███████╗████████╗██╗░██████╗               \033[35m|\033[0m
\033[35m|\033[0m           ██║░░░░░██╔════╝╚══██╔══╝╚█║██╔════╝               \033[35m|\033[0m
\033[35m|\033[0m           ██║░░░░░█████╗░░░░░██║░░░░╚╝╚█████╗░               \033[35m|\033[0m
\033[35m|\033[0m           ██║░░░░░██╔══╝░░░░░██║░░░░░░░╚═══██╗               \033[35m|\033[0m
\033[35m|\033[0m           ███████╗███████╗░░░██║░░░░░░██████╔╝               \033[35m|\033[0m
\033[35m|\033[0m           ╚══════╝╚══════╝░░░╚═╝░░░░░░╚═════╝░               \033[35m|\033[0m
"
echo -e "\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m|\033[0m      ███████╗██╗░░░██╗░█████╗░██╗░░██╗██╗███╗░░██╗░██████╗░  \033[35m|\033[0m
\033[35m|\033[0m      ██╔════╝██║░░░██║██╔══██╗██║░██╔╝██║████╗░██║██╔════╝░  \033[35m|\033[0m
\033[35m|\033[0m      █████╗░░██║░░░██║██║░░╚═╝█████═╝░██║██╔██╗██║██║░░██╗░  \033[35m|\033[0m
\033[35m|\033[0m      ██╔══╝░░██║░░░██║██║░░██╗██╔═██╗░██║██║╚████║██║░░╚██╗  \033[35m|\033[0m
\033[35m|\033[0m      ██║░░░░░╚██████╔╝╚█████╔╝██║░╚██╗██║██║░╚███║╚██████╔╝  \033[35m|\033[0m
\033[35m|\033[0m      ╚═╝░░░░░░╚═════╝░░╚════╝░╚═╝░░╚═╝╚═╝╚═╝░░╚══╝░╚═════╝░  \033[35m|\033[0m
"
echo -e "\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m|\033[0m                ░██████╗░░█████╗░██╗██╗██╗██╗                 \033[35m|\033[0m
\033[35m|\033[0m                ██╔════╝░██╔══██╗██║██║██║██║                 \033[35m|\033[0m
\033[35m|\033[0m                ██║░░██╗░██║░░██║██║██║██║██║                 \033[35m|\033[0m
\033[35m|\033[0m                ██║░░╚██╗██║░░██║╚═╝╚═╝╚═╝╚═╝                 \033[35m|\033[0m
\033[35m|\033[0m                ╚██████╔╝╚█████╔╝██╗██╗██╗██╗                 \033[35m|\033[0m
\033[35m|\033[0m                                                              \033[35m|\033[0m
\033[35m================================================================\033[0m"
NUM=1							#EDIT: Valor numerico que se repite en el nombre.
MAP="maps/map$NUM.cub"			#EDIT: Ruta a los archivos '.cub' con un valor numerico,
ERR=("Archivo Vacio" "Main duplicado" "Brecha en el mapa" "Valor invalido" 
"Datos invalidos" "Datos invalidos" "Datos invalidos" "Datos invalidos" 
"Datos invalidos" "Datos invalidos" "Datos invalidos" "Datos invalidos") #EDIT: Edita el mensaje de error (va por orden).
echo -e "\033[35m----------------------------------------------------------------\033[0m"
echo -e "\033[35m\033[1m	- Le damos mi rey?? (y/n):\033[0m \c"
read AUX
echo -e "\033[35m----------------------------------------------------------------\033[0m\n"
while [ -f "$MAP" ];
do
	if [[ $AUX == 'y' || $AUX == 'Y' ]]; then
		echo -e "\033[1m- A continuacion se testeara este mapa:\033[0m\n"
		echo -e "\033[4m\tFile $MAP \033[0m\n"
		echo -e "\033[33m$(cat $MAP)\033[0m"
		echo -e "\n\033[1m- Dicho mapa tiene este error:\033[0m\n"
		echo -e "\t\033[33m* ${ERR[NUM - 1]}\n\033[0m"
		echo -e "\033[35m----------------------------------------------------------------\033[0m"
		echo -e "\033[35m\033[1m	A continuacion ejecutaremos el programa del Cub3d.\033[0m"
		echo -e "\033[35m----------------------------------------------------------------\033[0m\c"
		read -s
		echo -e "\n\n\033[1m- El error que devuelve el programa es:\033[0m\n"
		./cub3d $MAP 2>&1 | while IFS= read -r line; do printf "\033[33m%s\033[0m\n" "$line"; done
	else
		echo -e "\033[35m----------------------------------------------------------------\033[0m"
		echo -e "\033[35m\033[1m	Eres un pussy bro... Pfff...\033[0m"
		echo -e "\033[35m----------------------------------------------------------------\033[0m"
		echo -e "\033[35m\n----------------------------------------------------------------\033[0m"
		echo -e "\033[35m\033[1m	bueno... te dejo jugar una partida por pena!!! \033[0m"
		echo -e "\033[35m----------------------------------------------------------------\033[0m"
		sleep 3
		./cub3d maps/map.cub
		exit 0
	fi
	((NUM++))
	MAP="maps/map$NUM.cub"
	if [[ -f "$MAP" ]]; then
		echo -e "\033[35m\n----------------------------------------------------------------\033[0m"
		echo -e "\033[35m\033[1m	- Seguimos mi rey?? (y/n):\033[0m\033[0m \c"
		read AUX
		echo -e "\033[35m----------------------------------------------------------------\033[0m\n"
	fi
done
echo -e "\033[35m\n----------------------------------------------------------------\033[0m"
echo -e "\033[35m\033[1m	- Ahora a jugar!!! \033[0m"
echo -e "\033[35m----------------------------------------------------------------\033[0m\n"
./cub3d maps/map.cub