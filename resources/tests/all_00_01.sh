#! /usr/bin/env bash

echo -e "\033[0;93m\t\t\t\tTESTING ...\033[0m\n\n"



echo -e "\n-------------------------\t\t\tABANLIN MAP 00\t\t\t-------------------------\n\n" >> trace_abanlin


./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin

./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/mtissari.filler >> trace_abanlin -q;
echo -e "Player is X\n\n" >> trace_abanlin

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin

./filler_vm -f maps/map00 -p1 players/abanlin.filler -p2 players/mtissari.filler >> trace_abanlin -q;
echo -e "Player is X\n\n" >> trace_abanlin

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin


echo -e "\n-------------------------\t\t\tABANLIN MAP 01\t\t\t-------------------------\n\n" >> trace_abanlin

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin

./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 players/mtissari.filler >> trace_abanlin -q;
echo -e "Player is X\n\n" >> trace_abanlin

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin

./filler_vm -f maps/map01 -p1 players/abanlin.filler -p2 players/mtissari.filler >> trace_abanlin -q;
echo -e "Player is X\n\n" >> trace_abanlin

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/abanlin.filler >> trace_abanlin -q;
echo -e "Player is O\n\n" >> trace_abanlin


echo -e "\n-------------------------\t\t\tCHAMPELY MAP 00\t\t\t-------------------------\n\n" >> trace_champely

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely

./filler_vm -f maps/map00 -p1 players/champely.filler -p2 players/mtissari.filler >> trace_champely -q;
echo -e "Player is X\n\n" >> trace_champely

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely

./filler_vm -f maps/map00 -p1 players/champely.filler -p2 players/mtissari.filler >> trace_champely -q;
echo -e "Player is X\n\n" >> trace_champely

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely


echo -e "\n-------------------------\t\t\tCHAMPELY MAP 01\t\t\t-------------------------\n\n" >> trace_champely

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely

./filler_vm -f maps/map01 -p1 players/champely.filler -p2 players/mtissari.filler >> trace_champely -q;
echo -e "Player is X\n\n" >> trace_champely

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely

./filler_vm -f maps/map01 -p1 players/champely.filler -p2 players/mtissari.filler >> trace_champely -q;
echo -e "Player is X\n\n" >> trace_champely

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/champely.filler >> trace_champely -q;
echo -e "Player is O\n\n" >> trace_champely


echo -e "\n-------------------------\t\t\tHCAO MAP 00\t\t\t-------------------------\n\n" >> trace_hcao

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao

./filler_vm -f maps/map00 -p1 players/hcao.filler -p2 players/mtissari.filler >> trace_hcao -q;
echo -e "Player is X\n\n" >> trace_hcao

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao

./filler_vm -f maps/map00 -p1 players/hcao.filler -p2 players/mtissari.filler >> trace_hcao -q;
echo -e "Player is X\n\n" >> trace_hcao

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao


echo -e "\n-------------------------\t\t\tHCAO MAP 01\t\t\t-------------------------\n\n" >> trace_hcao

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao

./filler_vm -f maps/map01 -p1 players/hcao.filler -p2 players/mtissari.filler >> trace_hcao -q;
echo -e "Player is X\n\n" >> trace_hcao

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao

./filler_vm -f maps/map01 -p1 players/hcao.filler -p2 players/mtissari.filler >> trace_hcao -q;
echo -e "Player is X\n\n" >> trace_hcao

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/hcao.filler >> trace_hcao -q;
echo -e "Player is O\n\n" >> trace_hcao



echo -e "\033[0;93m\t\t\t\t        ...\033[0m\n\n"


echo -e "\n-------------------------\t\t\tSUPERJEANNOT MAP 00\t\t\t-------------------------\n\n" >> trace_superjeannot

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot

./filler_vm -f maps/map00 -p1 players/superjeannot.filler -p2 players/mtissari.filler >> trace_superjeannot -q;
echo -e "Player is X\n\n" >> trace_superjeannot

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot

./filler_vm -f maps/map00 -p1 players/superjeannot.filler -p2 players/mtissari.filler >> trace_superjeannot -q;
echo -e "Player is X\n\n" >> trace_superjeannot

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot


echo -e "\n-------------------------\t\t\tSUPERJEANNOT MAP 01\t\t\t-------------------------\n\n" >> trace_superjeannot

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot

./filler_vm -f maps/map01 -p1 players/superjeannot.filler -p2 players/mtissari.filler >> trace_superjeannot -q;
echo -e "Player is X\n\n" >> trace_superjeannot

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot

./filler_vm -f maps/map01 -p1 players/superjeannot.filler -p2 players/mtissari.filler >> trace_superjeannot -q;
echo -e "Player is X\n\n" >> trace_superjeannot

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/superjeannot.filler >> trace_superjeannot -q;
echo -e "Player is O\n\n" >> trace_superjeannot


echo -e "\n-------------------------\t\t\tCARLI MAP 00\t\t\t-------------------------\n\n" >> trace_carli

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli

./filler_vm -f maps/map00 -p1 players/carli.filler -p2 players/mtissari.filler >> trace_carli -q;
echo -e "Player is X\n\n" >> trace_carli

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli

./filler_vm -f maps/map00 -p1 players/carli.filler -p2 players/mtissari.filler >> trace_carli -q;
echo -e "Player is X\n\n" >> trace_carli

./filler_vm -f maps/map00 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli


echo -e "\n-------------------------\t\t\tCARLI MAP 01\t\t\t-------------------------\n\n" >> trace_carli

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli

./filler_vm -f maps/map01 -p1 players/carli.filler -p2 players/mtissari.filler >> trace_carli -q;
echo -e "Player is X\n\n" >> trace_carli

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli

./filler_vm -f maps/map01 -p1 players/carli.filler -p2 players/mtissari.filler >> trace_carli -q;
echo -e "Player is X\n\n" >> trace_carli

./filler_vm -f maps/map01 -p1 players/mtissari.filler -p2 players/carli.filler >> trace_carli -q;
echo -e "Player is O\n\n" >> trace_carli



echo -e "\033[0;32m\t\t\t\tTESTS FOR MAPS 00 AND 01 DONE! \033[0m\n\n"
