#!/bin/bash

function print_ascii_header {
  echo "      ___           ___           ___                    ___           ___           ___           ___           ___           ___           ___     "
  echo "     /\__\         /\  \         /\  \                  /\  \         /\  \         /\  \         /\  \         /\  \         /\  \         /\  \    "
  echo "    /::|  |       /::\  \       /::\  \                /::\  \       /::\  \       /::\  \       /::\  \        \:\  \       /::\  \       /::\  \   "
  echo "   /:|:|  |      /:/\:\  \     /:/\:\  \              /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/\:\  \        \:\  \     /:/\:\  \     /:/\:\  \  "
  echo "  /:/|:|__|__   /::\~\:\  \   /::\~\:\  \            /:/  \:\  \   /::\~\:\  \   /::\~\:\  \   /::\~\:\  \       /::\  \   /:/  \:\  \   /::\~\:\  \ "
  echo " /:/ |::::\__\ /:/\:\ \:\__\ /:/\:\ \:\__\          /:/__/ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\     /:/\:\__\ /:/__/ \:\__\ /:/\:\ \:\__\\"
  echo " \/__/~~/:/  / \/__\:\/:/  / \/__\:\/:/  /          \:\  \  \/__/ \/_|::\/:/  / \:\~\:\ \/__/ \/__\:\/:/  /    /:/  \/__/ \:\  \ /:/  / \/_|::\/:/  /"
  echo "       /:/  /       \::/  /       \::/  /            \:\  \          |:|::/  /   \:\ \:\__\        \::/  /    /:/  /       \:\  /:/  /     |:|::/  / "
  echo "      /:/  /        /:/  /         \/__/              \:\  \         |:|\/__/     \:\ \/__/        /:/  /     \/__/         \:\/:/  /      |:|\/__/  "
  echo "     /:/  /        /:/  /                              \:\__\        |:|  |        \:\__\         /:/  /                     \::/  /       |:|  |   "
  echo "     \/__/         \/__/                                \/__/         \|__|         \/__/         \/__/                       \/__/         \|__|   "
  echo "                                                                                                                                         by edbernar"
  echo ""
  echo ""
  echo ""
}


# Afficher l'en-tête ASCII
print_ascii_header

# Fonction pour générer un nombre aléatoire dans une plage spécifiée
function random_number {
  local min=$1
  local max=$2
  echo $(( min + RANDOM % (max - min + 1) ))
}

n=10
if [ ! -d "./BSQ/map" ]; then
  mkdir ./BSQ/map
fi

for ((i = 0; i < n; i++))
do
  taille1=$(random_number 1 1000)
  taille2=$(random_number 1 1000)
  taille3=$(random_number 1 10)
  nom="Map_${i}"
  perl gen.pl $taille1 $taille2 $taille3 > "./BSQ/map/${nom}"
  echo "Carte générée : ${i} de taille ${taille1}x${taille2} densite ${taille3}"
done
