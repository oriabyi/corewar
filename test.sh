#!/bin/bash
bot=$1
cycle=$2
./corewar -dump $cycle $bot  > /tmp/my.txt && ./def_vm_champs/corewar -d $cycle $bot >  /tmp/st.txt && diff /tmp/my.txt /tmp/st.txt
#./corewar -d $cycle ./def_vm_champs/champs/Gagnant.cor > /tmp/my.txt && ./def_vm_champs/corewar -d $cycle ./def_vm_champs/champs/Gagnant.cor  > /tmp/st.txt && diff /tmp/my.txt /tmp/st.txt
#./corewar -d $cycle ./def_vm_champs/champs/jumper.cor > /tmp/my.txt && ./def_vm_champs/corewar -d $cycle ./def_vm_champs/champs/jumper.cor  > /tmp/st.txt && diff /tmp/my.txt /tmp/st.txt
#./corewar -d $cycle ./def_vm_champs/champs/Gagnant.cor ./def_vm_champs/champs/Octobre_Rouge_V4.2.cor ./def_vm_champs/champs/jumper.cor ./def_vm_champs/champs/mortel.cor > /tmp/my && ./def_vm_champs/corewar -d $cycle ./def_vm_champs/champs/Gagnant.cor ./def_vm_champs/champs/Octobre_Rouge_V4.2.cor ./def_vm_champs/champs/jumper.cor ./def_vm_champs/champs/mortel.cor > /tmp/st && diff /tmp/my /tmp/st
